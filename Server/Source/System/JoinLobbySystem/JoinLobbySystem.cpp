/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** JoinLobbySystem
*/

#include <algorithm>

#include "JoinLobbySystem.hpp"

/* Serialization */
#include "Serialization.hpp"

/* Constant */
#include "Constant.hpp"

System::JoinLobbySystem::JoinLobbySystem()
{
}

void System::JoinLobbySystem::changeClientLobby(int netClientId, int newLobbyId, Sparse_array<component::clobby_id_t> &lobbyId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId)
{
    Entity clientEntity = netIdToClientId[FORBIDDEN_IDS::NETWORK].value().netIdToClientId.at(netClientId);

    // remove client Entity from lobby vector
    int currentLobbyId = lobbyId[clientEntity].value().id;
    auto &entityList = lobbiesToEntities[FORBIDDEN_IDS::LOBBY].value().lobbiesToEntities.at(currentLobbyId);
    std::vector<Entity>::iterator it = std::find(entityList.begin(), entityList.end(), clientEntity);
    entityList.erase(it);

    // set the new lobby id in Client Entity
    lobbyId[clientEntity].value().id = newLobbyId;

    std::cout << "Join Lobby System: Client " << netClientId << " changed lobby from " << currentLobbyId << " to " << newLobbyId << std::endl;

    // add in the new lobby Entities vector the entity of the client
    try {
        lobbiesToEntities[FORBIDDEN_IDS::LOBBY].value().lobbiesToEntities.at(newLobbyId).push_back(clientEntity);
    } catch (std::out_of_range const &e) {
        std::cerr << "lobby " << newLobbyId << " is undefined" << std::endl;
    }
}

void System::JoinLobbySystem::operator()([[ maybe_unused ]]Registry &registry, Sparse_array<component::cnetwork_queue_t> &networkQueue, Sparse_array<component::clobby_id_t> &lobbyId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId)
{
    if (networkQueue[FORBIDDEN_IDS::NETWORK]) {
        while (!networkQueue[FORBIDDEN_IDS::NETWORK].value().joinLobbyQueue.empty()) {
            std::pair<int, packet_join_lobby> &packet = networkQueue[FORBIDDEN_IDS::NETWORK].value().joinLobbyQueue.front();

            changeClientLobby(packet.first, packet.second.id, lobbyId, lobbiesToEntities, netIdToClientId);

            packet_nb_players_in_lobby nbPlayersInLobby;
            try {
                nbPlayersInLobby.nbPlayers = lobbiesToEntities[FORBIDDEN_IDS::LOBBY].value().lobbiesToEntities.at(packet.second.id).size();
            } catch (std::out_of_range const &e) {
                networkQueue[FORBIDDEN_IDS::NETWORK].value().joinLobbyQueue.pop();
                return;
            }

            packet_send_lobbies sendLobbiesPacket;

            sendLobbiesPacket.nbOfLobbies = 3;
            sendLobbiesPacket.nbPlayersLobbyOne = lobbiesToEntities[FORBIDDEN_IDS::LOBBY].value().lobbiesToEntities.at(1).size();
            sendLobbiesPacket.nbPlayersLobbyTwo = lobbiesToEntities[FORBIDDEN_IDS::LOBBY].value().lobbiesToEntities.at(2).size();
            sendLobbiesPacket.nbPlayersLobbyThree = lobbiesToEntities[FORBIDDEN_IDS::LOBBY].value().lobbiesToEntities.at(3).size();

            networkQueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({packet.second.id, serialize_header::serializeHeader<packet_nb_players_in_lobby>(NETWORK_SERVER_TO_CLIENT::NUMBER_PLAYERS_IN_LOBBY, nbPlayersInLobby)});
            networkQueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(std::pair<int, std::vector<byte>>(0, serialize_header::serializeHeader<packet_send_lobbies>(NETWORK_SERVER_TO_CLIENT::SEND_LOBBYS, sendLobbiesPacket)));
            networkQueue[FORBIDDEN_IDS::NETWORK].value().joinLobbyQueue.pop();
        }
    }
}
