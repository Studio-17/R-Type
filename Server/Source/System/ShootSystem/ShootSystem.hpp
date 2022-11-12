/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#ifndef R_TYPE_SHOOTSYSTEM_HPP
    #define R_TYPE_SHOOTSYSTEM_HPP

    /* Ecs */
    #include "Registry.hpp"

    /* Components */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CDamage.hpp"
    #include "Component/CDirection.hpp"
    #include "Component/CHitBox.hpp"
    #include "Component/CPosition.hpp"
    #include "Component/CLobbyId.hpp"
    #include "Component/CNetIdToClientId.hpp"
    #include "Component/CHealth.hpp"

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
             * @param lobbyId The sparse array of lobby id entities
             * @param netIdToClientId The sparse array of net id to client id entities
             */
            void operator()(
                Registry &registry,
                Sparse_array<component::cnetwork_queue_t> &netqueue,
                Sparse_array<component::cposition_t> &position,
                Sparse_array<component::clobby_id_t> &lobbyId,
                Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId,
                Sparse_array<component::chealth_t> &health
            );

            /**
             * @brief Create a Bullet object
             *
             * @param registry The registry that contains all the ECS
             * @param position The sparse array of position entities
             * @param playerId The id of the player who shot
             * @param lobbyId The id of the lobby
             * @return Entity the bullet entity
             */
            Entity createBullet(Registry &registry, Sparse_array<component::cposition_t> &position, uint16_t playerId, int lobbyId);

        protected:
        private:
    };
}

#endif //R_TYPE_SHOOTSYSTEM_HPP
