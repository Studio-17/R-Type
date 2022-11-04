/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** NewClientSystem
*/

#include "NewClientSystem.hpp"
#include "CLobbyId.hpp"
#include "Constant.hpp"
#include "Lobbies.hpp"
#include "NewConnection.hpp"
#include "Serialization.hpp"

NewClientSystem::NewClientSystem() {
}

void NewClientSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities) {
    while (!netqueue[FORBIDDEN_IDS::NETWORK].value().newPlayerQueue.empty()) {
        std::pair<int, packet_new_connection> newConnect = netqueue[0].value().newPlayerQueue.front();

        // CREATE A CLIENT ENTITY
        Entity newClient = registry.spawn_entity();

        // ADD A NETWORK ID TO CLIENT ENTITY
        component::cnetwork_id_t netId;
        std::cout << "New client System : network client id:  " << newConnect.second.id << std::endl;
        netId.id = newConnect.second.id;
        registry.add_component<component::cnetwork_id_t>(newClient, std::move(netId));

        // GIVE A LOBBY ID WHERE THE CLIENT IS
        component::clobby_id_t lobbyId;
        lobbyId.id = 0;
        registry.add_component<component::clobby_id_t>(newClient, std::move(lobbyId));

        netIdToClientId[FORBIDDEN_IDS::NETWORK].value().netIdToClientId.try_emplace(newConnect.second.id, newClient);
        lobbiesToEntities[FORBIDDEN_IDS::NETWORK].value().lobbiesToEntities.try_emplace(1, std::vector<Entity>());
        lobbiesToEntities[FORBIDDEN_IDS::NETWORK].value().lobbiesToEntities.try_emplace(2, std::vector<Entity>());
        lobbiesToEntities[FORBIDDEN_IDS::NETWORK].value().lobbiesToEntities.try_emplace(3, std::vector<Entity>());

        lobbiesToEntities[FORBIDDEN_IDS::NETWORK].value().lobbiesToEntities.try_emplace(lobbyId.id, std::vector<Entity>());
        lobbiesToEntities[FORBIDDEN_IDS::NETWORK].value().lobbiesToEntities.at(lobbyId.id).push_back(newClient);

        netqueue[FORBIDDEN_IDS::NETWORK].value().newPlayerQueue.pop();
        sendLobbiesStatus(newClient, netqueue, lobbiesToEntities);
        // for (auto &[netId, clientId]: netIdToClientId[FORBIDDEN_IDS::NETWORK].value().netIdToClientId)
        //     std::cout << "[CLIENT] ids: " << netId << ", " << clientId << std::endl;
    }
}

void NewClientSystem::sendLobbiesStatus(int clientId, Sparse_array<component::cnetwork_queue_t> &networkQueue, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities) {
    packet_send_lobbies sendLobbiesPacket;

    sendLobbiesPacket.nbOfLobbies = 3;
    sendLobbiesPacket.nbPlayersLobbyOne = lobbiesToEntities[FORBIDDEN_IDS::NETWORK].value().lobbiesToEntities.at(1).size();
    sendLobbiesPacket.nbPlayersLobbyTwo = lobbiesToEntities[FORBIDDEN_IDS::NETWORK].value().lobbiesToEntities.at(2).size();
    sendLobbiesPacket.nbPlayersLobbyThree = lobbiesToEntities[FORBIDDEN_IDS::NETWORK].value().lobbiesToEntities.at(3).size();


    packet_new_connection_response newConnectResponse;
    newConnectResponse.id = clientId;
    networkQueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(std::pair<int, std::vector<byte>>(0, serialize_header::serializeHeader<packet_new_connection_response>(NETWORK_SERVER_TO_CLIENT::NEW_CLIENT_RESPONSE, newConnectResponse)));
    std::cout << " New client system : send Lobbies status : new client ecs id :  "<< clientId << std::endl;
    networkQueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(std::pair<int, std::vector<byte>>(0, serialize_header::serializeHeader<packet_send_lobbies>(NETWORK_SERVER_TO_CLIENT::SEND_LOBBYS, sendLobbiesPacket)));
}