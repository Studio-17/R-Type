/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CNetworkQueue
*/

#ifndef CNETWORKQUEUE_HPP_
    #define CNETWORKQUEUE_HPP_

    #include <queue>

    /* Packet */
    #include "NewEntity.hpp"
    #include "Structures/Position.hpp"
    #include "Lobbies.hpp"
    #include "KillEntity.hpp"
    #include "NewConnection.hpp"
    #include "UpdateEntityInfos.hpp"
    #include "EndGame.hpp"
    #include "UpdateEntityInfos.hpp"

using byte = unsigned char;

/**
 * @brief A namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the queue use by the ECS to send the request to the server
     */
    struct cnetwork_queue_t {
        std::queue<std::vector<byte>> receivedNetworkQueue; ///< Queue containing received vector of bytes representing request sent by the clients
        std::queue<std::vector<byte>> toSendNetworkQueue; ///< Queue containing vector of bytes representing request to send to clients

        std::queue<packet_new_entity> newEntityQueue; ///< Queue containing new entity requests from server
        std::queue<packet_position> updatePositionQueue; ///< Queue containing position requests from server
        std::queue<packet_nb_players_in_lobby> nbPlayerInLobbyQueue; ///< Queue containing number of players in lobby requests from server
        std::queue<packet_kill_entity> killEntityQueue; ///< Queue containing kill entity requests from server
        std::queue<packet_kill_entity_type> killEntityTypeQueue; ///< Queue containing kill entity type requests from server
        std::queue<packet_send_lobbies> getLobbiesQueue; ///< Queue containing send lobbies requests from server
        std::queue<packet_new_connection_response> newConnectionResponseQueue; ///< Queue containing new connection response requests from server
        std::queue<packet_update_entity_health> updateEntityHealthQueue; ///< Queue containing update entity healt requests from server
        std::queue<packet_update_entity_score> updateEntityScoreQueue; ///< Queue containing update entity score requests from server
        std::queue<packet_end_game> endGameQueue; ///< Queue containing end game requests from server
        std::queue<packet_update_entity_health> updateEntityHealthQueue; ///< Queue containing update entity healt requests from server
        std::queue<packet_update_entity_score> updateEntityScoreQueue; ///< Queue containing update entity score requests from server
    };
}

#endif /* !CNETWORKQUEUE_HPP_ */
