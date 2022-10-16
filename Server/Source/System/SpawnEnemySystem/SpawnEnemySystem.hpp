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

class SpawnEnemySystem {
    public:
        SpawnEnemySystem();
        ~SpawnEnemySystem() = default;

        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position);

        Entity createEnemy(Registry &registry);

    protected:
    private:
        bool _created;
};

#endif /* !SPAWNENEMYSYSTEM_HPP_ */
