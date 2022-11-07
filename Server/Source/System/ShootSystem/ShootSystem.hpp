/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#ifndef R_TYPE_SHOOTSYSTEM_HPP
    #define R_TYPE_SHOOTSYSTEM_HPP

    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CDamage.hpp"
    #include "Component/CDirection.hpp"
    #include "Component/CHitBox.hpp"
    #include "Component/CPosition.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief The Shoot System class, it handles all packets related to a mouse click by the user, generating a bullet
     */
    class ShootSystem {
        public:
            /**
             * @brief Construct a new Shoot System object
             */
            ShootSystem();
            ~ShootSystem() = default;

            /**
             * @brief The main handler for the Shoot System
             *
             * @param registry The registry that contains all the ECS
             * @param netqueue The sparse array of network entities
             * @param position The sparse array of position entities
             */
            void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position);

            /**
             * @brief Create a Bullet object
             *
             * @param registry The registry that contains all the ECS
             * @param position The sparse array of position entities
             * @param playerId The id of the player who shot
             * @return Entity the bullet entity
             */
            Entity createBullet(Registry &registry, Sparse_array<component::cposition_t> &position, uint16_t playerId);

        protected:
        private:
    };
}

#endif //R_TYPE_SHOOTSYSTEM_HPP
