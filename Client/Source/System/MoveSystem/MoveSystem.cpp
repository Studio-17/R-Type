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
#include "Constant.hpp"

MoveSystem::MoveSystem()
{
}

void MoveSystem::operator()(Registry &registry, Sparse_array<component::cdirection_t> &direction, Sparse_array<component::cposition_t> &position, Sparse_array<component::cvelocity_t> &velocity, Sparse_array<component::ctimer_t> &timer)
{
    if ((std::chrono::steady_clock::now() - timer[FORBIDDEN_IDS::NETWORK].value().deltaTime) > (std::chrono::nanoseconds)100000000) {
        timer[FORBIDDEN_IDS::NETWORK].value().deltaTime = std::chrono::steady_clock::now();
        // std::cout << "Chorno > 5000"  << std::endl;
    }
    else
        return;
    for (unsigned short index = 1; index < position.size() && index < velocity.size() && index < velocity.size() && direction.size(); index++) {
        if (position[index] && velocity[index] && direction[index]) {
            // if (killed[index].value().isDead)
            //     continue;
            // if (position[index].value().x > 1920)
            //         killed[index].value().isDead = true;
            position[index].value().x += (velocity[index].value().velocity * direction[index].value().x);
            position[index].value().y += (velocity[index].value().velocity * direction[index].value().y);
        }
    }
    // update la position
    // position = velocity * direction

    // toSendNetworkQueue to all clients
}
