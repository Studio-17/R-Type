/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NetworkSystem
*/

#include "NetworkSystem.hpp"

/* Constant */
#include "Constant.hpp"

/* Packet */
#include "Position.hpp"
#include "NewEntity.hpp"
#include "KillEntity.hpp"
#include "Lobbies.hpp"
#include "NewConnection.hpp"
#include "UpdateEntityInfos.hpp"
#include "NewLevel.hpp"
#include "EndGame.hpp"

System::NetworkSystem::NetworkSystem() :
    _callBacks ({
        {NETWORK_SERVER_TO_CLIENT::POSITION , std::bind(&System::NetworkSystem::dispatchToPositionQueue, this, std::placeholders::_1, std::placeholders::_2)},
        {NETWORK_SERVER_TO_CLIENT::NEW_ENTITY , std::bind(&System::NetworkSystem::dispatchToNewEntityQueue, this, std::placeholders::_1, std::placeholders::_2)},
        {NETWORK_SERVER_TO_CLIENT::KILL_ENTITY , std::bind(&System::NetworkSystem::dispatchToKillEntityQueue, this, std::placeholders::_1, std::placeholders::_2)},
        {NETWORK_SERVER_TO_CLIENT::KILL_ENTITY_TYPE , std::bind(&System::NetworkSystem::dispatchToKillEntityTypeQueue, this, std::placeholders::_1, std::placeholders::_2)},
        {NETWORK_SERVER_TO_CLIENT::NEW_CLIENT_RESPONSE , std::bind(&System::NetworkSystem::dispatchNetworkClientIdQueue, this, std::placeholders::_1, std::placeholders::_2)},
        {NETWORK_SERVER_TO_CLIENT::SEND_LOBBYS , std::bind(&System::NetworkSystem::dispatchToGetLobbiesQueue, this, std::placeholders::_1, std::placeholders::_2)},
        {NETWORK_SERVER_TO_CLIENT::NUMBER_PLAYERS_IN_LOBBY , std::bind(&System::NetworkSystem::dispatchNbPlayersInLobbyQueue, this, std::placeholders::_1, std::placeholders::_2)},
        {NETWORK_SERVER_TO_CLIENT::UPDATE_ENTITY_HEALTH , std::bind(&System::NetworkSystem::dispatchUpdateEntityHealthQueue, this, std::placeholders::_1, std::placeholders::_2)},
        {NETWORK_SERVER_TO_CLIENT::UPDATE_ENTITY_SCORE , std::bind(&System::NetworkSystem::dispatchUpdateEntityScoreQueue, this, std::placeholders::_1, std::placeholders::_2)},
        {NETWORK_SERVER_TO_CLIENT::END_GAME , std::bind(&System::NetworkSystem::dispatchEndGameQueue, this, std::placeholders::_1, std::placeholders::_2)},
        {NETWORK_SERVER_TO_CLIENT::NEW_LEVEL, std::bind(&System::NetworkSystem::dispatchNewLevelQueue,this, std::placeholders::_1, std::placeholders::_2)}
    })
{
}

void System::NetworkSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cnetwork_queue_t> &network)
{
    while (!network[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.empty()) {
        std::vector<byte> &tmp = network[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.front();
        uint8_t id = serialize_header::getId(tmp);

        std::vector<byte> bufferWithoutId;
        bufferWithoutId.insert(bufferWithoutId.begin(), tmp.begin() + sizeof(id), tmp.end());
        try {
            _callBacks.at(static_cast<NETWORK_SERVER_TO_CLIENT::PACKET_TYPE>(id))(bufferWithoutId, network);
        } catch (std::out_of_range const &e) {
            std::cerr << "Network System Undefined packet id: " << id << std::endl;
        }
        // std::cout << "Network System new packet " << static_cast<int>(id) << std::endl;
        network[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.pop();
    }

}

void System::NetworkSystem::dispatchToPositionQueue(std::vector<byte> const &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_position packet = serializable_trait<packet_position>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().updatePositionQueue.push(packet);
}

void System::NetworkSystem::dispatchToNewEntityQueue(std::vector<byte> const &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_new_entity packet = serializable_trait<packet_new_entity>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().newEntityQueue.push(packet);
}

void System::NetworkSystem::dispatchToKillEntityQueue(std::vector<byte> const &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_kill_entity packet = serializable_trait<packet_kill_entity>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().killEntityQueue.push(packet);
}

void System::NetworkSystem::dispatchToKillEntityTypeQueue(std::vector<byte> const &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_kill_entity_type packet = serializable_trait<packet_kill_entity_type>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().killEntityTypeQueue.push(packet);
}

void System::NetworkSystem::dispatchToGetLobbiesQueue(std::vector<byte> const &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_send_lobbies packet = serializable_trait<packet_send_lobbies>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().getLobbiesQueue.push(packet);
}

void System::NetworkSystem::dispatchNbPlayersInLobbyQueue(std::vector<byte> const &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_nb_players_in_lobby packet = serializable_trait<packet_nb_players_in_lobby>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().nbPlayerInLobbyQueue.push(packet);
}

void System::NetworkSystem::dispatchNetworkClientIdQueue(std::vector<byte> const &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_new_connection_response packet = serializable_trait<packet_new_connection_response>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().newConnectionResponseQueue.push(packet);
}

void System::NetworkSystem::dispatchUpdateEntityHealthQueue(std::vector<byte> const &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_update_entity_health packet = serializable_trait<packet_update_entity_health>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().updateEntityHealthQueue.push(packet);
}

void System::NetworkSystem::dispatchUpdateEntityScoreQueue(std::vector<byte> const &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_update_entity_score packet = serializable_trait<packet_update_entity_score>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().updateEntityScoreQueue.push(packet);
}

void System::NetworkSystem::dispatchNewLevelQueue(std::vector<byte> const &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_new_level packet = serializable_trait<packet_new_level>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().newLevelQueue.push(packet);
}

void System::NetworkSystem::dispatchEndGameQueue(std::vector<byte> const &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_end_game packet = serializable_trait<packet_end_game>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK].value().endGameQueue.push(packet);
}
