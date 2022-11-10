/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** SpawnEnemySystem
*/

#ifndef SPAWNENEMYSYSTEM_HPP_
    #define SPAWNENEMYSYSTEM_HPP_

    /* Ecs */
    #include "Registry.hpp"

    /* Components */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CPosition.hpp"
    #include "Component/CType.hpp"
    #include "Component/CTimer.hpp"
    #include "Component/CLobbiesStatus.hpp"
    #include "Component/CMap.hpp"

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
             * @param lobbiesStatus The sparse array of lobbies status entities
             * @param map The sparse array of map entities
             */
            void operator()(
                Registry &registry,
                Sparse_array<component::cnetwork_queue_t> &netqueue,
                Sparse_array<component::cposition_t> &position,
                Sparse_array<component::ctype_t> &type,
                Sparse_array<component::ctimer_t> &timer,
                Sparse_array<component::clobbies_status_t> &lobbiesStatus,
                Sparse_array<component::cmap_t> &map
            );

            /**
             * @brief Create a Enemy object
             *
             * @param registry The registry that contains all the ECS
             * @param map The sparse array of map entities
             * @return Entity The entity of the enemy
             */
            Entity createEnemy(Registry &registry, int lobby_id);

            /**
             * @brief Create a Enemy2 object
             *
             * @param registry The registry that contains all the ECS
             * @param map The sparse array of map entities
             * @return Entity The entity of the enemy
             */
            Entity createEnemy2(Registry &registry, int lobby_id);



        protected:
        private:
            enum MAPCONTENT {
                empty = '0',
                enemy = '1'
            };
    };
}

#endif /* !SPAWNENEMYSYSTEM_HPP_ */
