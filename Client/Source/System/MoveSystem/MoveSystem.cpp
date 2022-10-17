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

void MoveSystem::operator()(Registry &registry, Sparse_array<component::cdirection_t> &direction,Sparse_array<component::cposition_t> &position,Sparse_array<component::cvelocity_t> &velocity, Sparse_array<component::ckilled_t> &killed)
{
    for (unsigned short index = 1; index < position.size() && index < velocity.size() && index < velocity.size(); index++) {
        if (killed[index]->isDead)
            continue;
        position[index]->x += (velocity[index]->velocity * direction[index]->x);
        position[index]->y += (velocity[index]->velocity * direction[index]->y);
    }
    // update la position
    // position = velocity * direction

    // toSendNetworkQueue to all clients
}
