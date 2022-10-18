/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** MoveSystem
*/

#ifndef MOVESYSTEM_HPP_
#define MOVESYSTEM_HPP_

#include "Registry.hpp"

#include "CNetworkQueue.hpp"
#include "CDirection.hpp"
#include "CPosition.hpp"
#include "CVelocity.hpp"
#include "CKilled.hpp"
#include "CTimer.hpp"

/**
 * @brief MoveSystem class that handles the movement of the entities
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
         * @param direction the sparse array of direction entities
         * @param position the sparse array of position entities
         * @param velocity the sparse array of velocity entities
         * @param killed the sparse array of killed entities
         * @param timer the sparse array of timer entities
         */
        void operator()(Registry &registry,
                        Sparse_array<component::cdirection_t> &direction,
                        Sparse_array<component::cposition_t> &position,
                        Sparse_array<component::cvelocity_t> &velocity,
                        Sparse_array<component::ckilled_t> &killed,
                        Sparse_array<component::ctimer_t> &timer);

    protected:

    private:
};

#endif /* !MOVESYSTEM_HPP_ */
