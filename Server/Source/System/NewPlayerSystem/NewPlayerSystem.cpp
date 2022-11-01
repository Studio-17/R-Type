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

void NewPlayerSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position, Sparse_array<component::ctype_t> &type)
{
    while (!netqueue[0].value().newPlayerQueue.empty()) {
        Entity spaceShip = createSpaceShip(registry);

        if (position[spaceShip] && type[spaceShip]) {
            std::cout <<"[SERVER] adding new player" << std::endl;
            netqueue[0].value().toSendNetworkQueue.push({0, serialize_header::serializeHeader<packet_new_entity>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_PLAYER, {static_cast<uint16_t>(spaceShip), position[spaceShip].value().x, position[spaceShip].value().y, 1, type[spaceShip].value().type})});
            for (std::size_t index = 1; index != position.size(); index++) {
                if (position[index] && type[index]) {
                    if (index == spaceShip)
                        continue;
                    netqueue[0].value().toSendNetworkQueue.push({0, serialize_header::serializeHeader<packet_new_entity>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_ENTITY, {static_cast<uint16_t>(registry.entity_from_index(index)), position[index].value().x, position[index].value().y, 1, type[index].value().type})});
                }
            }
        }
        netqueue[0].value().newPlayerQueue.pop();
    }
}

Entity NewPlayerSystem::createSpaceShip(Registry &registry)
{
    Entity spaceShip = registry.spawn_entity();

    component::cdirection_t dir = {0, 0};
    registry.add_component<component::cdirection_t>(spaceShip, std::move(dir));

    component::cposition_t pos = {10, 10};
    registry.add_component<component::cposition_t>(spaceShip, std::move(pos));

    component::cvelocity_t vel = {10};
    registry.add_component<component::cvelocity_t>(spaceShip, std::move(vel));

    component::ctype_t type = {ENTITY_TYPE::PLAYER};
    registry.add_component<component::ctype_t>(spaceShip, std::move(type));

    component::crect_t rect = {17.2, 33};
    registry.add_component<component::crect_t>(spaceShip, std::move(rect));
    return spaceShip;
}