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
#include "CRect.hpp"

#include "NewEntity.hpp"

NewPlayerSystem::NewPlayerSystem()
{
}

void NewPlayerSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position, Sparse_array<component::ctype_t> &type, Sparse_array<component::ckilled_t> &killed)
{
    while (!netqueue[0]->newPlayerQueue.empty()) {
        Entity spaceShip = createSpaceShip(registry);

        // std::cout <<"[SERVER] adding new player" << std::endl;
        netqueue[0]->toSendNetworkQueue.push(serialize_header::serializeHeader<packet_new_entity>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_PLAYER, {spaceShip, position[spaceShip]->x, position[spaceShip]->y, 1, type[spaceShip]->type}));
        for (std::size_t index = 1; index != position.size(); index++) {
            if (index == spaceShip || killed[index]->isDead)
                continue;
            netqueue[0]->toSendNetworkQueue.push(serialize_header::serializeHeader<packet_new_entity>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_ENTITY, {(Entity)index, position[index]->x, position[index]->y, 1, type[index]->type}));
        }
        netqueue[0]->newPlayerQueue.pop();
    }
}

Entity NewPlayerSystem::createSpaceShip(Registry &registry)
{
    Entity spaceShip = registry.spawn_entity();

    registry.add_component<component::cdirection_t>(registry.entity_from_index(spaceShip), {0, 0});
    registry.add_component<component::cposition_t>(registry.entity_from_index(spaceShip), {10, 10});
    registry.add_component<component::cvelocity_t>(registry.entity_from_index(spaceShip), {10});
    registry.add_component<component::ctype_t>(registry.entity_from_index(spaceShip), {ENTITY_TYPE::PLAYER});
    registry.add_component<component::crect_t>(registry.entity_from_index(spaceShip), {17.2, 33});
    registry.add_component<component::ckilled_t>(registry.entity_from_index(spaceShip), {false});
    return spaceShip;
}