/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** SetNbPlayerInLobbySystem
*/

#ifndef SETNBPLAYERINLOBBYSYSTEM_HPP_
    #define SETNBPLAYERINLOBBYSYSTEM_HPP_

    /* Ecs */
    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief System that set number of player in Lobby
    */
    class SetNbPlayerInLobbySystem {
        public:
            /**
             * @brief Set the Nb Player In Lobby System object
             */
            SetNbPlayerInLobbySystem();
            ~SetNbPlayerInLobbySystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry Registry of the client
             * @param networkQueue The sparse array of network entities
             */
            void operator()(
                Registry &registry,
                Sparse_array<component::cnetwork_queue_t> &networkQueue
            );

        protected:
        private:
    };
}

#endif /* !SETNBPLAYERINLOBBYSYSTEM_HPP_ */
