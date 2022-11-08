/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** MoveSystem
*/

#ifndef MOVESYSTEM_HPP_
    #define MOVESYSTEM_HPP_

    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CDirection.hpp"
    #include "Component/CPosition.hpp"
    #include "Component/CVelocity.hpp"
    #include "Component/CTimer.hpp"
    #include "Component/CLobbyId.hpp"
    #include "Component/CLobbiesStatus.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief The Move System class, it handles all packets related to movement by the clients
     */
    class MoveSystem {
        public:
            /**
             * @brief Construct a new Move System object
             */
            MoveSystem();
            ~MoveSystem() = default;

            /**
             * @brief The main handler for the Move System
             *
             * @param registry The registry of the server
             * @param netqueue The sparse array of network entities
             * @param direction The sparse array of direction entities
             * @param position The sparse array of position entities
             * @param velocity The sparse array of velocity entities
             * @param timer The sparse array of timer entities
             */
            void operator()(Registry &registry,
                            Sparse_array<component::cnetwork_queue_t> &netqueue,
                            Sparse_array<component::cdirection_t> &direction,
                            Sparse_array<component::cposition_t> &position,
                            Sparse_array<component::cvelocity_t> &velocity,
                            Sparse_array<component::ctimer_t> &timer,
                            Sparse_array<component::clobby_id_t> &LobbyId,
                            Sparse_array<component::clobbies_status_t> &lobbiesStatus);

            /**
             * @brief Function to add send packet to send network queue
             *
             * @param registry The registry of the server
             * @param id The id of the killed entity
             * @param netqueue The sparse array of network entities
             */
            void sendKillEntityPacket(Registry &registry, uint16_t id, Sparse_array<component::cnetwork_queue_t> &netqueue);

        protected:
        private:
    };
}

#endif /* !MOVESYSTEM_HPP_ */
