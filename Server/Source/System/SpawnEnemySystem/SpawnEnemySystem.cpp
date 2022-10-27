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
#include "CRect.hpp"
#include "Component/CDirection.hpp"
#include "Component/CHitBox.hpp"
#include "Serialization.hpp"
#include "NewEntity.hpp"

SpawnEnemySystem::SpawnEnemySystem()
{
    std::srand(std::time(nullptr));
}

void SpawnEnemySystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position, Sparse_array<component::ctype_t> &type, Sparse_array<component::ctimer_t> &timer)
{
    if (std::chrono::steady_clock::now() - timer[0].value().spawnEnemyDeltaTime > (std::chrono::nanoseconds)3000000000)
        timer[0].value().spawnEnemyDeltaTime = std::chrono::steady_clock::now();
    else
        return;
    Entity enemy = createEnemy(registry);
    if (position[enemy] && type[enemy]) {
        std::cout << "[SERVER] adding new enemy" << std::endl;
        std::cout << "[SERVER] Position: x " << position[enemy].value().x << " ,y "<< position[enemy].value().y << std::endl;
        netqueue[0].value().toSendNetworkQueue.push(serialize_header::serializeHeader<packet_new_entity>(static_cast<uint16_t>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_ENTITY), {static_cast<uint16_t>(enemy), position[enemy].value().x, position[enemy].value().y, 3, static_cast<uint16_t>(type[enemy].value().type)}));
    }
}

Entity SpawnEnemySystem::createEnemy(Registry &registry)
{
    Entity enemy = registry.spawn_entity();

    component::cdirection_t direction = { -1, 0 };
    registry.add_component<component::cdirection_t>(enemy, std::move(direction));

    component::chitbox_t hitbox = { 10, 10 };
    registry.add_component<component::chitbox_t>(enemy, std::move(hitbox));

    component::cposition_t position = { 700, static_cast<float>(std::rand() % 600) };
    registry.add_component<component::cposition_t>(enemy, std::move(position));

    component::cvelocity_t velocity = { 4 };
    registry.add_component<component::cvelocity_t>(enemy, std::move(velocity));

    registry.add_component<component::ctype_t>(enemy, {ENTITY_TYPE::ENEMY});
    registry.add_component<component::crect_t>(enemy, {34, 33.5});
    return enemy;
}
