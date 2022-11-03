/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewEntitySystem
*/

#ifndef NEWENTITYSYSTEM_HPP_
    #define NEWENTITYSYSTEM_HPP_

    #include <string>
    #include <map>
    #include <utility>

    #include "Registry.hpp"
    #include "GraphicalLib.hpp"
    #include "CNetworkQueue.hpp"
    #include "CServerId.hpp"
    #include "Constant.hpp"
    #include "CRect.hpp"
    #include "CAsset.hpp"
    #include "NewEntity.hpp"
    #include "Serialization.hpp"
    #include "CClientNetworkId.hpp"

/**
 * @brief NewEntitySystem class that handles the creation of an entity
 * 
 */
class NewEntitySystem {
    public:
        /**
         * @brief Construct a new New Entity System object
         * 
         */
        NewEntitySystem();

        /**
         * @brief Destroy the New Entity System object
         * 
         */
        ~NewEntitySystem() = default;

        /**
         * @brief Function that will be automaticaly called while the client is working (on loop)
         * 
         * @param registry registry of the client
         * @param network the sparse array of network entities
         * @param serverIds the sparse array of serverId entities
         */
        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cserverid_t> &serverIds, Sparse_array<component::casset_t> &assets, Sparse_array<component::cclient_network_id> &clientNetwrokId);

        /**
         * @brief A method to add a new bullet entity
         * 
         * @param registry the registry of the client
         * @param packet_new_entity the packet containing the new entity
         */
        void addBullet(Registry &registry, packet_new_entity &packet_new_entity, Sparse_array<component::casset_t> &assets);

        /**
         * @brief A method to add a new ship entity
         * 
         * @param registry the registry of the client
         * @param packet_new_entity the packet containing the new entity
         */
        void addShip(Registry &registry, packet_new_entity &packet_new_entity, Sparse_array<component::casset_t> &assets, Sparse_array<component::cclient_network_id> &clientNetworkId);

        /**
         * @brief A method to add a new enemy entity
         * 
         * @param registry the registry of the client
         * @param packet_new_entity the packet containing the new entity
         */
        void addEnemy(Registry &registry, packet_new_entity &packet_new_entity, Sparse_array<component::casset_t> &assets);

        /**
         * @brief A method to check if an entity already exists
         * 
         * @param newEntityId the id of the new entity
         */
        void doesEntityAlreadyExist(int newEntityId);

    protected:
    private:
        std::unique_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
};

#endif /* !NEWENTITYSYSTEM_HPP_ */
