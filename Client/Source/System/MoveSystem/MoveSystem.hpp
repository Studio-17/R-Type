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
    #include "Component/CDirection.hpp"
    #include "Component/CPosition.hpp"
    #include "Component/CVelocity.hpp"
    #include "Component/CTimer.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief MoveSystem class that handles the movement of the entities
     */
    class MoveSystem {
        public:
            /**
             * @brief Construct a new Move System object
             */
            MoveSystem();
            ~MoveSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry The registry of the client
             * @param direction The sparse array of direction entities
             * @param position The sparse array of position entities
             * @param velocity The sparse array of velocity entities
             * @param timer The sparse array of timer entities
             */
            void operator()(Registry &registry,
                            Sparse_array<component::cdirection_t> &direction,
                            Sparse_array<component::cposition_t> &position,
                            Sparse_array<component::cvelocity_t> &velocity,
                            Sparse_array<component::ctimer_t> &timer);

        protected:
        private:
    };
}

#endif /* !MOVESYSTEM_HPP_ */
