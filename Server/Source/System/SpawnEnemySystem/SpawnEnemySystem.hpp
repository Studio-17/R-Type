/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** SpawnEnemySystem
*/

#ifndef SPAWNENEMYSYSTEM_HPP_
    #define SPAWNENEMYSYSTEM_HPP_

    #include "Registry.hpp"

    #include "Component/CNetworkQueue.hpp"
    #include "Component/CPosition.hpp"
    #include "Component/CType.hpp"
    #include "CTimer.hpp"

/**
 * @brief The SpawnEnemy System class, it handles all packets related to the spawn of an enemy in the game
 * 
 */
class SpawnEnemySystem {
    public:
        /**
         * @brief Construct a new Spawn Enemy System object
         * 
         */
        SpawnEnemySystem();

        /**
         * @brief Destroy the Spawn Enemy System object
         * 
         */
        ~SpawnEnemySystem() = default;

        /**
         * @brief The main handler for the SpawnEnemy System
         * 
         * @param registry the registry of the server
         * @param netqueue the sparse array of network entities
         * @param position the sparse array of position entities
         */
        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position, Sparse_array<component::ctype_t> &type, Sparse_array<component::ctimer_t> &timer);

        /**
         * @brief Create a Enemy object
         * 
         * @param registry the registry of the server
         * @return Entity the entity of the enemy
         */
        Entity createEnemy(Registry &registry);

    protected:
    private:
        bool _created; ///< Boolean that indicates if the enemy has been created
};

#endif /* !SPAWNENEMYSYSTEM_HPP_ */
