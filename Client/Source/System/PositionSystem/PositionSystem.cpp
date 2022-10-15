/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** PositionSystem
*/

#include "PositionSystem.hpp"

#include "Constant.hpp"

PositionSystem::PositionSystem()
{
}

PositionSystem::~PositionSystem()
{
}

void PositionSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cposition_t> &position, Sparse_array<component::cserverid_t> &serverIds)
{
    while (!network[FORBIDDEN_IDS::NETWORK]->updatePositionQueue.empty()) {
        packet_position &positionPacket = network[FORBIDDEN_IDS::NETWORK]->updatePositionQueue.front();
        std::cout << "the new postion id is "<< positionPacket.id << " at pos "<< positionPacket.x << " , "<< positionPacket.y << std::endl;
        for (std::size_t index = 0; index != serverIds.size(); index++) {
            if (serverIds[index]->id == positionPacket.id) {
                std::cout << "is good at id" << index << "("<< serverIds[index]->id<<", "<<  positionPacket.id <<")"<< std::endl;
                position[index]->x = positionPacket.x;
                position[index]->y = positionPacket.y;
            }
        }
        network[FORBIDDEN_IDS::NETWORK]->updatePositionQueue.pop();
    }
}
