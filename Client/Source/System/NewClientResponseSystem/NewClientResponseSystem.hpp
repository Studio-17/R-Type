/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewClientResponseSystem
*/

#ifndef NEWCLIENTRESPONSESYSTEM_HPP_
    #define NEWCLIENTRESPONSESYSTEM_HPP_

    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CClientNetworkId.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief NewClientResponseSystem class that handles the creation of a client
     */
    class NewClientResponseSystem {
        public:
            /**
             * @brief Construct a new New Client Response System object
             */
            NewClientResponseSystem();
            ~NewClientResponseSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry The registry of the client
             * @param network The sparse array of network entities
             * @param clientNetworkId The sparse array of client network id entities
             */
            void operator()([[ maybe_unused ]]Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cclient_network_id> &clientNetworkId);

        protected:
        private:
    };
}

#endif /* !NEWCLIENTRESPONSESYSTEM_HPP_ */
