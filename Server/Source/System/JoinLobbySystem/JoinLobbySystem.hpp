/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** JoinLobbySystem
*/

#ifndef JOINLOBBYSYSTEM_HPP_
    #define JOINLOBBYSYSTEM_HPP_

    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CLobbyId.hpp"
    #include "Component/CLobbiesToEntities.hpp"
    #include "Component/CNetIdToClientId.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief The Join Lobby System class, it handles all packets related to lobby join by the clients
     */
    class JoinLobbySystem {
        public:
            /**
             * @brief Construct a new Join Lobby System object
             */
            JoinLobbySystem();
            ~JoinLobbySystem() = default;

            /**
             * @brief The main handler for the JoinLobby System
             *
             * @param registry The registry of the server
             * @param networkQueue The sparse array of network entities
             * @param lobbyId The sparse array of lobbyId entities
             * @param lobbiesToEntities The sparse array of lobbiesToEntities entities
             * @param netIdToClientId The sparse array of netIdToClientId entities
             */
            void operator()([[ maybe_unused ]]Registry &registry, Sparse_array<component::cnetwork_queue_t> &networkQueue, Sparse_array<component::clobby_id_t> &lobbyId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId);

            /**
             * @brief Function to change client Lobby
             *
             * @param netClientId The sparse array of netClientId entities
             * @param newLobbyId The sparse array of newLobbyId entities
             * @param lobbyId The sparse array of lobbyId entities
             * @param lobbiesToEntities The sparse array of lobbiesToEntities entities
             * @param netIdToClientId The sparse array of netIdToClientId entities
             */
            void changeClientLobby(int netClientId, int newLobbyId, Sparse_array<component::clobby_id_t> &lobbyId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId);

        protected:
        private:
    };
}

#endif /* !JOINLOBBYSYSTEM_HPP_ */
