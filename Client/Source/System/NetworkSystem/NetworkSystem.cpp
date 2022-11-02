/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NetworkSystem
*/

#include <functional>

#include "Constant/Constant.hpp"
#include "KillEntity.hpp"
#include "Lobbies.hpp"
#include "NetworkSystem.hpp"
#include "NewEntity.hpp"
#include "Position.hpp"
#include "Serialization.hpp"

NetworkSystem::NetworkSystem()
{
}

void NetworkSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cid_of_ship_t> &idOfShip)
{
    const std::map<std::size_t, std::function<void(std::vector<byte>)>> queuesFunction;
    // {NETWORK_SERVER_TO_CLIENT::POSITION, std::bind(&NetworkSystem::dispatchToPositionQueue, this, std::placeholders::_1, network)},
    // {NETWORK_SERVER_TO_CLIENT::NEW_ENTITY, std::bind(&NetworkSystem::dispatchToNewEntityQueue, this, std::placeholders::_1, network)},
    // {NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, std::bind(&NetworkSystem::dispatchToKillEntityQueue, this, std::placeholders::_1, network)},
    // {NETWORK_SERVER_TO_CLIENT::NEW_PLAYER, std::bind(&NetworkSystem::handleNewPlayerAndDispatchToNewEntityQueue, this, std::placeholders::_1, network, idOfShip)},
    // {NETWORK_SERVER_TO_CLIENT::SEND_LOBBYS, std::bind(&NetworkSystem::dispatchToGetLobbiesQueue, this, std::placeholders::_1, network)}

    if (!network[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.empty()) {
        std::vector<byte> tmp = network[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.front();
        uint8_t id = serialize_header::getId(tmp);

        std::vector<byte> bufferWithoutId;
        bufferWithoutId.insert(bufferWithoutId.begin(), tmp.begin() + sizeof(id), tmp.end());

        if (id == NETWORK_SERVER_TO_CLIENT::POSITION)
            dispatchToPositionQueue(bufferWithoutId, network);
        if (id == NETWORK_SERVER_TO_CLIENT::NEW_ENTITY)
            dispatchToNewEntityQueue(bufferWithoutId, network);
        if (id == NETWORK_SERVER_TO_CLIENT::KILL_ENTITY)
            dispatchToKillEntityQueue(bufferWithoutId, network);
        if (id == NETWORK_SERVER_TO_CLIENT::NEW_PLAYER)
            handleNewPlayerAndDispatchToNewEntityQueue(bufferWithoutId, network, idOfShip);
        if (id == NETWORK_SERVER_TO_CLIENT::SEND_LOBBYS)
            dispatchToGetLobbiesQueue(bufferWithoutId, network);
        if (id == NETWORK_SERVER_TO_CLIENT::NB_PLAYERS_IN_LOBBY)
            dispatchNbPlayersInLobbyQueue(bufferWithoutId, network);

        network[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.pop();
    }

}

void NetworkSystem::dispatchToPositionQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_position packet = serializable_trait<packet_position>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().updatePositionQueue.push(packet);
}

void NetworkSystem::dispatchToNewEntityQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_new_entity packet = serializable_trait<packet_new_entity>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().newEntityQueue.push(packet);
}

void NetworkSystem::dispatchToKillEntityQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_kill_entity packet = serializable_trait<packet_kill_entity>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().killEntityQueue.push(packet);
}

void NetworkSystem::handleNewPlayerAndDispatchToNewEntityQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cid_of_ship_t> &idOfShip)
{
    packet_new_entity packet = serializable_trait<packet_new_entity>::unserialize(bytes);

    if (idOfShip[FORBIDDEN_IDS::NETWORK].value().id == 0)
        idOfShip[FORBIDDEN_IDS::NETWORK].value().id = packet.id;
    network[FORBIDDEN_IDS::NETWORK].value().newEntityQueue.push(packet);
}

void NetworkSystem::dispatchToGetLobbiesQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_send_lobbies packet = serializable_trait<packet_send_lobbies>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().getLobbiesQueue.push(packet);
}

void NetworkSystem::dispatchNbPlayersInLobbyQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_nb_players_in_lobby packet = serializable_trait<packet_nb_players_in_lobby>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().nbPlayerInLobbyQueue.push(packet);
}