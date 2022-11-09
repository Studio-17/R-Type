/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** GetLobbiesSystem
*/

#ifndef GETLOBBIESSYSTEM_HPP_
    #define GETLOBBIESSYSTEM_HPP_

    /* Ecs */
    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CRef.hpp"
    #include "Component/CText.hpp"

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
             * @brief Construct the Lobbies System object
             */
            GetLobbiesSystem();
            ~GetLobbiesSystem() = default;

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
                Sparse_array<component::cnetwork_queue_t> &networkQueue,
                Sparse_array<component::cref_t> &refs,
                Sparse_array<component::ctext_t> &texts
            );

        protected:
        private:
    };
}

#endif /* !GETLOBBIESSYSTEM_HPP_ */
