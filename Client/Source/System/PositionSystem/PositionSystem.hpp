/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** PositionSystem
*/

#ifndef POSITIONSYSTEM_HPP_
    #define POSITIONSYSTEM_HPP_

    #include "Registry.hpp"
    #include "CNetworkQueue.hpp"
    #include "CServerId.hpp"
    #include "CPosition.hpp"

/**
 * @brief PositionSystem class that handles the position of the entities
 * 
 */
class PositionSystem {
    public:
        /**
         * @brief Construct a new Position System object
         * 
         */
        PositionSystem();

        /**
         * @brief Destroy the Position System object
         * 
         */
        ~PositionSystem() = default;

        /**
         * @brief Function that will be automaticaly called while the client is working (on loop)
         * 
         * @param registry the registry of the server
         * @param network the sparse array of network entities
         * @param position the sparse array of position entities
         * @param serverIds the sparse array of server id entities
         * @param currScene the sparse array of current scene entities
         */
        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cposition_t> &position, Sparse_array<component::cserverid_t> &serverIds);

    protected:
    private:
};

#endif /* !POSITIONSYSTEM_HPP_ */
