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
        packet_move packet = netqueue[0].value().moveQueue.front();
        netqueue[0].value().moveQueue.pop();
        if (velocity[packet.playerId] && position[packet.playerId]) {
            std::unordered_map<uint16_t, int> movement = {{0, 0}, {1, 1}, {2, -1}};
            int resultY = velocity[packet.playerId].value().velocity * movement[packet.y];
            int resultX = velocity[packet.playerId].value().velocity * movement[packet.x];

            position[packet.playerId].value().x += resultX;
            position[packet.playerId].value().y += resultY;
            netqueue[0].value().toSendNetworkQueue.push(serialize_header::serializeHeader<packet_position>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::POSITION, {packet.playerId, position[packet.playerId].value().x, position[packet.playerId].value().y, 1}));
        }
    }
}
