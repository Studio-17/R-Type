/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CNetworkQueue
*/

#ifndef CNETWORKQUEUE_HPP_
#define CNETWORKQUEUE_HPP_

#include "KillEntity.hpp"
#include "Lobbies.hpp"
#include "NewConnection.hpp"
#include "Structures/NewEntity.hpp"
#include "Structures/Position.hpp"
#include <queue>

using byte = unsigned char;

/**
 * @brief A namespace for all components
 * 
 */
namespace component {
    /**
     * @brief A structure representing the queue use by the ECS to send the request to the server
     * 
     */
    typedef struct cnetwork_queue_s {
        std::queue<std::vector<byte>> toSendNetworkQueue;
        std::queue<std::vector<byte>> receivedNetworkQueue;
        std::queue<packet_new_entity> newEntityQueue;
        std::queue<packet_position> updatePositionQueue;
        std::queue<packet_nb_players_in_lobby> nbPlayerInLobbyQueue;
        std::queue<packet_kill_entity> killEntityQueue;
        std::queue<packet_send_lobbies> getLobbiesQueue;
        std::queue<packet_new_connection_response> newConnectionResponseQueue;
    } cnetwork_queue_t;
}

#endif /* !CNETWORKQUEUE_HPP_ */
