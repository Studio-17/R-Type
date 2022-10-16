/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewPlayerSystem
*/

#include "NewPlayerSystem.hpp"

#include "Serialization.hpp"

#include "CDirection.hpp"
#include "CPosition.hpp"
#include "CVelocity.hpp"

#include "NewEntity.hpp"
#include "Game.hpp"

NewPlayerSystem::NewPlayerSystem()
{
}

void NewPlayerSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position)
{
    while (!netqueue[0]->newPlayerQueue.empty()) {
        packet_game newPlayer = netqueue[0]->newPlayerQueue.front();
        Entity spaceShip = createSpaceShip(registry);

        netqueue[0]->toSendNetworkQueue.push(serialize_header::serializeHeader<packet_new_entity>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_PLAYER, {spaceShip, position[spaceShip]->x, position[spaceShip]->y, 1, ENTITY_TYPE::PLAYER}));
        for (std::size_t index = 1; index != position.size(); index++) {
            if (index == spaceShip)
                continue;
            netqueue[0]->toSendNetworkQueue.push(serialize_header::serializeHeader<packet_new_entity>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_ENTITY, {(Entity)index, position[index]->x, position[index]->y, 1, ENTITY_TYPE::PLAYER}));
        }
        netqueue[0]->newPlayerQueue.pop();
    }
}

Entity NewPlayerSystem::createSpaceShip(Registry &registry)
{
    Entity spaceShip = registry.spawn_entity();

    component::cdirection_t direction = {0, 0};
    registry.add_component<component::cdirection_t>(registry.entity_from_index(spaceShip), std::move(direction));
    component::cposition_t position = {10, 10};
    registry.add_component<component::cposition_t>(registry.entity_from_index(spaceShip), std::move(position));
    component::cvelocity_t velocity = {10};
    registry.add_component<component::cvelocity_t>(registry.entity_from_index(spaceShip), std::move(velocity));
    return spaceShip;
}