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

NetworkSystem::~NetworkSystem()
{
}

void NetworkSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network)
{
    if (!network[FORBIDDEN_IDS::NETWORK].receivedNetworkQueue.empty()) {
        // Here parse and send to the corresponing queue
        std::vector<byte> &tmp = network[FORBIDDEN_IDS::NETWORK].receivedNetworkQueue.value().front();
        uint8_t id = serialize_header::getId(tmp);
    }

}

