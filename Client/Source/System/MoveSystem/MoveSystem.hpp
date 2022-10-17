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
         * @brief Function that will be automaticaly called while the client is working (on loop)
         * 
         * @param registry 
         * @param netqueue 
         * @param direction 
         * @param position 
         * @param velocity 
         */
        void operator()(Registry &registry,
                        Sparse_array<component::cdirection_t> &direction,
                        Sparse_array<component::cposition_t> &position,
                        Sparse_array<component::cvelocity_t> &velocity,
                        Sparse_array<component::ckilled_t> &killed);

    protected:

    private:
};

#endif /* !MOVESYSTEM_HPP_ */
