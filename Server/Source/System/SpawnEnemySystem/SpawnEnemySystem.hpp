/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** SpawnEnemySystem
*/

#ifndef SPAWNENEMYSYSTEM_HPP_
    #define SPAWNENEMYSYSTEM_HPP_

    #include <utility>
    #include <unordered_map>
    #include <functional>

    /* Ecs */
    #include "Registry.hpp"

    /* Components */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CPosition.hpp"
    #include "Component/CType.hpp"
    #include "Component/CTimer.hpp"
    #include "Component/CLobbiesStatus.hpp"
    #include "Component/CMap.hpp"

    /* Structure */
    #include "Structure/spec.hpp"

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
             * @brief Create an Enemy object from spec list load from config file
             *
             * @param registry The registry that contains all the ECS
             * @param enemyType The id of the enemy in the config list of spec
             * @param lobby_id The id of the lobby where spawn the entity
             * @param line The line number of the entity position in the spawn enemy map
             * @param map_size The number of line of the spawn enemy map
             * @return Entity The entity of the enemy
             */
            Entity createEnemyFromSpec(Registry &registry, int enemyType, int lobby_id, std::size_t line, std::size_t map_size);

        protected:
        private:
            /**
             * @brief Get the Json Data object from configuration file
             *
             * @param filepath Path to the configuration file
             * @return nlohmann::json Json data of the file
             */
            nlohmann::json getJsonData(std::string const &filepath);

            /**
             * @brief load spec assets from configuration file
             *
             * @param filepath Path to the configuration file
             */
            void loadAssets(std::string const &filepath);

            enum MAPCONTENT {
                EMPTY = '0',
                ENEMY1 = '1',
                ENEMY2 = '2',
                ENEMY3 = '3'
            }; ///< Enum representing the equivalent of a charater to his enemy
            std::pair<int, int> _mapDimension; ///< dimension of the screen
            std::unordered_map<MAPCONTENT, int> _entityCreator; ///< Map representing the spec index in enemySpec map to load enemy
            std::vector<spec_t> _enemySpec; ///< Vector of enemy spec to load enemy
    };
}

#endif /* !SPAWNENEMYSYSTEM_HPP_ */
