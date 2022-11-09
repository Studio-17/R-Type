/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** HitboxSystem
*/

#ifndef HITBOXSYSTEM_HPP_
    #define HITBOXSYSTEM_HPP_

    /* Ecs */
    #include "Registry.hpp"

    /* Component */
    #include "Component/CType.hpp"
    #include "Component/CPosition.hpp"
    #include "Component/CRect.hpp"
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CHealth.hpp"
    #include "Component/CLobbyId.hpp"
    #include "Component/CScore.hpp"
    #include "Component/COwnerId.hpp"

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
            bool CheckCollision(component::crect_t const &rec1, component::crect_t const &rec2, component::cposition_t const &pos1, component::cposition_t const &pos2);

            /**
             * @brief The main handler for the Hitbox System
             *
             * @param registry The registry that contains all the ECS
             * @param network_queues The Sparse array of all network queue component of all entities
             * @param types The Sparse array of all type component of all entities
             * @param positions The Sparse array of all position component of all entities
             * @param rects The Sparse array of all rect component of all entities
             * @param healths The Sparse array of all health component of all entities
             * @param lobbyIds The Sparse array of all lobby id component of all entities
             * @param scores The Sparse array of all score component of all entities
             * @param ownerIds The Sparse array of all owner id component of all entities
             */
            void operator()(
                Registry &registry,
                Sparse_array<component::cnetwork_queue_t> &network_queues,
                Sparse_array<component::ctype_t> &types,
                Sparse_array<component::cposition_t> &positions,
                Sparse_array<component::crect_t> &rects,
                Sparse_array<component::chealth_t> &health,
                Sparse_array<component::clobby_id_t> &lobbyId,
                Sparse_array<component::cscore_t> &score,
                Sparse_array<component::ctype_t> &type,
                Sparse_array<component::cowner_id_t> &ownerId
            );

            /**
             * @brief A method to check if a collision happened between a player and a bullet
             *
             * @param registry The registry that contains all the ECS
             * @param netQueue The network queue of the player
             * @param health1 The health of entity one
             * @param health2 The health of entity two
             * @param lobbyId The lobby id
             * @param i The index of the entity one
             * @param x The index of the entity two
             */
            void doHealthCheck(Registry &registry, component::cnetwork_queue_t &netQueue, component::chealth_t &health1, component::chealth_t &health2, component::clobby_id_t &lobbyId, int i, int x);
            /**
             * @brief A method to check if a collision happened between a player and a bonus
             *
             * @param netQueue The network queue of the player
             * @param lobbyId The lobby id
             * @param scores The Sparse array of all score component of all entities
             * @param types The Sparse array of all type component of all entities
             * @param ownerIds The Sparse array of all owner id component of all entities
             * @param x The index of the entity one
             */
            void doScoreUpdate(component::cnetwork_queue_t &netQueue, component::clobby_id_t &lobbyId, Sparse_array<component::cscore_t> &score, Sparse_array<component::ctype_t> &type, Sparse_array<component::cowner_id_t> &ownerId, int x);

        protected:
        private:
    };
};

#endif /* !HITBOXSYSTEM_HPP_ */
