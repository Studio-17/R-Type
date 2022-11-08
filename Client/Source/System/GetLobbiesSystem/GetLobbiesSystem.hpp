/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** GetLobbiesSystem
*/

#ifndef GETLOBBIESSYSTEM_HPP_
    #define GETLOBBIESSYSTEM_HPP_

    #include "Registry.hpp"
    #include "CNetworkQueue.hpp"
    #include "CAsset.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief GetLobbiesSystem class that handles the request to send to Server to get lobbies
     */
    class GetLobbiesSystem {
        public:
            /**
             * @brief Get the Lobbies System object
             */
            GetLobbiesSystem();
            ~GetLobbiesSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry The registry of the client
             * @param networkQueue The sparse array of network entities
             */
            void operator()([[ maybe_unused ]]Registry &registry, Sparse_array<component::cnetwork_queue_t> &networkQueue, Sparse_array<component::casset_t> &assets);

            void createLobby(Registry &registry, packet_send_lobbies &lobbiesInfos, Sparse_array<component::casset_t> &assets);

        protected:
        private:
    };
}

#endif /* !GETLOBBIESSYSTEM_HPP_ */
