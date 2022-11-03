/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** JoinLobbySystem
*/

#include <algorithm>

#include "Serialization.hpp"
#include "JoinLobbySystem.hpp"
#include "Constant.hpp"

JoinLobbySystem::JoinLobbySystem()
{
}

void JoinLobbySystem::changeClientLobby(int netClientId, int newLobbyId, Sparse_array<component::clobby_id_t> &lobbyId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId)
{
    Entity clientEntity = netIdToClientId[FORBIDDEN_IDS::NETWORK].value().netIdToClientId.at(netClientId);

    // remove client Entity from lobby vector
    int currentLobbyId = lobbyId[clientEntity].value().id;
    auto &entityList = lobbiesToEntities[FORBIDDEN_IDS::NETWORK].value().lobbiesToEntities.at(currentLobbyId);
    std::vector<Entity>::iterator it = std::find(entityList.begin(), entityList.end(), clientEntity);
    entityList.erase(it);

    // set the new lobby id in Client Entity
    lobbyId[clientEntity].value().id = newLobbyId;

    // add in the new lobby Entities vector the entity of the client
    try {
        lobbiesToEntities[FORBIDDEN_IDS::NETWORK].value().lobbiesToEntities.at(newLobbyId).push_back(clientEntity);
    } catch (std::out_of_range const &e) {
        std::cerr << "lobby " << newLobbyId << " is undefined" << std::endl;
    }
}

void JoinLobbySystem::operator()([[ maybe_unused ]]Registry &registry, Sparse_array<component::cnetwork_queue_t> &networkQueue, Sparse_array<component::clobby_id_t> &lobbyId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId)
{
    if (networkQueue[FORBIDDEN_IDS::NETWORK]) {
        while (!networkQueue[FORBIDDEN_IDS::NETWORK].value().joinLobbyQueue.empty()) {
            std::pair<int, packet_join_lobby> &packet = networkQueue[FORBIDDEN_IDS::NETWORK].value().joinLobbyQueue.front();

            changeClientLobby(packet.first, packet.second.id, lobbyId, lobbiesToEntities, netIdToClientId);

            // int nbPlayersInLobby = lobbiesToEntities[FORBIDDEN_IDS::NETWORK].value().lobbiesToEntities.at(lobbyId[netIdToClientId[FORBIDDEN_IDS::NETWORK].value().netIdToClientId.at(packet.first)].value().id).size();
            packet_nb_players_in_lobby nbPlayersInLobby;
            try {
                nbPlayersInLobby.nbPlayers = lobbiesToEntities[FORBIDDEN_IDS::NETWORK].value().lobbiesToEntities.at(packet.second.id).size();
            } catch (std::out_of_range const &e) {
                networkQueue[FORBIDDEN_IDS::NETWORK].value().joinLobbyQueue.pop();
                return;
            }

            networkQueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({packet.second.id, serialize_header::serializeHeader<packet_nb_players_in_lobby>(NETWORK_SERVER_TO_CLIENT::NUMBER_PLAYERS_IN_LOBBY, nbPlayersInLobby)});
            networkQueue[FORBIDDEN_IDS::NETWORK].value().joinLobbyQueue.pop();
        }
    }
}
