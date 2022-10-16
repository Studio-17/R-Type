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

void System::ReceiveSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &queues)
{
    if (queues[0]->receivedNetworkQueue.empty())
        return;
    std::vector<byte> buffer = queues[0]->receivedNetworkQueue.front();
    queues[0]->receivedNetworkQueue.pop();
    uint8_t id = serialize_header::getId(buffer);

    std::vector<byte> bufferWithoutId;
    bufferWithoutId.insert(bufferWithoutId.begin(), buffer.begin() + sizeof(id), buffer.end());
    try {
        callBacks.at(id)(bufferWithoutId, queues);
    } catch (std::out_of_range const &) {
        std::cerr << "undefined packet id: " << id << std::endl;
    }
}

void System::ReceiveSystem::addHitOnQueue(std::vector<byte> const &data, Sparse_array<component::cnetwork_queue_t> &queues)
{

}


void System::ReceiveSystem::addMoveOnQueue(std::vector<byte> const &data, Sparse_array<component::cnetwork_queue_t> &queues)
{
    packet_move newMove = serializable_trait<packet_move>::unserialize(data);
    queues[0]->moveQueue.push(newMove);
}

void System::ReceiveSystem::addShootOnQueue(std::vector<byte> const &data, Sparse_array<component::cnetwork_queue_t> &queues)
{
    packet_shoot newMove = serializable_trait<packet_shoot>::unserialize(data);
    queues[0]->shootQueue.push(newMove);
}

