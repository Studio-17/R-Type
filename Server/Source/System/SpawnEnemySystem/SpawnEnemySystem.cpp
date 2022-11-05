/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** SpawnEnemy
*/

#include <cstdlib>
#include <ctime>

#include "SpawnEnemySystem.hpp"

#include "Constant.hpp"
#include "Serialization.hpp"
#include "NewEntity.hpp"

#include "Component/CVelocity.hpp"
#include "Component/CRect.hpp"
#include "Component/CDirection.hpp"
#include "Component/CHitBox.hpp"
#include "Component/CSceneId.hpp"

System::SpawnEnemySystem::SpawnEnemySystem()
{
    std::srand(std::time(nullptr));
}

void System::SpawnEnemySystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position, Sparse_array<component::ctype_t> &type, Sparse_array<component::ctimer_t> &timer)
{
    if (std::chrono::steady_clock::now() - timer[0].value().spawnEnemyDeltaTime > (std::chrono::nanoseconds)3000000000)
        timer[FORBIDDEN_IDS::NETWORK].value().spawnEnemyDeltaTime = std::chrono::steady_clock::now();
    else
        return;
    Entity enemy = createEnemy(registry);
    if (position[enemy] && type[enemy]) {
        netqueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({1, serialize_header::serializeHeader<packet_new_entity>(static_cast<uint16_t>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_ENTITY), {static_cast<uint16_t>(enemy), position[enemy].value().x, position[enemy].value().y, 3, static_cast<uint16_t>(type[enemy].value().type), 0})});
    }
}

Entity System::SpawnEnemySystem::createEnemy(Registry &registry)
{
    Entity enemy = registry.spawn_entity_with(
        component::cdirection_t{ .x = -1, .y = 0 },
        component::chitbox_t{ .height = 10, .width = 10 },
        component::cposition_t{ .x = 700, .y = static_cast<float>(std::rand() % 600) },
        component::cvelocity_t{ .velocity = 4 },
        component::ctype_t{ .type = ENTITY_TYPE::ENEMY },
        component::crect_t{ .height = 34, .width = 33.5 },
        component::csceneid_t{ .sceneId = SCENE::GAME }
    );
    return enemy;
}
