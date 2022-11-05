/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** ReceiveSystem
*/

#include "ReceiveSystem.hpp"
#include "Serialization.hpp"
#include "Constant.hpp"

System::ReceiveSystem::ReceiveSystem()
{
}

void System::ReceiveSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cnetwork_queue_t> &queues)
{
    if (queues[0].value().receivedNetworkQueue.empty())
        return;
    std::pair<int, std::vector<byte>> &buffer = queues[0].value().receivedNetworkQueue.front();
    uint8_t id = serialize_header::getId(buffer.second);

    std::vector<byte> bufferWithoutId;
    bufferWithoutId.insert(bufferWithoutId.begin(), buffer.second.begin() + sizeof(id), buffer.second.end());
    try {
        callBacks.at(id)(bufferWithoutId, buffer.first, queues);
    } catch (std::out_of_range const &) {
        std::cout << "Undefined packet id: " << id << std::endl;
    }
    queues[0].value().receivedNetworkQueue.pop();
}

void System::ReceiveSystem::addMoveOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues)
{
    packet_move newMove = serializable_trait<packet_move>::unserialize(data);
    queues[FORBIDDEN_IDS::NETWORK].value().moveQueue.push(std::pair<int, packet_move>(clientId, newMove));
}

void System::ReceiveSystem::addShootOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues)
{
    packet_shoot newShoot = serializable_trait<packet_shoot>::unserialize(data);
    queues[FORBIDDEN_IDS::NETWORK].value().shootQueue.push(std::pair<int, packet_shoot> (clientId, newShoot));
}

void System::ReceiveSystem::addNewPLayerOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues)
{
    packet_new_connection newConnection = serializable_trait<packet_new_connection>::unserialize(data);
    queues[FORBIDDEN_IDS::NETWORK].value().newPlayerQueue.push(std::pair<int, packet_new_connection>(clientId, newConnection));
}

void System::ReceiveSystem::addDisconnectionOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues)
{
    packet_disconnection disconnection = serializable_trait<packet_disconnection>::unserialize(data);
    queues[FORBIDDEN_IDS::NETWORK].value().disconnectionQueue.push(std::pair<int, packet_disconnection>(clientId, disconnection));
}

void System::ReceiveSystem::addJoinLobbyOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues)
{
    packet_join_lobby join_lobby = serializable_trait<packet_join_lobby>::unserialize(data);
    queues[FORBIDDEN_IDS::NETWORK].value().joinLobbyQueue.push(std::pair<int, packet_join_lobby>(clientId, join_lobby));
}

void System::ReceiveSystem::addStartGameOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues)
{
    packet_start_game start_game = serializable_trait<packet_start_game>::unserialize(data);
    queues[FORBIDDEN_IDS::NETWORK].value().startGameQueue.push(std::pair<int, packet_start_game>(clientId, start_game));
}
