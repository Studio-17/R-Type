/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewPlayerSystem
*/

#include "NewPlayerSystem.hpp"

#include "Serialization.hpp"
#include "Constant.hpp"

#include "CDirection.hpp"
#include "CPosition.hpp"
#include "CVelocity.hpp"
#include "CRect.hpp"
#include "CSceneId.hpp"

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
            netqueue[0].value().toSendNetworkQueue.push(serialize_header::serializeHeader<packet_new_entity>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_PLAYER, {static_cast<uint16_t>(spaceShip), position[spaceShip].value().x, position[spaceShip].value().y, 1, static_cast<uint16_t>(type[spaceShip].value().type)}));
            for (std::size_t index = 1; index != position.size(); index++) {
                if (position[index] && type[index]) {
                    if (index == spaceShip)
                        continue;
                    netqueue[0].value().toSendNetworkQueue.push(serialize_header::serializeHeader<packet_new_entity>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_ENTITY, {static_cast<uint16_t>(registry.entity_from_index(index)), position[index].value().x, position[index].value().y, 1, static_cast<uint16_t>(type[index].value().type)}));
                }
            }
        }
        netqueue[0].value().newPlayerQueue.pop();
    }
}

Entity NewPlayerSystem::createSpaceShip(Registry &registry)
{
    Entity spaceShip = registry.spawn_entity_with(
        component::cdirection_t{ .x = 0, .y = 0},
        component::cposition_t{ .x = 10, .y = 10},
        component::cvelocity_t{ .velocity = 10},
        component::ctype_t{ .type = ENTITY_TYPE::PLAYER},
        component::crect_t{ .height = 17.2, .width = 33},
        component::csceneid_t{ .sceneId = SCENE::GAME}
    );
    return spaceShip;
}