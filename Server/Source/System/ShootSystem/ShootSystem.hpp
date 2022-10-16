/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#ifndef R_TYPE_SHOOTSYSTEM_HPP
#define R_TYPE_SHOOTSYSTEM_HPP

#include "Registry.hpp"

#include "Component/CNetworkQueue.hpp"
#include "Component/CDamage.hpp"
#include "Component/CDirection.hpp"
#include "Component/CHitBox.hpp"
#include "Component/CPosition.hpp"

class ShootSystem {
    public:
        ShootSystem();

        ~ShootSystem() = default;

        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position);

        Entity createBullet(Registry &registry, Sparse_array<component::cposition_t> &position, uint16_t playerId);

    protected:

    private:
};

#endif //R_TYPE_SHOOTSYSTEM_HPP
