/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NetworkSystem
*/

#ifndef NETWORKSYSTEM_HPP_
    #define NETWORKSYSTEM_HPP_

    /* Ecs */
    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CIdOfShip.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief NetworkSystem class that handles the communication using queues with the server to send it tasks as packets
     */
    class NetworkSystem {
        public:
            /**
             * @brief Construct a new Network System object
             */
            NetworkSystem();
            ~NetworkSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry The registry of the client
             * @param network The sparse array of network entities
             * @param idOfShip The sparse array of idOfShip entities
             */
            void operator()(
                Registry &registry,
                Sparse_array<component::cnetwork_queue_t> &network,
                Sparse_array<component::cid_of_ship_t> &idOfShip
            );

            /**
             * @brief A method to send informations to the position queue
             *
             * @param bytes The bytes to send
             * @param network The sparse array of network entities
             */
            void dispatchToPositionQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network);

            /**
             * @brief A method to send informations to the new entity queue
             *
             * @param bytes The bytes to send
             * @param network The sparse array of network entities
             */
            void dispatchToNewEntityQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network);

            /**
             * @brief A method to send informations to the kill entity queue
             *
             * @param bytes The bytes to send
             * @param network The sparse array of network entities
             */
            void dispatchToKillEntityQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network);

            /**
             * @brief A method to send informations to the kill entity type queue
             *
             * @param bytes The bytes to send
             * @param network The sparse array of network entities
             */
            void dispatchToKillEntityTypeQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network);

            /**
             * @brief A method to send informations to the get lobbies queue
             *
             * @param bytes The bytes to send
             * @param network The sparse array of network entities
             */
            void dispatchToGetLobbiesQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network);

            /**
             * @brief A method to send informations to the new player queue
             *
             * @param bytes The bytes to send
             * @param network The sparse array of network entities
             * @param idOfShip The sparse array of idOfShip entities
             */
            void handleNewPlayerAndDispatchToNewEntityQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cid_of_ship_t> &idOfShip);

            /**
             * @brief A method to send informations to the Nb Players in queue
             *
             * @param bytes The bytes to send
             * @param network The sparse array of network entities
             */
            void dispatchNbPlayersInLobbyQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network);

            /**
             * @brief A method to send informations to the network client id queue
             *
             * @param bytes The bytes to send
             * @param network The sparse array of network entities
             */
            void dispatchNetworkClientIdQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network);

            /**
             * @brief A method to send informations to the update entity health queue
             * 
             * @param bytes The bytes to send
             * @param network The sparse array of network entities
             */
            void dispatchUpdateEntityHealthQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network);

            /**
             * @brief A method to send informations to the update entity score queue
             * 
             * @param bytes The bytes to send
             * @param network The sparse array of network entities
             */
            void dispatchUpdateEntityScoreQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network);

            /**
             * @brief A method to send informations to the end Game queue
             *
             * @param bytes The bytes to send
             * @param network The sparse array of network entities
             */
            void dispatchEndGameQueue(std::vector<byte> &bytes, Sparse_array<component::cnetwork_queue_t> &network);

        protected:
        private:
    };
}

#endif /* !NETWORKSYSTEM_HPP_ */
