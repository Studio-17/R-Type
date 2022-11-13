/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewLevelSystem
*/

#ifndef NEWLEVELSYSTEM_HPP_
    #define NEWLEVELSYSTEM_HPP_

    #include "Registry.hpp"
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CHealth.hpp"
    #include "Component/CScore.hpp"
    #include "Component/CServerId.hpp"
    #include "Component/CText.hpp"
    #include "Component/CRef.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief System to handle when a new level is reached
     */
    class NewLevelSystem {
        public:
            NewLevelSystem();
            ~NewLevelSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             * 
             * @param registry The registry of the client
             * @param netQueue The sparse array of network entities
             * @param sererId The sparse array of the serverIds
             * @param texts The sparse array of the texts
             * @param refs The sparse array of the refs
             */
            void operator()([[ maybe_unused ]] Registry &registry,
                            Sparse_array<component::cnetwork_queue_t> &netQueue,
                            Sparse_array<component::cserverid_t> &serverId,
                            Sparse_array<component::ctext_t> &texts,
                            Sparse_array<component::cref_t> &refs);


        protected:
        private:
    };
}

#endif /* !NEWLEVELSYSTEM_HPP_ */
