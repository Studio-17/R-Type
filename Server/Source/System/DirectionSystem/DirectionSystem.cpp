/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** DirectionSystem
*/

#include <unordered_map>

/* Components */
#include "Component/CVelocity.hpp"

/* Packets */
#include "DirectionSystem.hpp"
#include "Serialization.hpp"
#include "Constant.hpp"
#include "Move.hpp"
#include "Position.hpp"

System::DirectionSystem::DirectionSystem()
{
}

void System::DirectionSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, [[ maybe_unused ]] Sparse_array<component::cdirection_t> &direction, Sparse_array<component::cposition_t> &position, Sparse_array<component::cvelocity_t> &velocity, Sparse_array<component::clobby_id_t> &LobbyId, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId)
{
    if (!netqueue[FORBIDDEN_IDS::NETWORK].value().moveQueue.empty()) {
        std::pair<int, packet_move> &packet = netqueue[FORBIDDEN_IDS::NETWORK].value().moveQueue.front();
        if (velocity[packet.second.playerId] && position[packet.second.playerId]) {
            // std::cout << "[SERVER] do movement for id : " << packet.second.playerId << std::endl;
            std::unordered_map<uint16_t, int> movement {{0, 0}, {1, 1}, {2, -1}};
            int resultY = velocity[packet.second.playerId].value().velocity * movement[packet.second.y];
            int resultX = velocity[packet.second.playerId].value().velocity * movement[packet.second.x];

            position[packet.second.playerId].value().x += resultX;
            position[packet.second.playerId].value().y += resultY;

            int lobbyId = LobbyId[netIdToClientId[FORBIDDEN_IDS::NETWORK].value().netIdToClientId.at(packet.first)].value().id;

            netqueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({lobbyId, serialize_header::serializeHeader<packet_position>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::POSITION, {packet.second.playerId, position[packet.second.playerId].value().x, position[packet.second.playerId].value().y, 1})});
        }
        netqueue[FORBIDDEN_IDS::NETWORK].value().moveQueue.pop();
    }
}
