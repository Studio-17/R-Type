/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CNetworkQueue
*/

#ifndef CNETWORKQUEUE_HPP_
    #define CNETWORKQUEUE_HPP_

    #include <queue>

    #include "Move.hpp"
    #include "Shoot.hpp"
    #include "NewConnection.hpp"
    #include "Disconnection.hpp"
    #include "Lobbies.hpp"
    #include "StartGame.hpp"

using byte = unsigned char;

/**
 * @brief A namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the queue use by the ECS to send the request to the server
     */
    struct cnetwork_queue_t {
        std::queue<std::pair<int, std::vector<byte>>> receivedNetworkQueue; ///< Queue containing received vector of bytes representing request sent by the clients
        std::queue<std::pair<int, std::vector<byte>>> toSendNetworkQueue; ///< Queue containing vector of bytes representing request to send to clients

        std::queue<std::pair<int, packet_move>> moveQueue; ///< Queue containing move requests from clients
        std::queue<std::pair<int, packet_shoot>> shootQueue; ///< Queue containing shoot requests from clients
        std::queue<std::pair<int, packet_new_connection>> newPlayerQueue; ///< Queue containing new connection requests from clients
        std::queue<std::pair<int, packet_disconnection>> disconnectionQueue; ///< Queue containing disconnection requests from clients
        std::queue<std::pair<int, packet_join_lobby>> joinLobbyQueue; ///< Queue containing join lobby requests from clients
        std::queue<std::pair<int, packet_start_game>> startGameQueue; ///< Queue containing start game requests from clients
    };
}

#endif /* !CNETWORKQUEUE_HPP_ */
