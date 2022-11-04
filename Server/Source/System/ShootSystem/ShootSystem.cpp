/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#include "ShootSystem.hpp"
#include "Shoot.hpp"
#include "Serialization.hpp"
#include "NewEntity.hpp"
#include "CVelocity.hpp"
#include "CType.hpp"
#include "CRect.hpp"

ShootSystem::ShootSystem()
{
}

void ShootSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position)
{
    (void)registry;
    (void)netqueue;
    (void)position;
    // while (!netqueue[0].value().shootQueue.empty()) {
    //     std::pair<int, packet_shoot> packet = netqueue[0].value().shootQueue.front();
    //     netqueue[0].value().shootQueue.pop();
    //     if (position[packet.second.id]) {
    //         Entity bullet = createBullet(registry, position, packet.second.id);
    //         netqueue[0].value().toSendNetworkQueue.push({0, serialize_header::serializeHeader<packet_new_entity>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_ENTITY, {static_cast<uint16_t>(bullet), position[bullet].value().x, position[bullet].value().y, 1, ENTITY_TYPE::BULLET})});
    //     }
    // }
}

Entity ShootSystem::createBullet(Registry &registry, Sparse_array<component::cposition_t> &position, uint16_t playerId)
{
    Entity bullet = registry.spawn_entity_with(
        component::cdamage_t{ .damage = 0},
        component::cdirection_t{ .x = 1, .y = 0},
        component::chitbox_t{ .height = 10, .width = 10},
        component::cposition_t{ .x = position[playerId].value().x, .y = position[playerId].value().y},
        component::cvelocity_t{ .velocity = 14},
        component::ctype_t{ .type = ENTITY_TYPE::BULLET},
        component::crect_t{ .height = 18, .width = 17}
    );
    return bullet;
}
