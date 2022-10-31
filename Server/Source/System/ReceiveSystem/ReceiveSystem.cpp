/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** ReceiveSystem
*/

#include "ReceiveSystem.hpp"
#include "Serialization.hpp"

System::ReceiveSystem::ReceiveSystem()
{
}

void System::ReceiveSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cnetwork_queue_t> &queues)
{
    if (queues[0].value().receivedNetworkQueue.empty())
        return;
    std::vector<byte> buffer = queues[0].value().receivedNetworkQueue.front();
    queues[0].value().receivedNetworkQueue.pop();
    uint8_t id = serialize_header::getId(buffer);

    std::vector<byte> bufferWithoutId;
    bufferWithoutId.insert(bufferWithoutId.begin(), buffer.begin() + sizeof(id), buffer.end());
    try {
        callBacks.at(id)(bufferWithoutId, queues);
    } catch (std::out_of_range const &) {
        std::cerr << "undefined packet id: " << id << std::endl;
    }
}

void System::ReceiveSystem::addMoveOnQueue(std::vector<byte> const &data, Sparse_array<component::cnetwork_queue_t> &queues)
{
    packet_move newMove = serializable_trait<packet_move>::unserialize(data);
    queues[0].value().moveQueue.push(newMove);
}

void System::ReceiveSystem::addShootOnQueue(std::vector<byte> const &data, Sparse_array<component::cnetwork_queue_t> &queues)
{
    packet_shoot newMove = serializable_trait<packet_shoot>::unserialize(data);
    queues[0].value().shootQueue.push(newMove);
}

void System::ReceiveSystem::addNewPLayerOnQueue(std::vector<byte> const &data, Sparse_array<component::cnetwork_queue_t> &queues)
{
    // std::cout << "[Server] new Connexion" << std::endl;
    packet_new_connexion newMove = serializable_trait<packet_new_connexion>::unserialize(data);
    queues[0].value().newPlayerQueue.push(newMove);
}
