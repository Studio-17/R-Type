/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** DisconnectionSystem
*/

#include <algorithm>

#include "DisconnectionSystem.hpp"
#include "Serialization.hpp"
#include "Constant.hpp"
#include "KillEntity.hpp"

System::DisconnectionSystem::DisconnectionSystem()
{
}

void System::DisconnectionSystem::removeClientLobby(int netClientId, Sparse_array<component::clobby_id_t> &lobbyId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId)
{
    Entity clientEntity = netIdToClientId[FORBIDDEN_IDS::NETWORK].value().netIdToClientId.at(netClientId);

    // remove client Entity from lobby vector
    int currentLobbyId = lobbyId[clientEntity].value().id;
    auto &entityList = lobbiesToEntities[FORBIDDEN_IDS::NETWORK].value().lobbiesToEntities.at(currentLobbyId);
    std::vector<Entity>::iterator it = std::find(entityList.begin(), entityList.end(), clientEntity);
    entityList.erase(it);
}

void System::DisconnectionSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network_queues, Sparse_array<component::clobby_id_t> &lobbyId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId)
{
    if (network_queues[FORBIDDEN_IDS::NETWORK]) {
        while (!network_queues[FORBIDDEN_IDS::NETWORK].value().disconnectionQueue.empty()) {
            std::pair<int, packet_disconnection> packet = network_queues[FORBIDDEN_IDS::NETWORK].value().disconnectionQueue.front();
            network_queues[FORBIDDEN_IDS::NETWORK].value().disconnectionQueue.pop();
            network_queues[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({0, serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, {static_cast<int>(packet.second.disconnection)})});
            registry.kill_entity(registry.entity_from_index(packet.second.disconnection));
            removeClientLobby(packet.first, lobbyId, lobbiesToEntities, netIdToClientId);
        }
    }
}
