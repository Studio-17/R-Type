/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** HitboxSystem
*/

/* Systems */
#include "HitboxSystem.hpp"

/* Serialization */
#include "Serialization.hpp"

/* Constant */
#include "Constant.hpp"
#include "UpdateEntityInfos.hpp"

/* Packets */
#include "KillEntity.hpp"

/* Packets */
#include "KillEntity.hpp"

System::HitboxSystem::HitboxSystem()
{
}

void System::HitboxSystem::doHealthCheck(Registry &registry, component::cnetwork_queue_t &netQueue, component::chealth_t &health1, component::chealth_t &health2, component::clobby_id_t &lobbyId, int i, int x)
{
    health1.health--;
    health2.health--;

    netQueue.toSendNetworkQueue.push({lobbyId.id, serialize_header::serializeHeader<packet_update_entity_health>(NETWORK_SERVER_TO_CLIENT::UPDATE_ENTITY_HEALTH, {static_cast<int>(i), health1.health})});
    netQueue.toSendNetworkQueue.push({lobbyId.id, serialize_header::serializeHeader<packet_update_entity_health>(NETWORK_SERVER_TO_CLIENT::UPDATE_ENTITY_HEALTH, {static_cast<int>(x), health2.health})});

    if (health1.health == 0) {
        netQueue.toSendNetworkQueue.push({lobbyId.id, serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, {static_cast<int>(i)})});
        registry.kill_entity(registry.entity_from_index(i));
    }
    if (health2.health == 0) {
        netQueue.toSendNetworkQueue.push({lobbyId.id, serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, {static_cast<int>(x)})});
        registry.kill_entity(registry.entity_from_index(x));
    }
}

void System::HitboxSystem::doScoreUpdate(component::cnetwork_queue_t &netQueue, component::clobby_id_t &lobbyId, Sparse_array<component::cscore_t> &score, Sparse_array<component::ctype_t> &type, Sparse_array<component::cowner_id_t> &ownerId, int x)
{
    if (type[x].value().type == ENTITY_TYPE::BULLET) {
        std::cout << "Score updte !" << score[ownerId[x].value().id].value().score << std::endl;
        score[ownerId[x].value().id].value().score += 10;
        netQueue.toSendNetworkQueue.push({lobbyId.id, serialize_header::serializeHeader<packet_update_entity_score>(NETWORK_SERVER_TO_CLIENT::UPDATE_ENTITY_SCORE, {static_cast<int>(x), score[ownerId[x].value().id].value().score})});
    }
}


bool System::HitboxSystem::CheckCollision(component::crect_t const &rec1, component::crect_t const &rec2, component::cposition_t const &pos1, component::cposition_t const &pos2)
{
    if (pos1.y < (pos2.y + rec2.height) && (pos1.y + rec1.height) > pos2.y)
        if ((pos1.x < (pos2.x + rec2.width) && (pos1.x + rec1.width) > pos2.x))
            return true;
    return false;
}

void System::HitboxSystem::HitboxSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network_queues, Sparse_array<component::ctype_t> &types, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rects, Sparse_array<component::chealth_t> &health, Sparse_array<component::clobby_id_t> &lobbyId, Sparse_array<component::cscore_t> &score, Sparse_array<component::ctype_t> &type, Sparse_array<component::cowner_id_t> &ownerId) {
    if (network_queues[FORBIDDEN_IDS::NETWORK]) {
        for (std::size_t i = 0; i < types.size() && i < positions.size() && i < rects.size() && i < lobbyId.size(); i++) {
            if (types[i] && positions[i] && rects[i] && lobbyId[i]) {
                auto &firsttype = types[i];
                auto &firstpos = positions[i];
                auto &firstrect = rects[i];

                if (firsttype.value().type != ENEMY && firsttype.value().type != ENEMY2 && firsttype.value().type != ENEMY3)
                    continue;
                for (std::size_t x = 0; x < types.size() && x < positions.size() && x < rects.size() && x < lobbyId.size(); x++) {
                    if (types[x] && positions[x] && rects[x] && lobbyId[x]) {
                        if (x == i)
                            continue;
                        if (lobbyId[i].value().id != lobbyId[x].value().id)
                            continue;
                        auto &secondtype = types[x];
                        auto &secondpos = positions[x];
                        auto &secondrect = rects[x];

                        if (secondtype.value().type == ENEMY || secondtype.value().type == ENEMY2 || secondtype.value().type == ENEMY3)
                            continue;
                        if (CheckCollision(firstrect.value(), secondrect.value(), firstpos.value(), secondpos.value())) {
                            if (secondtype.value().type == PLAYER || secondtype.value().type == BULLET) {
                                // std::cout << "hit box system lobby id entity to kill " << lobbyId[i].value().id << std::endl;
                                // network_queues[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({lobbyId[i].value().id, serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, {static_cast<int>(i)})});
                                // network_queues[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({lobbyId[i].value().id, serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, {static_cast<int>(x)})});
                                // registry.kill_entity(registry.entity_from_index(i));
                                // registry.kill_entity(registry.entity_from_index(x));
                                doScoreUpdate(network_queues[FORBIDDEN_IDS::NETWORK].value(), lobbyId[i].value(), score, type, ownerId, x);
                                doHealthCheck(registry, network_queues[FORBIDDEN_IDS::NETWORK].value(), health[i].value(), health[x].value(), lobbyId[i].value(), i, x);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}