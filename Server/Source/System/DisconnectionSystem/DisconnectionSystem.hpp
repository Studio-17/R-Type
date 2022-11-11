/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** DisconnectionSystem
*/

#ifndef DISCONNECTIONSYSTEM_HPP_
    #define DISCONNECTIONSYSTEM_HPP_

    /* Ecs */
    #include "Registry.hpp"

    /* Component*/
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CLobbyId.hpp"
    #include "Component/CLobbiesToEntities.hpp"
    #include "Component/CNetIdToClientId.hpp"
    #include "Component/CDisconnected.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief The Disconnection System class, it handles disconnection of a client
     */
    class DisconnectionSystem {
        public:
            /**
             * @brief Construct a new Disconnection System object
             */
            DisconnectionSystem();
            ~DisconnectionSystem() = default;

            /**
             * @brief The main handler for the Disconnection System
             *
             * @param registry The registry of the server
             * @param network_queues The sparse array of network entities
             * @param lobbyId The sparse array of lobbyId entities
             * @param lobbiesToEntities The sparse array of lobbiesToEntities entities
             * @param netIdToClientId The sparse array of netIdToClientId entities
             * @param disconnected The sparse array of disconnected entities
             */
            void operator()(
                Registry &registry,
                Sparse_array<component::cnetwork_queue_t> &network_queues,
                Sparse_array<component::clobby_id_t> &lobbyId,
                Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities,
                Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId,
                Sparse_array<component::cdisconnected_t> &disconnected
            );

        protected:
        private:
    };
}

#endif /* !DISCONNECTIONSYSTEM_HPP_ */
