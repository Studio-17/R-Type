/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewEntitySystem
*/

#include "NewEntitySystem.hpp"

/* Serialization */
#include "Serialization.hpp"

/* Constant */
#include "Constant.hpp"

/* Packet */
#include "NewEntity.hpp"

/* Component */
#include "Component/CAssetId.hpp"
#include "Component/CDirection.hpp"
#include "Component/CPosition.hpp"
#include "Component/CScale.hpp"
#include "Component/CVelocity.hpp"
#include "Component/CType.hpp"
#include "Component/CHealth.hpp"
#include "Component/CScore.hpp"

System::NewEntitySystem::NewEntitySystem()
{
    _entityType = {
        {7, "bullet"},
        {6, "enemy"},
        {1, "blueSpaceShip"},
        {14, "amiral"},
        {16, "robot"}
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

void System::NewEntitySystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cserverid_t> &serverIds, Sparse_array<component::casset_t> &assets, Sparse_array<component::cclient_network_id> &clientNetworkId, Sparse_array<component::csceneid_t> &sceneId) {
    while (!network[FORBIDDEN_IDS::NETWORK].value().newEntityQueue.empty()) {
        packet_new_entity &newEntity = network[FORBIDDEN_IDS::NETWORK].value().newEntityQueue.front();
        if (findEntity(serverIds, newEntity.id))
            continue;
        if (newEntity.type == ENTITY_TYPE::BULLET)
            addBullet(registry, newEntity, assets);
        if (newEntity.type == ENTITY_TYPE::ENEMY)
            addEnemy(registry, newEntity, assets);
        if (newEntity.type == ENTITY_TYPE::PLAYER)
            addShip(registry, newEntity, assets, clientNetworkId, sceneId);
        if (newEntity.type == ENTITY_TYPE::ENEMY2)
            addEnemy2(registry, newEntity, assets);
        if (newEntity.type == ENTITY_TYPE::ENEMY3)
            addEnemy3(registry, newEntity, assets);
        network[FORBIDDEN_IDS::NETWORK].value().newEntityQueue.pop();
    }
}

void System::NewEntitySystem::addBullet(Registry &registry, packet_new_entity &newEntity, Sparse_array<component::casset_t> &assets)
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
        component::cscale_t{ .scale = asset.at(_entityType.at(newEntity.type)).getScale() },
        component::ctype_t{.type = ENTITY_TYPE::BULLET},
        component::chealth_t{newEntity.health},
        component::cscore_t{newEntity.score}
    );
}

void System::NewEntitySystem::addEnemy(Registry &registry, packet_new_entity &newEntity, Sparse_array<component::casset_t> &assets)
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
        component::cscale_t{ .scale = asset.at(_entityType.at(newEntity.type)).getScale() },
        component::ctype_t{.type = ENTITY_TYPE::ENEMY},
        component::chealth_t{newEntity.health},
        component::cscore_t{newEntity.score}
    );
}

void System::NewEntitySystem::addTextToEntity(Registry &registry, std::string const &ref, std::string const &content, std::pair<float, float> const &pos)
{
    Entity text = registry.spawn_entity_with(
        component::ctext_t{ .text = content, .font = "Assets/Fonts/Square.ttf", .spacing = 7 },
        component::cposition_t{ .x = pos.first , .y = pos.second },
        component::ctype_t{ .type = ENTITY_TYPE::TEXT },
        component::csceneid_t{ .sceneId = SCENE::GAME },
        component::cscale_t{ .scale = 40 },
        component::ccolor_t{ .color = {255, 255, 255, 255} },
        component::crefid_t{ .refId = ref }
    );
    std::cout << "Ref: " << ref << std::endl;
    Sparse_array<component::cref_t> &reference = registry.get_components<component::cref_t>();

    reference[FORBIDDEN_IDS::NETWORK].value().ref.insert({ref, registry.entity_from_index(static_cast<std::size_t>(text))});
}

