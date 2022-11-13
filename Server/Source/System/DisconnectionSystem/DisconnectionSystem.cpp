/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** DisconnectionSystem
*/

#include <algorithm>

/* Systems */
#include "DisconnectionSystem.hpp"

/* Serialization */
#include "Serialization.hpp"

/* Constant */
#include "Constant.hpp"

/* Packets */
#include "KillEntity.hpp"

System::DisconnectionSystem::DisconnectionSystem()
{
}

void System::DisconnectionSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network_queues, Sparse_array<component::clobby_id_t> &lobbyId, [[ maybe_unused ]] Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId, Sparse_array<component::cdisconnected_t> &disconnected)
{
    if (network_queues[FORBIDDEN_IDS::NETWORK]) {
        while (!network_queues[FORBIDDEN_IDS::NETWORK].value().disconnectionQueue.empty()) {
            std::pair<int, packet_disconnection> &packet = network_queues[FORBIDDEN_IDS::NETWORK].value().disconnectionQueue.front();
            int clientLobbyId = lobbyId[netIdToClientId[FORBIDDEN_IDS::NETWORK].value().netIdToClientId.at(packet.first)].value().id;

            if (packet.second.disconnection != 0) {
                network_queues[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({clientLobbyId, serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, {static_cast<int>(packet.second.disconnection)})});
                registry.kill_entity(registry.entity_from_index(packet.second.disconnection));
            }
            disconnected[netIdToClientId[FORBIDDEN_IDS::NETWORK].value().netIdToClientId.at(packet.first)].value().isDisconnected = true;
            network_queues[FORBIDDEN_IDS::NETWORK].value().disconnectionQueue.pop();
        }
    }
}
