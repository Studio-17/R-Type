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
    // Check si la queue est pas empty et modifier les positions de l'entité choisie
    if (!network[FORBIDDEN_IDS::NETWORK]->updatePositionQueue.empty()) {
        packet_position positionPacket = network[FORBIDDEN_IDS::NETWORK]->updatePositionQueue.front();

        for (auto &serverId : serverIds) {
            if (serverId->id == positionPacket.id) {
                // Attention c'est pas ca qu'il faut faire ici
                position[serverId->id]->x = positionPacket.x;
                position[serverId->id]->y = positionPacket.y;
                // add index of sprite to update
            }
        }

        network[FORBIDDEN_IDS::NETWORK]->updatePositionQueue.pop();
    }
}