void System::NewEntitySystem::addShip(Registry &registry, packet_new_entity &newEntity, Sparse_array<component::casset_t> &assets, Sparse_array<component::cclient_network_id> &clientNetworkId, Sparse_array<component::csceneid_t> &sceneId) {

    // Make the ship controllable if the packet is destinated to you
    if (newEntity.clientId == clientNetworkId[FORBIDDEN_IDS::NETWORK].value().id) {
        std::cout << "New Entity System : Add Ship : Add ship as controllable for client number : " << newEntity.clientId << std::endl;
        clientNetworkId[FORBIDDEN_IDS::NETWORK].value().controllableNetworkEntityId = newEntity.id;
    }

    auto &asset = assets[FORBIDDEN_IDS::NETWORK]->assets;

    sceneId[FORBIDDEN_IDS::NETWORK].value().sceneId = SCENE::GAME;

    Entity ship = registry.spawn_entity_with(
        component::cdirection_t{.x = 0, .y = 0},
        component::crect_t{asset.at(_entityType.at(newEntity.type)).getRectangle()},
        component::cposition_t{.x = static_cast<float>(newEntity.positionX), .y = static_cast<float>(newEntity.positionY)},
        component::cserverid_t{.id = newEntity.id},
        component::cvelocity_t{.velocity = 4},
        component::cassetid_t{.assets = _entityType.at(newEntity.type)},
        component::csceneid_t{.sceneId = SCENE::GAME},
        component::ctype_t{.type = ENTITY_TYPE::PLAYER},
        component::cscale_t{.scale = asset.at(_entityType.at(newEntity.type)).getScale()},
        component::chealth_t{newEntity.health},
        component::cscore_t{newEntity.score}
    );
    addTextToEntity(registry, "score-spaceship-txt", "Score: " + std::to_string(newEntity.score), {100, 100});
    addTextToEntity(registry, "health-spaceship-txt", "Lives: " + std::to_string(newEntity.health), {100, 200});

}

void System::NewEntitySystem::addEnemy2(Registry &registry, packet_new_entity &newEntity, Sparse_array<component::casset_t> &assets)
{
    auto &asset = assets[FORBIDDEN_IDS::NETWORK]->assets;

    std::cout << "Add enemy2 : " <<  _entityType.at(newEntity.type) << std::endl;

    Entity enemy = registry.spawn_entity_with(
        component::cdirection_t{ .x = -1, .y = 0 },
        component::crect_t{ asset.at(_entityType.at(newEntity.type)).getRectangle() },
        component::cposition_t{ .x = static_cast<float>(newEntity.positionX), .y = static_cast<float>(newEntity.positionY) },
        component::cserverid_t{ .id = newEntity.id },
        component::cvelocity_t{ .velocity = 4 },
        component::cassetid_t{ .assets = _entityType.at(newEntity.type) },
        component::csceneid_t{ .sceneId = SCENE::GAME },
        component::cscale_t{ .scale = asset.at(_entityType.at(newEntity.type)).getScale() },
        component::ctype_t{.type = ENTITY_TYPE::ENEMY},
        component::chealth_t{newEntity.health},
        component::cscore_t{newEntity.score}
    );
}

void System::NewEntitySystem::addEnemy3(Registry &registry, packet_new_entity &newEntity, Sparse_array<component::casset_t> &assets)
{
    auto &asset = assets[FORBIDDEN_IDS::NETWORK]->assets;

    std::cout << "Add enemy3 : " <<  _entityType.at(newEntity.type) << std::endl;

    Entity enemy = registry.spawn_entity_with(
        component::cdirection_t{ .x = -1, .y = 0 },
        component::crect_t{ asset.at(_entityType.at(newEntity.type)).getRectangle() },
        component::cposition_t{ .x = static_cast<float>(newEntity.positionX), .y = static_cast<float>(newEntity.positionY) },
        component::cserverid_t{ .id = newEntity.id },
        component::cvelocity_t{ .velocity = 10 },
        component::cassetid_t{ .assets = _entityType.at(newEntity.type) },
        component::csceneid_t{ .sceneId = SCENE::GAME },
        component::cscale_t{ .scale = asset.at(_entityType.at(newEntity.type)).getScale() },
        component::ctype_t{.type = ENTITY_TYPE::ENEMY},
        component::chealth_t{newEntity.health},
        component::cscore_t{newEntity.score}
    );

}
