/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** KillSystem
*/

#ifndef KILLSYSTEM_HPP_
    #define KILLSYSTEM_HPP_

    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CServerId.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief KillSystem class that handles the killing of entities
     */
    class KillSystem {
        public:
            /**
             * @brief Construct a new Kill System object
             */
            KillSystem();
            ~KillSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry The registry of the client
             * @param network The sparse array of network entities
             * @param serverId The sparse array of serverId entities
             */
            void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cserverid_t> &serverId);

            /**
             * @brief A method to kill an entity
             *
             * @param registry The registry of the client
             * @param id The id of the entity to kill
             * @param serverId The sparse array of serverId entities
             */
            void killEntity(Registry &registry, std::size_t id, Sparse_array<component::cserverid_t> &serverId);

        protected:
        private:
    };
}

#endif /* !KILLSYSTEM_HPP_ */
