/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** KillSystem
*/

#ifndef KILLSYSTEM_HPP_
    #define KILLSYSTEM_HPP_

    #include <iostream>
    #include "Registry.hpp"
    #include "CNetworkQueue.hpp"
    #include "CServerId.hpp"
    #include "CSprite.hpp"
    #include "GraphicalLib.hpp"

/**
 * @brief KillSystem class that handles the killing of entities
 * 
 */
class KillSystem {
    public:
        /**
         * @brief Construct a new Kill System object
         * 
         */
        KillSystem();

        /**
         * @brief Destroy the Kill System object
         * 
         */
        ~KillSystem() = default;

        /**
         * @brief Function that will be automaticaly called while the client is working (on loop)
         * 
         * @param registry registry of the client
         * @param network the sparse array of network entities
         * @param serverId the sparse array of serverId entities
         */
        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cserverid_t> &serverId, Sparse_array<component::csprite_t> &sprites);

        /**
         * @brief A method to kill an entity
         * 
         * @param registry the registry of the client
         * @param id the id of the entity to kill
         * @param serverId the sparse array of serverId entities
         */
        void killEntity(Registry &registry, std::size_t id, Sparse_array<component::cserverid_t> &serverId, Sparse_array<component::csprite_t> &sprites);

    protected:
    private:
        std::unique_ptr<rtype::GraphicalLib> _graphicLib;
};

#endif /* !KILLSYSTEM_HPP_ */
