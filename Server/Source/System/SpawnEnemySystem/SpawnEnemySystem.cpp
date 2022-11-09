/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** SpawnEnemy
*/

#include <cstdlib>
#include <ctime>

#include "SpawnEnemySystem.hpp"

/* Constant */
#include "Constant.hpp"

/* Serialization */
#include "Serialization.hpp"

/* Packets */
#include "NewEntity.hpp"

/* Component */
#include "Component/CVelocity.hpp"
#include "Component/CRect.hpp"
#include "Component/CDirection.hpp"
#include "Component/CHitBox.hpp"
#include "Component/CSceneId.hpp"
#include "Component/CLobbyId.hpp"
#include "Component/CHealth.hpp"

System::SpawnEnemySystem::SpawnEnemySystem()
{
    std::srand(std::time(nullptr));
}

void System::SpawnEnemySystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position, Sparse_array<component::ctype_t> &type, Sparse_array<component::ctimer_t> &timer, Sparse_array<component::clobbies_status_t> &lobbiesStatus, Sparse_array<component::cmap_t> &map)
{
    if (std::chrono::steady_clock::now() - timer[0].value().spawnEnemyDeltaTime > (std::chrono::nanoseconds)3000000000)
        timer[FORBIDDEN_IDS::NETWORK].value().spawnEnemyDeltaTime = std::chrono::steady_clock::now();
    else
        return;
    if (map[FORBIDDEN_IDS::LOBBY].value().end)
        return;
    for (int i = 1; i <= (int)lobbiesStatus[FORBIDDEN_IDS::LOBBY].value().lobbiesStatus.size(); i++) {
        if (lobbiesStatus[FORBIDDEN_IDS::LOBBY].value().lobbiesStatus[i].first == true) {
            std::cout << "SpawnEnemy System" << map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().index) << std::endl;
            if (!map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().index))
                return;
            Entity enemy = createEnemy(registry, i);
            netqueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({i, serialize_header::serializeHeader<packet_new_entity>(static_cast<uint16_t>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_ENTITY), {static_cast<uint16_t>(enemy), position[enemy].value().x, position[enemy].value().y, 3, static_cast<uint16_t>(type[enemy].value().type), 0, 1, 0})});
        }
    }
    map[FORBIDDEN_IDS::LOBBY].value().index += 1;
    if (map[FORBIDDEN_IDS::LOBBY].value().index >= map[FORBIDDEN_IDS::LOBBY].value().map.size()) {
        std::cout << "Spawn Enemy map End" << std::endl;
        map[FORBIDDEN_IDS::LOBBY].value().end = true;
    }
}

Entity System::SpawnEnemySystem::createEnemy(Registry &registry, int lobby_id)
{
    Entity enemy = registry.spawn_entity_with(
        component::cdirection_t{ .x = -1, .y = 0 },
        component::chitbox_t{ .height = 10, .width = 10 },
        component::cposition_t{ .x = 700, .y = static_cast<float>(std::rand() % 600) },
        component::cvelocity_t{ .velocity = 4 },
        component::ctype_t{ .type = ENTITY_TYPE::ENEMY },
        component::crect_t{ .height = 34, .width = 33 },
        component::csceneid_t{ .sceneId = SCENE::GAME },
        component::clobby_id_t{ .id = lobby_id },
        component::chealth_t {1}
    );
    return enemy;
}
