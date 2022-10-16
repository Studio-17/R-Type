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
    #include "NewEntity.hpp"
    #include "Serialization.hpp"

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
        ~NewEntitySystem();

        /**
         * @brief Function that will be automaticaly called while the client is working (on loop)
         * 
         * @param registry 
         * @param network 
         * @param serverIds 
         */
        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cserverid_t> &serverIds);

        /**
         * @brief A method to add a new bullet entity
         * 
         * @param registry 
         * @param packet_new_entity 
         */
        void addBullet(Registry &registry, packet_new_entity &packet_new_entity);

        /**
         * @brief A method to add a new ship entity
         * 
         * @param registry 
         * @param packet_new_entity 
         */
        void addShip(Registry &registry, packet_new_entity &packet_new_entity);

        /**
         * @brief A method to add a new enemy entity
         * 
         * @param registry 
         * @param packet_new_entity 
         */
        void addEnemy(Registry &registry, packet_new_entity &packet_new_entity);

        /**
         * @brief A method to check if an entity already exists
         * 
         * @param newEntityId 
         */
        void doesEntityAlreadyExist(int newEntityId);

    protected:
    private:
        std::unique_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
        std::map<ENTITY_TYPE, std::pair<std::string, component::crect_t>> _entityType; ///< Map of the entity type
};

#endif /* !NEWENTITYSYSTEM_HPP_ */
