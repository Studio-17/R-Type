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
        std::cout << "network sysytem" << std::endl;
        // Here parse and send to the corresponing queue
        std::vector<byte> tmp = network[FORBIDDEN_IDS::NETWORK]->receivedNetworkQueue.front();
        uint8_t id = serialize_header::getId(tmp);
        std::cout << "split"<<std::endl;
        if (id == NETWORK_SERVER_TO_CLIENT::POSITION) {
            std::cout << "position" << std::endl;
            dispatchToPositionQueue(tmp, network);
        } if (id == NETWORK_SERVER_TO_CLIENT::NEW_ENTITY) {
            std::cout << "new entity" << std::endl;
            dispatchToNewEntityQueue(tmp, network);
        }
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

