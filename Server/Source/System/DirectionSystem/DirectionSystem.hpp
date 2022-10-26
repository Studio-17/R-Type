/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** DirectionSystem
*/

#ifndef DIRECTIONSYSTEM_HPP_
    #define DIRECTIONSYSTEM_HPP_

#include "Registry.hpp"

#include "Component/CNetworkQueue.hpp"
#include "Component/CDirection.hpp"

/**
 * @brief The Direction System class, it handles all packets related to movement by the clients
 * 
 */
class DirectionSystem {
    public:
        /**
         * @brief Construct a new Direction System object
         * 
         */
        DirectionSystem();

        /**
         * @brief Destroy the Direction System object
         * 
         */
        ~DirectionSystem() = default;

        /**
         * @brief The main handler for the Direction System
         * 
         * @param registry the registry of the server
         * @param netqueue the sparse array of network entities
         * @param direction the sparse array of direction entities
         * @param position the sparse array of position entities
         * @param velocity the sparse array of velocity entities
         */
        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cdirection_t> &direction,Sparse_array<component::cposition_t> &position, Sparse_array<component::cvelocity_t> &velocity);

    protected:

    private:
};

#endif /* !DIRECTIONSYSTEM_HPP_ */