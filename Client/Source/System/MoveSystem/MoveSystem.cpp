/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#include "MoveSystem.hpp"
#include "Move.hpp"
#include "Serialization.hpp"
#include "Position.hpp"

MoveSystem::MoveSystem()
{
}

void MoveSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cdirection_t> &direction,Sparse_array<component::cposition_t> &position,Sparse_array<component::cvelocity_t> &velocity)
{
    for (unsigned short index = 1; index < position.size() && index < velocity.size() && index < velocity.size(); index++) {
        position[index]->x += (velocity[index]->velocity * direction[index]->x);
        if (position[index]->x > 800)
            position[index]->x = 0;
        position[index]->y += (velocity[index]->velocity * direction[index]->y);
    }
    // update la position
    // position = velocity * direction

    // toSendNetworkQueue to all clients
}
