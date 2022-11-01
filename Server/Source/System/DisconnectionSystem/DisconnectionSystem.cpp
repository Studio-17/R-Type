/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** DisconnectionSystem
*/

#include "DisconnectionSystem.hpp"
#include "Serialization.hpp"
#include "Constant.hpp"
#include "KillEntity.hpp"

DisconnectionSystem::DisconnectionSystem()
{
}

void DisconnectionSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network_queues)
{
    if (network_queues[FORBIDDEN_IDS::NETWORK]) {
        while (!network_queues[FORBIDDEN_IDS::NETWORK].value().disconnectionQueue.empty()) {
            packet_disconnection packet = network_queues[FORBIDDEN_IDS::NETWORK].value().disconnectionQueue.front();
            network_queues[FORBIDDEN_IDS::NETWORK].value().disconnectionQueue.pop();
            network_queues[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({0, serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, {static_cast<int>(packet.disconnection)})});
            registry.kill_entity(registry.entity_from_index(packet.disconnection));
        }
    }
}
