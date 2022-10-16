/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** HitboxSystem
*/

#include "HitboxSystem.hpp"

systemNamespace::HitboxSystem::HitboxSystem()
{
}

bool systemNamespace::HitboxSystem::CheckCollision(std::optional<component::crect_t> &rec1, std::optional<component::crect_t> &rec2, std::optional<component::cposition_t> &pos1, std::optional<component::cposition_t> &pos2)
{
    bool collision = false;

    if ((pos1->x < (pos2->x + rec2->width) && (pos1->x + rec1->width) > pos2->x) && (pos1->y < (pos2->y + rec2->height) && (pos1->y + rec1->height) > pos2->y))
        collision = true;

    return collision;
}

void systemNamespace::HitboxSystem::HitboxSystem::operator()(Registry &registry, Sparse_array<component::ctype_t> &types, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rects, Sparse_array<component::cnetwork_queue_t> &network_queues)
{
    for (std::size_t i = 0; i < types.size(); i++) {
        auto &firsttype = types[i];
        auto &firstpos = positions[i];
        auto &firstrect = rects[i];
        // auto &queue = network_queues[i];
        if (firsttype->type == ENEMY) {
            for (std::size_t x = 0; x < types.size(); x++) {
                auto &secondtype = types[i];
                auto &secondrect = rects[i];
                auto &secondpos = positions[i];
                if (secondtype->type != ENEMY) {
                    if (CheckCollision(firstrect, secondrect, firstpos, secondpos)) {
                        if (secondtype->type == PLAYER || secondtype->type == BULLET) {
                            registry.kill_entity(registry.entity_from_index(i));
                            registry.kill_entity(registry.entity_from_index(x));
                        }
                    }
                }
            }
        }

    }
}