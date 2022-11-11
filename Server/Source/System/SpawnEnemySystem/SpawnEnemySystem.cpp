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

System::SpawnEnemySystem::SpawnEnemySystem() :
    _mapDimension({1920, 1080}),
    _entityCreator ({
        {MAPCONTENT::ENEMY1, std::bind(&System::SpawnEnemySystem::createEnemy, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4)},
        {MAPCONTENT::ENEMY2, std::bind(&System::SpawnEnemySystem::createEnemy2, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4)}})
{
    std::srand(std::time(nullptr));
}

void System::SpawnEnemySystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position, Sparse_array<component::ctype_t> &type, Sparse_array<component::ctimer_t> &timer, Sparse_array<component::clobbies_status_t> &lobbiesStatus, Sparse_array<component::cmap_t> &map)
{
    if (std::chrono::steady_clock::now() - timer[0].value().spawnEnemyDeltaTime > (std::chrono::nanoseconds)3000000000)
        timer[FORBIDDEN_IDS::NETWORK].value().spawnEnemyDeltaTime = std::chrono::steady_clock::now();
    else
        return;
    for (int index = 1; index <= (int)lobbiesStatus[FORBIDDEN_IDS::LOBBY].value().lobbiesStatus.size(); index++) {
        if (lobbiesStatus[FORBIDDEN_IDS::LOBBY].value().lobbiesStatus[index].first == true) {
            if  (map[FORBIDDEN_IDS::LOBBY].value().end.at(index))
                continue;
            for (std::size_t line = 0; line != map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().end.at(index)).size(); line++) {
                if (map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().end.at(index)).at(line).at(map[FORBIDDEN_IDS::LOBBY].value().index.at(index)) == MAPCONTENT::EMPTY)
                    continue;
                try {
                    Entity enemy = _entityCreator.at(static_cast<MAPCONTENT>(map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().end.at(index)).at(line).at(map[FORBIDDEN_IDS::LOBBY].value().index.at(index))))(registry, index, line, map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().end.at(index)).size());
                    netqueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({index, serialize_header::serializeHeader<packet_new_entity>(static_cast<uint16_t>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_ENTITY), {static_cast<uint16_t>(enemy), position[enemy].value().x, position[enemy].value().y, 3, static_cast<uint16_t>(type[enemy].value().type), 0, 1, 0})});
                } catch (std::out_of_range const &e) {
                    std::cerr << "Spawn Enemy System: key value " << map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().end.at(index)).at(line).at(map[FORBIDDEN_IDS::LOBBY].value().index.at(index)) << " is undefined" << std::endl;
                }
            }
            map[FORBIDDEN_IDS::LOBBY].value().index.at(index) += 1;
            if (map[FORBIDDEN_IDS::LOBBY].value().index.at(index) >= map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().end.at(index)).at(0).size()) {
                std::cout << "Spawn enemy end at size "<<  map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().end.at(index)).at(0).size() <<std::endl;
                map[FORBIDDEN_IDS::LOBBY].value().end.at(index) = true;
            }
        }
    }
}

Entity System::SpawnEnemySystem::createEnemy(Registry &registry, int lobby_id, std::size_t line, std::size_t map_size)
{
    Entity enemy = registry.spawn_entity_with(
        component::cdirection_t{ .x = -1, .y = 0 },
        component::chitbox_t{ .height = 10, .width = 10 },
        component::cposition_t{ .x = static_cast<float>(_mapDimension.first), .y = static_cast<float>(std::rand() % (_mapDimension.second / map_size) + (_mapDimension.second / map_size * line))},
        component::cvelocity_t{ .velocity = 4 },
        component::ctype_t{ .type = ENTITY_TYPE::ENEMY },
        component::crect_t{ .height = 34, .width = 33 },
        component::csceneid_t{ .sceneId = SCENE::GAME },
        component::clobby_id_t{ .id = lobby_id },
        component::chealth_t {1}
    );
    return enemy;
}

Entity System::SpawnEnemySystem::createEnemy2(Registry &registry, int lobby_id, std::size_t line, std::size_t map_size)
{
    Entity enemy = registry.spawn_entity_with(
        component::cdirection_t{ .x = -1, .y = 0 },
        component::chitbox_t{ .height = 10, .width = 10 },
        component::cposition_t{ .x = static_cast<float>(_mapDimension.first), .y = static_cast<float>(std::rand() % (_mapDimension.second / map_size) + (_mapDimension.second / map_size * line))},
        component::cvelocity_t{ .velocity = 4 },
        component::ctype_t{ .type = ENTITY_TYPE::ENEMY },
        component::crect_t{ .height = 34, .width = 33 },
        component::csceneid_t{ .sceneId = SCENE::GAME },
        component::clobby_id_t{ .id = lobby_id },
        component::chealth_t {2}
    );
    return enemy;
}
