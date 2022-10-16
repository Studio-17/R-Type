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
    for (unsigned short index = 0; index < position.size(); index++) {
        position[index]->x += (velocity[index]->velocity * direction[index]->x);
        // if (position[index]->x > 1920)
        //     position[index]->x = 0;
        position[index]->y += (velocity[index]->velocity * direction[index]->y);
            // std::cout << "entity no:" << index << " at pos: " << position[index]->x << " , " << position[index]->y << std::endl;

            // netqueue[0]->toSendNetworkQueue.push(serialize_header::serializeHeader<packet_position>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::POSITION, packet_position{index, position[index]->x, position[index]->y, 1}));
    }
    // update la position
    // position = velocity * direction

    // toSendNetworkQueue to all clients
}
