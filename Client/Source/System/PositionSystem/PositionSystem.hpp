/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** PositionSystem
*/

#ifndef POSITIONSYSTEM_HPP_
    #define POSITIONSYSTEM_HPP_

    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CPosition.hpp"
    #include "Component/CServerId.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief PositionSystem class that handles the position of the entities
     */
    class PositionSystem {
        public:
            /**
             * @brief Construct a new Position System object
             */
            PositionSystem();
            ~PositionSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry The registry of the server
             * @param network The sparse array of network entities
             * @param position The sparse array of position entities
             * @param serverIds The sparse array of server id entities
             */
            void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cposition_t> &position, Sparse_array<component::cserverid_t> &serverIds);

        protected:
        private:
    };
}

#endif /* !POSITIONSYSTEM_HPP_ */
