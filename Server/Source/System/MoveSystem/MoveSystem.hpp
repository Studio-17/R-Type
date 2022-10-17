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
#include "Component/CKilled.hpp"

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
         * @param registry 
         * @param netqueue 
         * @param direction 
         * @param position 
         * @param velocity 
         */
        void operator()(Registry &registry,
                        Sparse_array<component::cnetwork_queue_t> &netqueue,
                        Sparse_array<component::cdirection_t> &direction,
                        Sparse_array<component::cposition_t> &position,
                        Sparse_array<component::cvelocity_t> &velocity,
                        Sparse_array<component::ckilled_t> &killed);

        void sendKillEntityPacket(Registry &registry, int id, Sparse_array<component::cnetwork_queue_t> &netqueue);

    protected:

    private:
};

#endif /* !MOVESYSTEM_HPP_ */
