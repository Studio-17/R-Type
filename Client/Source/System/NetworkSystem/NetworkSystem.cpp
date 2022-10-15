/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NetworkSystem
*/

#include "NetworkSystem.hpp"
#include "Constant/Constant.hpp"
#include "Serialization.hpp"

NetworkSystem::NetworkSystem()
{
}

void NetworkSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network)
{
    if (!network[FORBIDDEN_IDS::NETWORK]->receivedNetworkQueue.empty()) {
        std::vector<byte> tmp = network[FORBIDDEN_IDS::NETWORK]->receivedNetworkQueue.front();
        uint8_t id = serialize_header::getId(tmp);

        std::vector<byte> bufferWithoutId;
        bufferWithoutId.insert(bufferWithoutId.begin(), tmp.begin() + sizeof(id), tmp.end());

        if (id == NETWORK_SERVER_TO_CLIENT::POSITION)
            dispatchToPositionQueue(bufferWithoutId, network);
        if (id == NETWORK_SERVER_TO_CLIENT::NEW_ENTITY)
            dispatchToNewEntityQueue(bufferWithoutId, network);
        network[FORBIDDEN_IDS::NETWORK]->receivedNetworkQueue.pop();
    }

}

void NetworkSystem::dispatchToPositionQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_position packet = serializable_trait<packet_position>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK]->updatePositionQueue.push(packet);
}

void NetworkSystem::dispatchToNewEntityQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network)
{
    packet_new_entity packet = serializable_trait<packet_new_entity>::unserialize(bytes);
    network[FORBIDDEN_IDS::NETWORK]->newEntityQueue.push(packet);
}

