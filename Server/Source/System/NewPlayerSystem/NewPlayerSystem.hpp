/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewPlayerSystem
*/

#ifndef NEWPLAYERSYSTEM_HPP_
    #define NEWPLAYERSYSTEM_HPP_

    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CPosition.hpp"
    #include "Component/CType.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief NewPlayerSystem class that handles the new player
     */
    class NewPlayerSystem {
        public:
            /**
             * @brief Construct a new New Player System object
             */
            NewPlayerSystem();
            ~NewPlayerSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry Registry of the client
             * @param netqueue The sparse array of network entities
             * @param position The sparse array of position entities
             * @param type The sparse array of type entities
             */
            void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position, Sparse_array<component::ctype_t> &type);

        protected:
        private:
            /**
             * @brief Create a Space Ship object
             *
             * @param registry Registry of the client
             * @return Entity The entity of the spaceShip
             */
            Entity createSpaceShip(Registry &registry);
    };
}

#endif /* !NEWPLAYERSYSTEM_HPP_ */
