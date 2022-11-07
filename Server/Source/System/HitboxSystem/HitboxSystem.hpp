/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** HitboxSystem
*/

#ifndef HITBOXSYSTEM_HPP_
    #define HITBOXSYSTEM_HPP_

    #include "Registry.hpp"

    /* Component */
    #include "Component/CType.hpp"
    #include "Component/CPosition.hpp"
    #include "Component/CRect.hpp"
    #include "Component/CNetworkQueue.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief The Hitbox System class, it handles everything related to collisions between entities
     */
    class HitboxSystem {
        public:
            /**
             * @brief Construct a new Hitbox System object
             */
            HitboxSystem();
            ~HitboxSystem() = default;

            /**
             * @brief A method to check if a collision happened
             *
             * @param rec1 The first rectangle
             * @param rec2 The second rectangle
             * @param pos1 The first position
             * @param pos2 The second position
             * @return true If a collision happened
             * @return false If no collision happened
             */
            bool CheckCollision(std::optional<component::crect_t> &rec1, std::optional<component::crect_t> &rec2, std::optional<component::cposition_t> &pos1, std::optional<component::cposition_t> &pos2);

            /**
             * @brief The main handler for the Hitbox System
             *
             * @param registry The registry that contains all the ECS
             * @param network_queues The Sparse array of all network queue component of all entities
             * @param types The Sparse array of all type component of all entities
             * @param positions The Sparse array of all position component of all entities
             * @param rects The Sparse array of all rect component of all entities
             */
            void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network_queues,
                                                Sparse_array<component::ctype_t> &types,
                                                Sparse_array<component::cposition_t> &positions,
                                                Sparse_array<component::crect_t> &rects);


        protected:
        private:
    };
};

#endif /* !HITBOXSYSTEM_HPP_ */
