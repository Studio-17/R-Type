/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#ifndef R_TYPE_HITSYSTEM_HPP
#define R_TYPE_HITSYSTEM_HPP

#include "Registry.hpp"

// #include "Component/CNetworkQueue.hpp"

#include "Component/CDamage.hpp"
#include "Component/CHealth.hpp"
#include "Component/CHitBox.hpp"
#include "Component/CPosition.hpp"

class HitSystem {
    public:
        HitSystem();

        ~HitSystem() = default;

        void operator()(Registry &registry,
                        // Sparse_array<component::cnetwork_queue_t> &netqueue,
                        Sparse_array<component::cdamage_t> &damage,
                        Sparse_array<component::chealth_t> &health,
                        Sparse_array<component::chitbox_t> &hitbox,
                        Sparse_array<component::cposition_t> &position);

    protected:

    private:
};

#endif //R_TYPE_HITSYSTEM_HPP
