/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** StartGameSystem
*/

#ifndef STARTGAMESYSTEM_HPP_
    #define STARTGAMESYSTEM_HPP_

    /* Ecs */
    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CLobbiesToEntities.hpp"
    #include "Component/CLobbyId.hpp"
    #include "Component/CNetIdToClientId.hpp"
    #include "Component/CPosition.hpp"
    #include "Component/CType.hpp"
    #include "Component/CLobbiesStatus.hpp"
    #include "Component/CHealth.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief System in charge of handle start of game
     */
    class StartGameSystem {
        public:
            /**
             * @brief Construct a new Start Game System object
             */
            StartGameSystem();
            ~StartGameSystem() = default;

            /**
             * @brief Create a Space Ship object
             *
             * @param registry The registry that contains all the ECS
             * @return Entity The new spaceShip entity
             */
            Entity createSpaceShip(Registry &registry, int lobbyId);

            /**
             * @brief The main handler for the StartGame System
             *
             * @param registry The registry that contains all the ECS
             * @param netqueue The sparse array of network entities
             * @param LobbyId The sparse array of lobbyId entities
             * @param netIdToClientId The sparse array of netIdToClientId entities
             * @param lobbiesToEntities The sparse array of lobbiesToEntities entities
             * @param position The sparse array of position entities
             * @param type The sparse array of type entities
             * @param lobbiesStatus The sparse array of lobbiesStatus entities
             */
            void operator()(
                Registry &registry,
                Sparse_array<component::cnetwork_queue_t> &netqueue,
                Sparse_array<component::clobby_id_t> &LobbyId,
                Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId,
                Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities,
                Sparse_array<component::cposition_t> &position,
                Sparse_array<component::ctype_t> &type,
                Sparse_array<component::clobbies_status_t> &lobbiesStatus
            );

        protected:
        private:
    };
}

#endif /* !STARTGAMESYSTEM_HPP_ */
