/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** SpawnEnemy
*/

#include "SpawnEnemySystem.hpp"

#include <cstdlib>
#include <ctime>

#include "CVelocity.hpp"
#include "Component/CDirection.hpp"
#include "Component/CHitBox.hpp"
#include "Serialization.hpp"
#include "NewEntity.hpp"

SpawnEnemySystem::SpawnEnemySystem()
{
    std::srand(std::time(nullptr));
    _created = false;
}

void SpawnEnemySystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position)
{
    if (!_created) {
        Entity enemy = createEnemy(registry);

        netqueue[0]->toSendNetworkQueue.push(serialize_header::serializeHeader<packet_new_entity>(static_cast<uint16_t>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_ENTITY), {enemy, position[enemy]->x, position[enemy]->y, 1, ENTITY_TYPE::ENEMY}));
        _created = true;
    }
}

Entity SpawnEnemySystem::createEnemy(Registry &registry)
{
    Entity enemy = registry.spawn_entity();

    component::cdirection_t direction = { 1, 0 };
    registry.add_component<component::cdirection_t>(registry.entity_from_index(enemy), std::move(direction));

    component::chitbox_t hitbox = { 10, 10 };
    registry.add_component<component::chitbox_t>(registry.entity_from_index(enemy), std::move(hitbox));

    component::cposition_t position = { 900, static_cast<float>(std::rand() % 600) };
    registry.add_component<component::cposition_t>(registry.entity_from_index(enemy), std::move(position));

    component::cvelocity_t velocity = { 1 };
    registry.add_component<component::cvelocity_t>(registry.entity_from_index(enemy), std::move(velocity));

    return enemy;
}
