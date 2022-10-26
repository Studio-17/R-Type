/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** HitboxSystem
*/

#include "HitboxSystem.hpp"
#include "KillEntity.hpp"
#include "Serialization.hpp"

System::HitboxSystem::HitboxSystem()
{
}

bool System::HitboxSystem::CheckCollision(std::optional<component::crect_t> &rec1, std::optional<component::crect_t> &rec2, std::optional<component::cposition_t> &pos1, std::optional<component::cposition_t> &pos2)
{
    if (pos1->y < (pos2->y + rec2->height) && (pos1->y + rec1->height) > pos2->y) {
        // std::cout << "[Server] same y" << std::endl;
        if ((pos1->x < (pos2->x + rec2->width) && (pos1->x + rec1->width) > pos2->x)) {
            // std::cout << "first "<< pos1->x << " second "<<pos2->x << std::endl;
            // std::cout << "rect "<< rec1->width<< " second " << rec2->width << std::endl;
            // std::cout << "[Server] same x" << std::endl;
            return true;
        }
    }
    return false;
}

void System::HitboxSystem::HitboxSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network_queues, Sparse_array<component::ctype_t> &types, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rects)
{
    if (network_queues[0]) {
        for (int i = 0; i < types.size() && i < positions.size() && i < rects.size(); i++) {
            if (types[i] && positions[i] && rects[i]) {
                auto &firsttype = types[i];
                auto &firstpos = positions[i];
                auto &firstrect = rects[i];

                if (firsttype.value().type != ENEMY)
                    continue;
                for (int x = 0; x < types.size() && x < positions.size() && x < rects.size(); x++) {
                    if (types[x] && positions[x] && rects[x]) {
                        if (x == i)
                            continue;
                        auto &secondtype = types[x];
                        auto &secondpos = positions[x];
                        auto &secondrect = rects[x];

                        if (secondtype.value().type == ENEMY)
                            continue;
                        if (CheckCollision(firstrect, secondrect, firstpos, secondpos)) {
                            if (secondtype.value().type == PLAYER || secondtype.value().type == BULLET) {
                                network_queues[0].value().toSendNetworkQueue.push(serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, {i}));
                                network_queues[0].value().toSendNetworkQueue.push(serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, {x}));
                                registry.kill_entity(registry.entity_from_index(i));
                                registry.kill_entity(registry.entity_from_index(x));
                            }
                        }
                    }
                }
            }
        }
    }
}