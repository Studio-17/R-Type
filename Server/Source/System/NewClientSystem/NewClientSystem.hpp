/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** NewClientSystem
*/

#ifndef NEWCLIENTSYSTEM_HPP_
    #define NEWCLIENTSYSTEM_HPP_

    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetIdToClientId.hpp"
    #include "Component/CNetworkId.hpp"
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CLobbiesToEntities.hpp"
    #include "Component/CNetworkQueue.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief NewClientSystem class that handles the new client
     */
    class NewClientSystem {
        public:
            /**
             * @brief Construct a new New Client System object
             */
            NewClientSystem();
            ~NewClientSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry Registry of the client
             * @param netqueue The sparse array of network entities
             * @param netIdToClientId The sparse array of netIdToClientId entities
             * @param lobbiesToEntities The sparse array of lobbiesToEntities entities
             */
            void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities);

            /**
             * @brief Function that send lobbies status to network queue
             *
             * @param clientId The sparse array of clientId entities
             * @param networkQueue The sparse array of network entities
             * @param lobbiesToEntities The sparse array of lobbiesToEntities entities
             */
            void sendLobbiesStatus(int clientId, Sparse_array<component::cnetwork_queue_t> &networkQueue, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities);
        protected:
        private:
    };
}

#endif /* !NEWCLIENTSYSTEM_HPP_ */
