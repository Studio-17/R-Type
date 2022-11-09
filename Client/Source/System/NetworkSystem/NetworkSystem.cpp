/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NetworkSystem
*/

#include "NetworkSystem.hpp"
#include "Serialization.hpp"
#include "Constant.hpp"

/* Packet */
#include "Position.hpp"
#include "NewEntity.hpp"
#include "KillEntity.hpp"
#include "Lobbies.hpp"
#include "NewConnection.hpp"
#include "UpdateEntityInfos.hpp"

System::NetworkSystem::NetworkSystem()
{
}

void System::NetworkSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cid_of_ship_t> &idOfShip)
{
    while (!network[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.empty()) {
        std::vector<byte> &tmp = network[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.front();
        uint8_t id = serialize_header::getId(tmp);

        std::vector<byte> bufferWithoutId;
        bufferWithoutId.insert(bufferWithoutId.begin(), tmp.begin() + sizeof(id), tmp.end());
        std::cout << "Network System new packet " << static_cast<int>(id) << std::endl;
        if (id == NETWORK_SERVER_TO_CLIENT::POSITION)
            dispatchToPositionQueue(bufferWithoutId, network);
        if (id == NETWORK_SERVER_TO_CLIENT::NEW_ENTITY)
            dispatchToNewEntityQueue(bufferWithoutId, network);
        if (id == NETWORK_SERVER_TO_CLIENT::KILL_ENTITY) {
            std::cout << "Network system kill entity" << std::endl;
            dispatchToKillEntityQueue(bufferWithoutId, network);
        }
        if (id == NETWORK_SERVER_TO_CLIENT::KILL_ENTITY_TYPE) {
            std::cout << "Network system kill entity type" << std::endl;
            dispatchToKillEntityTypeQueue(bufferWithoutId, network);
        }
        if (id == NETWORK_SERVER_TO_CLIENT::NEW_PLAYER)
            handleNewPlayerAndDispatchToNewEntityQueue(bufferWithoutId, network, idOfShip);
        if (id == NETWORK_SERVER_TO_CLIENT::SEND_LOBBYS)
            dispatchToGetLobbiesQueue(bufferWithoutId, network);
        if (id == NETWORK_SERVER_TO_CLIENT::NUMBER_PLAYERS_IN_LOBBY)
            dispatchNbPlayersInLobbyQueue(bufferWithoutId, network);
        if (id == NETWORK_SERVER_TO_CLIENT::NEW_CLIENT_RESPONSE)
            dispatchNetworkClientIdQueue(bufferWithoutId, network);
        if (id == NETWORK_SERVER_TO_CLIENT::UPDATE_ENTITY_HEALTH)
            dispatchUpdateEntityHealthQueue(bufferWithoutId, network);
        if (id == NETWORK_SERVER_TO_CLIENT::UPDATE_ENTITY_SCORE)
            dispatchUpdateEntityScoreQueue(bufferWithoutId, network);

        network[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.pop();
    }

}

void System::NetworkSystem::dispatchToPositionQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_position packet = serializable_trait<packet_position>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().updatePositionQueue.push(packet);
}

void System::NetworkSystem::dispatchToNewEntityQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_new_entity packet = serializable_trait<packet_new_entity>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().newEntityQueue.push(packet);
}

void System::NetworkSystem::dispatchToKillEntityQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_kill_entity packet = serializable_trait<packet_kill_entity>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().killEntityQueue.push(packet);
}

void System::NetworkSystem::dispatchToKillEntityTypeQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_kill_entity_type packet = serializable_trait<packet_kill_entity_type>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().killEntityTypeQueue.push(packet);
}

void System::NetworkSystem::handleNewPlayerAndDispatchToNewEntityQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cid_of_ship_t> &idOfShip)
{
    packet_new_entity packet = serializable_trait<packet_new_entity>::unserialize(bytes);

    if (idOfShip[FORBIDDEN_IDS::NETWORK].value().id == 0)
        idOfShip[FORBIDDEN_IDS::NETWORK].value().id = packet.id;
    network[FORBIDDEN_IDS::NETWORK].value().newEntityQueue.push(packet);
}

void System::NetworkSystem::dispatchToGetLobbiesQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_send_lobbies packet = serializable_trait<packet_send_lobbies>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().getLobbiesQueue.push(packet);
}

void System::NetworkSystem::dispatchNbPlayersInLobbyQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_nb_players_in_lobby packet = serializable_trait<packet_nb_players_in_lobby>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().nbPlayerInLobbyQueue.push(packet);
}

void System::NetworkSystem::dispatchNetworkClientIdQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_new_connection_response packet = serializable_trait<packet_new_connection_response>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().newConnectionResponseQueue.push(packet);
}

void System::NetworkSystem::dispatchUpdateEntityHealthQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_update_entity_health packet = serializable_trait<packet_update_entity_health>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().updateEntityHealthQueue.push(packet);
}

void System::NetworkSystem::dispatchUpdateEntityScoreQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_update_entity_score packet = serializable_trait<packet_update_entity_score>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().updateEntityScoreQueue.push(packet);
}

