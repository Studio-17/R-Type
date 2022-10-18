/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** HitboxSystem
*/

#ifndef HITBOXSYSTEM_HPP_
    #define HITBOXSYSTEM_HPP_

    #include "Registry.hpp"
    #include "CType.hpp"
    #include "CPosition.hpp"
    #include "CRect.hpp"
    #include "CNetworkQueue.hpp"
    #include "CKilled.hpp"

/**
 * @brief Namespace for systems
 * 
 */
namespace System {
    /**
     * @brief The Hitbox System class, it handles everything related to collisions between entities
     * 
     */
    class HitboxSystem {
        public:
            /**
             * @brief Construct a new Hitbox System object
             * 
             */
            HitboxSystem();
            /**
             * @brief Destroy the Event System object
             * 
             */
            ~HitboxSystem() = default;

            /**
             * @brief A method to check if a collision happened
             * 
             * @param rec1 the first rectangle
             * @param rec2 the second rectangle
             * @param pos1 the first position
             * @param pos2 the second position
             * @return true if a collision happened
             * @return false if no collision happened
             */
            bool CheckCollision(std::optional<component::crect_t> &rec1, std::optional<component::crect_t> &rec2, std::optional<component::cposition_t> &pos1, std::optional<component::cposition_t> &pos2);

            /**
             * @brief The main handler for the Hitbox System
             * 
             * @param registry The registry that contains all the ECS
             * @param network_queues Sparse array of all network queue component of all entities
             * @param types Sparse array of all type component of all entities
             * @param positions Sparse array of all position component of all entities
             * @param rects Sparse array of all rect component of all entities
             * @param killed Sparse array of all killed component of all entities
             */
            void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network_queues,
                                                Sparse_array<component::ctype_t> &types,
                                                Sparse_array<component::cposition_t> &positions,
                                                Sparse_array<component::crect_t> &rects,
                                                Sparse_array<component::ckilled_t> &killed);


        protected:
        private:
    };
};

#endif /* !HITBOXSYSTEM_HPP_ */
