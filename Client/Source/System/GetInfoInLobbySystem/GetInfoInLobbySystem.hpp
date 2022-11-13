/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** GetInfoInLobbySystem
*/

#ifndef GETINFOINLOBBBYSYSTEM_HPP_
    #define GETINFOINLOBBBYSYSTEM_HPP_

    /* Ecs */
    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CRef.hpp"
    #include "Component/CText.hpp"

/**
 * @brief Namespace for systems
 *
 */
namespace System {
    /**
     * @brief GetInfoInLobbySystem class that handles the dynamic info of the entities
     *
     */
    class GetInfoInLobbySystem {
        public:
            /**
             * @brief Construct the Info In Lobby System object
             *
             */
            GetInfoInLobbySystem();
            /**
             * @brief Destroy the Get Info In Lobby System object
             * 
             */
            ~GetInfoInLobbySystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry The registry of the client
             * @param networkQueue The sparse array of network entities
             * @param refs The sparse array of ref entities
             * @param texts The sparse array of text entities
             */
            void operator()(
                Registry &registry,
                Sparse_array<component::cnetwork_queue_t> &netqueue,
                Sparse_array<component::cref_t> &refs,
                Sparse_array<component::ctext_t> &texts
            );

        protected:
        private:
    };
}

#endif /* !GETINFOINLOBBBYSYSTEM_HPP_ */
