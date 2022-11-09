/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** EndGameSystem
*/

#include "EndGameSystem.hpp"
#include "Serialization.hpp"

/* Packet */
#include "Lobbies.hpp"

System::EndGameSystem::EndGameSystem()
{
}

void System::EndGameSystem::operator()([[ maybe_unused ]]Registry &registry, Sparse_array<component::cnetwork_queue_t> &network_queues, Sparse_array<component::csceneid_t> &sceneId)
{
    while (!network_queues[FORBIDDEN_IDS::NETWORK].value().endGameQueue.empty()) {
        sceneId[FORBIDDEN_IDS::NETWORK].value().sceneId = ROOMS;
        network_queues[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(serialize_header::serializeHeader<packet_join_lobby>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::JOIN_LOBBY, {0}));
        network_queues[FORBIDDEN_IDS::NETWORK].value().endGameQueue.pop();
    }
}
