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
#include "CKilled.hpp"

ShootSystem::ShootSystem()
{
}

void ShootSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position)
{
    if (!netqueue[0]->shootQueue.empty()) {
        packet_shoot packet = netqueue[0]->shootQueue.front();
        netqueue[0]->shootQueue.pop();
        Entity bullet = createBullet(registry, position, packet.id);
        netqueue[0]->toSendNetworkQueue.push(serialize_header::serializeHeader<packet_new_entity>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_ENTITY, {bullet, position[bullet]->x, position[bullet]->y, 1, ENTITY_TYPE::BULLET}));
    }
}

Entity ShootSystem::createBullet(Registry &registry, Sparse_array<component::cposition_t> &position, uint16_t playerId)
{
    Entity bullet = registry.spawn_entity();

    component::cdamage_t damage = { 0 };
    registry.add_component<component::cdamage_t>(registry.entity_from_index(bullet), std::move(damage));

    component::cdirection_t direction = { 1, 0 };
    registry.add_component<component::cdirection_t>(registry.entity_from_index(bullet), std::move(direction));

    component::chitbox_t hitbox = {10, 10};
    registry.add_component<component::chitbox_t>(registry.entity_from_index(bullet), std::move(hitbox));

    component::cposition_t possition = {position[playerId]->x, position[playerId]->y};
    registry.add_component<component::cposition_t>(registry.entity_from_index(bullet), std::move(possition));

    component::cvelocity_t velocity = {1 };
    registry.add_component<component::cvelocity_t>(registry.entity_from_index(bullet), std::move(velocity));
    registry.add_component<component::ctype_t>(registry.entity_from_index(bullet), {ENTITY_TYPE::BULLET});
    registry.add_component<component::crect_t>(registry.entity_from_index(bullet), {18, 17});
    registry.add_component<component::ckilled_t>(registry.entity_from_index(bullet), {false});
    return bullet;
}
