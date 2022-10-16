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

void systemNamespace::HitboxSystem::HitboxSystem::operator()(Registry &registry, Sparse_array<component::ctype_t> &types, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rects, Sparse_array<component::cnetwork_queue_t> &network_queues, Sparse_array<component::cserverid_t> &server_ids)
{
    for (std::size_t i = 0; i < types.size() && positions.size() && i < rects.size() && network_queues.size() && server_ids.size(); i++) {
        auto &t = types[i];
        auto pos = positions[i];
        auto &rect = rects[i];
        auto &queue = network_queues[i];
        auto &id = server_ids[i];
    }
}