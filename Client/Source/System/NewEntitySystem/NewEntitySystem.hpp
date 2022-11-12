/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewEntitySystem
*/

#ifndef NEWENTITYSYSTEM_HPP_
    #define NEWENTITYSYSTEM_HPP_

    #include <unordered_map>
    #include <string>

    /* Ecs */
    #include "Registry.hpp"

    /* Component */
    #include "Component/CAsset.hpp"
    #include "Component/CClientNetworkId.hpp"
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CSceneId.hpp"
    #include "Component/CServerId.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief NewEntitySystem class that handles the creation of an entity
     */
    class NewEntitySystem {
        public:
            /**
             * @brief Construct a new New Entity System object
             */
            NewEntitySystem();
            ~NewEntitySystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry The registry of the client
             * @param network The sparse array of network entities
             * @param serverIds The sparse array of server Id entities
             * @param assets The sparse array of asset entities
             * @param clientNetwrokId The sparse array of client network id entities
             * @param sceneId The sparse array of scene id entities
             */
            void operator()(
                Registry &registry,
                Sparse_array<component::cnetwork_queue_t> &network,
                Sparse_array<component::cserverid_t> &serverIds,
                Sparse_array<component::casset_t> &assets,
                Sparse_array<component::cclient_network_id> &clientNetwrokId,
                Sparse_array<component::csceneid_t> &sceneId
            );

            /**
             * @brief A method to add a new bullet entity
             *
             * @param registry The registry of the client
             * @param packet_new_entity The packet containing the new entity
             * @param assets The sparse array of asset id entities
             */
            void addBullet(Registry &registry, packet_new_entity &packet_new_entity, Sparse_array<component::casset_t> &assets);

            /**
             * @brief A method to add a new ship entity
             *
             * @param registry The registry of the client
             * @param packet_new_entity The packet containing the new entity
             * @param assets The sparse array of asset id entities
             * @param clientNetworkId The sparse array of client network id entities
             * @param sceneId The sparse array of scene id entities
             */
            void addShip(Registry &registry, packet_new_entity &packet_new_entity, Sparse_array<component::casset_t> &assets, Sparse_array<component::cclient_network_id> &clientNetworkId, Sparse_array<component::csceneid_t> &sceneId);

            /**
             * @brief A method to add a new enemy entity
             *
             * @param registry The registry of the client
             * @param packet_new_entity The packet containing the new entity
             * @param assets The sparse array of asset id entities
             */
            void addEnemy(Registry &registry, packet_new_entity &packet_new_entity, Sparse_array<component::casset_t> &assets);

            /**
             * @brief A method to add a new enemy entity
             *
             * @param registry The registry of the client
             * @param packet_new_entity The packet containing the new entity
             * @param assets The sparse array of asset id entities
             */
            void addEnemy2(Registry &registry, packet_new_entity &packet_new_entity, Sparse_array<component::casset_t> &assets);

            void addEnemy3(Registry &registry, packet_new_entity &packet_new_entity, Sparse_array<component::casset_t> &assets);

            /**
             * @brief A method to check if an entity already exists
             *
             * @param newEntityId The id of the new entity
             */
            void doesEntityAlreadyExist(int newEntityId);

        protected:
        private:
            std::unordered_map<int, std::string> _entityType; ///< Map of the entity type
    };
}

#endif /* !NEWENTITYSYSTEM_HPP_ */
