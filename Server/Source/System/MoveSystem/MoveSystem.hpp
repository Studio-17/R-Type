/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** MoveSystem
*/

#ifndef MOVESYSTEM_HPP_
#define MOVESYSTEM_HPP_

#include "Registry.hpp"

#include "Component/CNetworkQueue.hpp"
#include "Component/CDirection.hpp"
#include "Component/CPosition.hpp"
#include "Component/CVelocity.hpp"
#include "Component/CTimer.hpp"

/**
 * @brief The Move System class, it handles all packets related to movement by the clients
 * 
 */
class MoveSystem {
    public:
        /**
         * @brief Construct a new Move System object
         * 
         */
        MoveSystem();

        /**
         * @brief Destroy the Move System object
         * 
         */
        ~MoveSystem() = default;

        /**
         * @brief The main handler for the Move System
         * 
         * @param registry the registry of the server
         * @param netqueue the sparse array of network entities
         * @param direction the sparse array of direction entities
         * @param position the sparse array of position entities
         * @param velocity the sparse array of velocity entities
         * @param killed the sparse array of killed entities
         * @param timer the sparse array of timer entities
         */
        void operator()(Registry &registry,
                        Sparse_array<component::cnetwork_queue_t> &netqueue,
                        Sparse_array<component::cdirection_t> &direction,
                        Sparse_array<component::cposition_t> &position,
                        Sparse_array<component::cvelocity_t> &velocity,
                        Sparse_array<component::ctimer_t> &timer);

        void sendKillEntityPacket(Registry &registry, uint16_t id, Sparse_array<component::cnetwork_queue_t> &netqueue);

    protected:

    private:
};

#endif /* !MOVESYSTEM_HPP_ */
