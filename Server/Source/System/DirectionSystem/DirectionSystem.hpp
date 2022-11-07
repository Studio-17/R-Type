/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** DirectionSystem
*/

#ifndef DIRECTIONSYSTEM_HPP_
    #define DIRECTIONSYSTEM_HPP_

    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CDirection.hpp"
    #include "Component/CPosition.hpp"
    #include "Component/CLobbyId.hpp"
    #include "Component/CNetIdToClientId.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief The Direction System class, it handles all packets related to movement by the clients
     */
    class DirectionSystem {
        public:
            /**
             * @brief Construct a new Direction System object
             */
            DirectionSystem();
            ~DirectionSystem() = default;

            /**
             * @brief The main handler for the Direction System
             *
             * @param registry The registry of the server
             * @param netqueue The sparse array of network entities
             * @param direction The sparse array of direction entities
             * @param position The sparse array of position entities
             * @param velocity The sparse array of velocity entities
             */
            void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cdirection_t> &direction, Sparse_array<component::cposition_t> &position, Sparse_array<component::cvelocity_t> &velocity, Sparse_array<component::clobby_id_t> &lobbyId, Sparse_array<component::cnet_id_to_client_id_t> &networkToClientId);

        protected:
        private:
    };
}

#endif /* !DIRECTIONSYSTEM_HPP_ */