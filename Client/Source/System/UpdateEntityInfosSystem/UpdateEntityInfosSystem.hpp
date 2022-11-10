/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** UpdateEntityInfoSystem
*/

#ifndef UPDATEENTITYINFOSYSTEM_HPP_
    #define UPDATEENTITYINFOSYSTEM_HPP_

    #include "Registry.hpp"
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CHealth.hpp"
    #include "Component/CScore.hpp"
    #include "Component/CServerId.hpp"

/**
 * @brief Namespace for all components
 * 
 */
namespace System {
    /**
     * @brief Update entity info system class that handles the update of an entity
     * 
     */
    class UpdateEntityInfosSystem {
        public:
            UpdateEntityInfosSystem();
            ~UpdateEntityInfosSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             * 
             * @param registry The registry of the client
             * @param health The sparse array of health components
             * @param score The sparse array of score components
             * @param netQueue The sparse array of network entities
             */
            void operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::chealth_t> &health, Sparse_array<component::cscore_t> &score, Sparse_array<component::cnetwork_queue_t> &netQueue, Sparse_array<component::cserverid_t> &serverId);

        protected:
        private:
    };
}

#endif /* !UPDATEENTITYINFOSYSTEM_HPP_ */
