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

void SpawnEnemySystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position, Sparse_array<component::ctype_t> &type)
{
    if (!_created) {
        Entity enemy = createEnemy(registry);

        std::cout << "[Server] adding new enemy" << std::endl;
        std::cout << "[SERVER] Position: x " <<position[enemy]->x <<" ,y "<<position[enemy]->y<< std::endl;
        netqueue[0]->toSendNetworkQueue.push(serialize_header::serializeHeader<packet_new_entity>(static_cast<uint16_t>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_ENTITY), {enemy, position[enemy]->x, position[enemy]->y, 3, type[enemy]->type}));
        _created = true;
    }
}

Entity SpawnEnemySystem::createEnemy(Registry &registry)
{
    Entity enemy = registry.spawn_entity();

    component::cdirection_t direction = { 0, 0 };
    registry.add_component<component::cdirection_t>(registry.entity_from_index(enemy), std::move(direction));

    component::chitbox_t hitbox = { 10, 10 };
    registry.add_component<component::chitbox_t>(registry.entity_from_index(enemy), std::move(hitbox));

    component::cposition_t position = { 700, static_cast<float>(std::rand() % 600) };
    registry.add_component<component::cposition_t>(registry.entity_from_index(enemy), std::move(position));

    component::cvelocity_t velocity = { 1 };
    registry.add_component<component::cvelocity_t>(registry.entity_from_index(enemy), std::move(velocity));
    registry.add_component<component::ctype_t>(registry.entity_from_index(enemy), {ENTITY_TYPE::ENEMY});

    return enemy;
}
