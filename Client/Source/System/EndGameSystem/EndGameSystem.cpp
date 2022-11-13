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

void System::EndGameSystem::operator()([[ maybe_unused ]]Registry &registry, Sparse_array<component::cnetwork_queue_t> &network_queues, Sparse_array<component::csceneid_t> &sceneId, Sparse_array<component::cref_t> &refs)
{
    (void)refs;
    while (!network_queues[FORBIDDEN_IDS::NETWORK].value().endGameQueue.empty()) {
        registry.kill_entity(registry.entity_from_index(static_cast<std::size_t>(refs[FORBIDDEN_IDS::NETWORK].value().ref.at("score-spaceship-txt"))));
        registry.kill_entity(registry.entity_from_index(static_cast<std::size_t>(refs[FORBIDDEN_IDS::NETWORK].value().ref.at("health-spaceship-txt"))));
        sceneId[FORBIDDEN_IDS::NETWORK].value().sceneId = ENDGAME;
        network_queues[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(serialize_header::serializeHeader<packet_join_lobby>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::JOIN_LOBBY, {0}));
        network_queues[FORBIDDEN_IDS::NETWORK].value().endGameQueue.pop();
    }
}
