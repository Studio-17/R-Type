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
        ~PositionSystem();

        /**
         * @brief Function that will be automaticaly called while the client is working (on loop)
         * 
         * @param registry 
         * @param network 
         * @param position 
         * @param serverIds 
         */
        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cposition_t> &position, Sparse_array<component::cserverid_t> &serverIds);

    protected:
    private:
};

#endif /* !POSITIONSYSTEM_HPP_ */
