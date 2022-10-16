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
         * @param registry 
         * @param netqueue 
         * @param position 
         */
        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position);

        /**
         * @brief Create a Enemy object
         * 
         * @param registry 
         * @return Entity 
         */
        Entity createEnemy(Registry &registry);

    protected:
    private:
        /**
         * @brief A boolean to notify that an enemy was created
         * 
         */
        bool _created;
};

#endif /* !SPAWNENEMYSYSTEM_HPP_ */
