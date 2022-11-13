/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** KillEntityTypeSystem
*/

#ifndef KILLENTITYTYPESYSTEM_HPP_
    #define KILLENTITYTYPESYSTEM_HPP_

    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CType.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief KillEntityTypeSystem class that handles the killing of entities type
     */
    class KillEntityTypeSystem {
        public:
            /**
             * @brief Construct a new Kill entity type System object
             */
            KillEntityTypeSystem();
            ~KillEntityTypeSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry The registry of the client
             * @param network The sparse array of network entities
             * @param type The sparse array of type entities
             * @param sounds The sparse array of sound entities
             */
            void operator()(Registry &registry,
                            Sparse_array<component::cnetwork_queue_t> &network,
                            Sparse_array<component::ctype_t> &type);

        protected:
        private:
    };
}

#endif /* !KILLENTITYTYPESYSTEM_HPP_ */
