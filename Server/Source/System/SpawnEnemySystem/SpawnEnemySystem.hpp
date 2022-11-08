/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** SpawnEnemySystem
*/

#ifndef SPAWNENEMYSYSTEM_HPP_
    #define SPAWNENEMYSYSTEM_HPP_

    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CPosition.hpp"
    #include "Component/CType.hpp"
    #include "Component/CTimer.hpp"
    #include "Component/CLobbiesStatus.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief The SpawnEnemy System class, it handles all packets related to the spawn of an enemy in the game
     */
    class SpawnEnemySystem {
        public:
            /**
             * @brief Construct a new Spawn Enemy System object
             */
            SpawnEnemySystem();
            ~SpawnEnemySystem() = default;

            /**
             * @brief The main handler for the SpawnEnemy System
             *
             * @param registry The registry that contains all the ECS
             * @param netqueue The sparse array of network entities
             * @param position The sparse array of position entities
             * @param type The sparse array of type entities
             * @param timer The sparse array of timer entities
             */
            void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position, Sparse_array<component::ctype_t> &type, Sparse_array<component::ctimer_t> &timer, Sparse_array<component::clobbies_status_t> &lobbiesStatus);

            /**
             * @brief Create a Enemy object
             *
             * @param registry The registry that contains all the ECS
             * @return Entity The entity of the enemy
             */
            Entity createEnemy(Registry &registry, int lobby_id);
        protected:
        private:
    };
}

#endif /* !SPAWNENEMYSYSTEM_HPP_ */
