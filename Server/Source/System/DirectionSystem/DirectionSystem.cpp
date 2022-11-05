/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** DirectionSystem
*/

#include <unordered_map>

#include "Registry.hpp"

#include "Component/CDirection.hpp"
#include "Component/CPosition.hpp"
#include "Component/CVelocity.hpp"

#include "DirectionSystem.hpp"
#include "Move.hpp"
#include "Serialization.hpp"
#include "Position.hpp"

DirectionSystem::DirectionSystem()
{
}

void DirectionSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, [[ maybe_unused ]] Sparse_array<component::cdirection_t> &direction, Sparse_array<component::cposition_t> &position, Sparse_array<component::cvelocity_t> &velocity)
{
    if (!netqueue[0].value().moveQueue.empty()) {
        std::pair<int, packet_move> packet = netqueue[0].value().moveQueue.front();
        // std::cout << "[SERVER] DirectionSystem id : " << packet.second.playerId << std::endl;
        netqueue[0].value().moveQueue.pop();
        if (velocity[packet.second.playerId] && position[packet.second.playerId]) {
            // std::cout << "[SERVER] do movement for id : " << packet.second.playerId << std::endl;
            std::unordered_map<uint16_t, int> movement {{0, 0}, {1, 1}, {2, -1}};
            int resultY = velocity[packet.second.playerId].value().velocity * movement[packet.second.y];
            int resultX = velocity[packet.second.playerId].value().velocity * movement[packet.second.x];

            position[packet.second.playerId].value().x += resultX;
            position[packet.second.playerId].value().y += resultY;
            // std::cout << "x: " << position[packet.second.playerId].value().x << " y: " << position[packet.second.playerId].value().y << std::endl;
            netqueue[0].value().toSendNetworkQueue.push({0, serialize_header::serializeHeader<packet_position>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::POSITION, {packet.second.playerId, position[packet.second.playerId].value().x, position[packet.second.playerId].value().y, 1})});
        }
    }
}
