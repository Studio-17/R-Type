/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewEntitySystem
*/

#include "NewEntitySystem.hpp"

#include "CSprite.hpp"
// #include "CRect.hpp"
#include "CPosition.hpp"

NewEntitySystem::NewEntitySystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();

    _entityType[ENTITY_TYPE::PLAYER] = {"Assets/sprites/r-typesheet42.gif", {0, 0, 86, 33, 1, 5}};
    _entityType[ENTITY_TYPE::BULLET] = {"Assets/sprites/r-typesheet3.gif" , {0, 0, 18, 17, 1, 12}};
}

NewEntitySystem::~NewEntitySystem()
{
}

void NewEntitySystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cserverid_t> &serverIds)
{
    // Here check if the new entity queue is not empty and add the entity
    if (!network[FORBIDDEN_IDS::NETWORK]->newEntityQueue.empty()) {
        packet_new_entity newEntity = network[FORBIDDEN_IDS::NETWORK]->newEntityQueue.front();

        Entity bullet = registry.spawn_entity();

        component::crect_t rect = {_entityType.at(static_cast<ENTITY_TYPE>(newEntity.type)).second};
        registry.add_component<component::crect_t>(registry.entity_from_index(bullet), std::move(rect));

        component::csprite_t sprite = {.sprite = _graphicLib->createSprite(_entityType.at(static_cast<ENTITY_TYPE>(newEntity.type)).first, 1, (Rectangle){.x = rect.x, .y = rect.y, .width = rect.width, .height = rect.height})};
        registry.add_component<component::csprite_t>(registry.entity_from_index(bullet), std::move(sprite));

        component::cposition_t position = {.x = (float)newEntity.positionX, .y = (float)newEntity.positionY};
        registry.add_component<component::cposition_t>(registry.entity_from_index(bullet), std::move(position));

        component::cserverid_t serverId = {.id = newEntity.id};
        registry.add_component<component::cserverid_t>(registry.entity_from_index(bullet), std::move(serverId));

        network[FORBIDDEN_IDS::NETWORK]->newEntityQueue.pop();
    }
}
