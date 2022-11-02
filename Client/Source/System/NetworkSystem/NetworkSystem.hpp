/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NetworkSystem
*/

#ifndef NETWORKSYSTEM_HPP_
    #define NETWORKSYSTEM_HPP_

    #include "Registry.hpp"
    #include "CNetworkQueue.hpp"
    #include "CIdOfShip.hpp"

/**
 * @brief NetworkSystem class that handles the communication using queues with the server to send it tasks as packets
 * 
 */
class NetworkSystem {
    public:
        /**
         * @brief Construct a new Network System object
         * 
         */
        NetworkSystem();
        /**
         * @brief Destroy the Network System object
         * 
         */
        ~NetworkSystem() = default;

        /**
         * @brief Function that will be automaticaly called while the client is working (on loop)
         * 
         * @param registry registry of the client
         * @param network the sparse array of network entities
         * @param idOfShip the sparse array of idOfShip entities
         */
        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cid_of_ship_t> &idOfShip);

        /**
         * @brief A method to send informations to the position queue
         * 
         * @param bytes the bytes to send
         * @param network the sparse array of network entities
         */
        void dispatchToPositionQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network);

        /**
         * @brief A method to send informations to the new entity queue
         * 
         * @param bytes the bytes to send
         * @param network the sparse array of network entities
         */
        void dispatchToNewEntityQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network);

        /**
         * @brief A method to send informations to the kill entity queue
         * 
         * @param bytes the bytes to send
         * @param network the sparse array of network entities
         */
        void dispatchToKillEntityQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network);

        /**
         * @brief A method to send informations to the get lobbies queue
         * 
         * @param bytes the bytes to send
         * @param network the sparse array of network entities
         */
        void dispatchToGetLobbiesQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network);

        /**
         * @brief A method to send informations to the new player queue
         * 
         * @param bytes the bytes to send
         * @param network the sparse array of network entities
         * @param idOfShip the sparse array of idOfShip entities
         */
        void handleNewPlayerAndDispatchToNewEntityQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cid_of_ship_t> &idOfShip);

        /**
         * @brief A method to send informations to the Nb Players in queue
         * 
         * @param bytes the bytes to send
         * @param network the sparse array of network entities
         */
        void dispatchNbPlayersInLobbyQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network);

    protected:
    private:
};

#endif /* !NETWORKSYSTEM_HPP_ */
