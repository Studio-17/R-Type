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

void MoveSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cdirection_t> &direction, Sparse_array<component::cposition_t> &position, Sparse_array<component::cvelocity_t> &velocity, Sparse_array<component::ctimer_t> &timer)
{
    if ((std::chrono::steady_clock::now() - timer[FORBIDDEN_IDS::NETWORK].value().deltaTime) > (std::chrono::nanoseconds)100000000)
        timer[FORBIDDEN_IDS::NETWORK].value().deltaTime = std::chrono::steady_clock::now();
    else
        return;
    for (unsigned short index = 1; index < position.size() && index < velocity.size() && index < velocity.size() && direction.size(); index++) {
        if (position[index] && velocity[index] && direction[index]) {
            // if (killed[index].value().isDead)
            //     continue;
            // if (position[index].value().x > 1920)
            //         killed[index].value().isDead = true;

            // std::cout << "x = " << position[9].value().x << ", y = " << position[9].value().y << std::endl;
            position[index]->x += (velocity[index]->velocity * direction[index]->x);
            position[index]->y += (velocity[index]->velocity * direction[index]->y);
            // std::cout << "x = " << position[9].value().x << ", y = " << position[9].value().y << std::endl;
        }
    }
}
