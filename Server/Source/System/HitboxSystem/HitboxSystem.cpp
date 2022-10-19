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

void System::HitboxSystem::HitboxSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network_queues, Sparse_array<component::ctype_t> &types, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rects, Sparse_array<component::ckilled_t> &killed)
{
    for (std::size_t i = 0; i < types.size(); i++) {
        auto &firsttype = types[i];
        auto &firstpos = positions[i];
        auto &firstrect = rects[i];
        // auto &queue = network_queues[i];

        if (firsttype->type != ENEMY || killed[i]->isDead)
            continue;
        for (std::size_t x = 0; x < types.size(); x++) {
            if (x == i)
                continue;
            auto &secondtype = types[x];
            auto &secondrect = rects[x];
            auto &secondpos = positions[x];
            if (secondtype->type == ENEMY || killed[x]->isDead)
                continue;
            if (CheckCollision(firstrect, secondrect, firstpos, secondpos)) {
                if (secondtype->type == PLAYER || secondtype->type == BULLET) {
                    // std::cout << "[SERVER] collision between " <<firsttype->type<< " and "<< secondtype->type<< std::endl;
                    killed[i]->isDead = true;
                    killed[x]->isDead = true;
                    registry.kill_entity(registry.entity_from_index(i));
                    registry.kill_entity(registry.entity_from_index(x));
                    network_queues[0]->toSendNetworkQueue.push(serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, {registry.entity_from_index(i)}));
                    network_queues[0]->toSendNetworkQueue.push(serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, {registry.entity_from_index(x)}));
                }
            }
        }
    }
}