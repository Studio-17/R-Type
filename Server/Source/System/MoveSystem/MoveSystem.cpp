/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#include "MoveSystem.hpp"

MoveSystem::MoveSystem()
{
}

void MoveSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cdirection_t> &direction,Sparse_array<component::cposition_t> &position,Sparse_array<component::cvelocity_t> &velocity)
{
    // update la position
    // position = velocity * direction

    // toSendNetworkQueue to all clients
}
