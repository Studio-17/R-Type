/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#ifndef R_TYPE_SHOOTSYSTEM_HPP
#define R_TYPE_SHOOTSYSTEM_HPP

#include "Registry.hpp"

// #include "Component/CNetworkQueue.hpp"

#include "Component/CDamage.hpp"
#include "Component/CDirection.hpp"
#include "Component/CHitBox.hpp"
#include "Component/CPosition.hpp"
#include "Component/CVelocity.hpp"

class ShootSystem {
    public:
        ShootSystem();

        ~ShootSystem() = default;

        void operator()(Registry &registry,
                        // Sparse_array<component::cnetwork_queue_t> &netqueue,
                        Sparse_array<component::cdamage_t> &damage,
                        Sparse_array<component::cdirection_t> &direction,
                        Sparse_array<component::chitbox_t> &hitbox,
                        Sparse_array<component::cposition_t> &position,
                        Sparse_array<component::cvelocity_t> &velocity);

    protected:

    private:
};

#endif //R_TYPE_SHOOTSYSTEM_HPP
