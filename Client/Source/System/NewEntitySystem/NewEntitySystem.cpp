/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewEntitySystem
*/

#include "NewEntitySystem.hpp"

#include "CPosition.hpp"
#include "CDirection.hpp"
#include "CVelocity.hpp"
#include "CAssetId.hpp"
#include "CSceneId.hpp"
#include "CScale.hpp"

NewEntitySystem::NewEntitySystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
    _entityType = {
        {7, "bullet"},
        {6, "enemy"},
        {1, "blueSpaceShip"}
    };
}

static bool findEntity(Sparse_array<component::cserverid_t> &serverIds, uint16_t idToFind)
{
    for (std::size_t id = 0; id != serverIds.size(); id++) {
        if (serverIds[id])
            if (serverIds[id].value().id == idToFind)
                return true;
    }
    return false;
}

void NewEntitySystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cserverid_t> &serverIds, Sparse_array<component::casset_t> &assets, Sparse_array<component::cclient_network_id> &clientNetworkId) {
    while (!network[FORBIDDEN_IDS::NETWORK].value().newEntityQueue.empty()) {
        packet_new_entity newEntity = network[FORBIDDEN_IDS::NETWORK].value().newEntityQueue.front();
        network[FORBIDDEN_IDS::NETWORK].value().newEntityQueue.pop();
        if (findEntity(serverIds, newEntity.id))
            continue;
        if (newEntity.type == ENTITY_TYPE::BULLET)
            addBullet(registry, newEntity, assets);
        if (newEntity.type == ENTITY_TYPE::ENEMY)
            addEnemy(registry, newEntity, assets);
        if (newEntity.type == ENTITY_TYPE::PLAYER)
            addShip(registry, newEntity, assets, clientNetworkId);
    }
}

void NewEntitySystem::addBullet(Registry &registry, packet_new_entity &newEntity, Sparse_array<component::casset_t> &assets)
{
    auto &asset = assets[FORBIDDEN_IDS::NETWORK]->assets;

    Entity bullet = registry.spawn_entity_with(
        component::cdirection_t{ .x = 1, .y = 0 },
        component::crect_t{ asset.at(_entityType.at(newEntity.type)).getRectangle() },
        component::cposition_t{ .x = static_cast<float>(newEntity.positionX), .y = static_cast<float>(newEntity.positionY) },
        component::cserverid_t{ .id = newEntity.id },
        component::cvelocity_t{ .velocity = 14 },
        component::cassetid_t{ .assets = _entityType.at(newEntity.type) },
        component::csceneid_t{ .sceneId = SCENE::GAME },
        component::cscale_t{ .scale = asset.at(_entityType.at(newEntity.type)).getScale() }
    );
}

void NewEntitySystem::addEnemy(Registry &registry, packet_new_entity &newEntity, Sparse_array<component::casset_t> &assets)
{
    auto &asset = assets[FORBIDDEN_IDS::NETWORK]->assets;

    Entity enemy = registry.spawn_entity_with(
        component::cdirection_t{ .x = -1, .y = 0 },
        component::crect_t{ asset.at(_entityType.at(newEntity.type)).getRectangle() },
        component::cposition_t{ .x = static_cast<float>(newEntity.positionX), .y = static_cast<float>(newEntity.positionY) },
        component::cserverid_t{ .id = newEntity.id },
        component::cvelocity_t{ .velocity = 4 },
        component::cassetid_t{ .assets = _entityType.at(newEntity.type) },
        component::csceneid_t{ .sceneId = SCENE::GAME },
        component::cscale_t{ .scale = asset.at(_entityType.at(newEntity.type)).getScale() }
    );
}

void NewEntitySystem::addShip(Registry &registry, packet_new_entity &newEntity, Sparse_array<component::casset_t> &assets, Sparse_array<component::cclient_network_id> &clientNetworkId) {

    // Make the ship controllable if the packet is destinated to you
    if (newEntity.clientId == clientNetworkId[FORBIDDEN_IDS::NETWORK].value().id) {
        std::cout << "New Entity System : Add Ship : Add ship as controllable for client number : " << newEntity.clientId << std::endl;
        clientNetworkId[FORBIDDEN_IDS::NETWORK].value().controllableNetworkEntityId = newEntity.id;
    }

    auto &asset = assets[FORBIDDEN_IDS::NETWORK]->assets;

    Entity enemy = registry.spawn_entity_with(
        component::cdirection_t{ .x = 0, .y = 0},
        component::crect_t{ asset.at(_entityType.at(newEntity.type)).getRectangle() },
        component::cposition_t{ .x = static_cast<float>(newEntity.positionX), .y = static_cast<float>(newEntity.positionY) },
        component::cserverid_t{ .id = newEntity.id },
        component::cvelocity_t{ .velocity = 4 },
        component::cassetid_t{ .assets = _entityType.at(newEntity.type) },
        component::csceneid_t{ .sceneId = SCENE::GAME },
        component::cscale_t{ .scale = asset.at(_entityType.at(newEntity.type)).getScale() }
    );
}
