/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** PositionSystem
*/

#include "PositionSystem.hpp"
#include "Constant.hpp"

/* Packet */
#include "Position.hpp"

System::PositionSystem::PositionSystem()
{
}

void System::PositionSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cposition_t> &position, Sparse_array<component::cserverid_t> &serverIds)
{
    while (!network[FORBIDDEN_IDS::NETWORK].value().updatePositionQueue.empty()) {
        packet_position &positionPacket = network[FORBIDDEN_IDS::NETWORK].value().updatePositionQueue.front();

        for (std::size_t index = 0; index != serverIds.size() && index != position.size(); index++) {
            if (serverIds[index] && position[index]) {
                if (serverIds[index].value().id == positionPacket.id) {
                    position[index].value().x = positionPacket.x;
                    position[index].value().y = positionPacket.y;
                }
            }
        }
        network[FORBIDDEN_IDS::NETWORK].value().updatePositionQueue.pop();
    }
}
