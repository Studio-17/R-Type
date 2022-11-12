/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** SpawnEnemy
*/

#include <cstdlib>
#include <ctime>
#include <fstream>

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
    _mapDimension({1920, 1080}), _entityCreator ({ {MAPCONTENT::ENEMY1, 0}, {MAPCONTENT::ENEMY2, 1}, {MAPCONTENT::ENEMY3, 2}})
{
    loadAssets("Assets/Specs/Enemy.json");
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
            std::cout << "Spawn enemy top print" << map[FORBIDDEN_IDS::LOBBY].value().mapIndex.at(index) << std::endl;
            if  (map[FORBIDDEN_IDS::LOBBY].value().end.at(index))
                continue;
            for (std::size_t line = 0; line != map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().mapIndex.at(index)).size(); line++) {
                if (map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().mapIndex.at(index)).at(line).at(map[FORBIDDEN_IDS::LOBBY].value().index.at(index)) == MAPCONTENT::EMPTY)
                    continue;
                try {
                    Entity enemy = createEnemyFromSpec(registry, _entityCreator.at(static_cast<MAPCONTENT>(map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().mapIndex.at(index)).at(line).at(map[FORBIDDEN_IDS::LOBBY].value().index.at(index)))), index, line, map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().mapIndex.at(index)).size());
                    netqueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({index, serialize_header::serializeHeader<packet_new_entity>(static_cast<uint16_t>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_ENTITY), {static_cast<uint16_t>(enemy), position[enemy].value().x, position[enemy].value().y, 3, static_cast<uint16_t>(type[enemy].value().type), 0, 1, 0})});
                } catch (std::out_of_range const &e) {
                    std::cerr << "Spawn Enemy System: key value " << map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().mapIndex.at(index)).at(line).at(map[FORBIDDEN_IDS::LOBBY].value().index.at(index)) << " is undefined" << std::endl;
                }
            }
            map[FORBIDDEN_IDS::LOBBY].value().index.at(index) += 1;
            if (map[FORBIDDEN_IDS::LOBBY].value().index.at(index) >= map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().mapIndex.at(index)).at(0).size()) {
                std::cout << "Spawn enemy end at size "<<  map[FORBIDDEN_IDS::LOBBY].value().map.at(map[FORBIDDEN_IDS::LOBBY].value().mapIndex.at(index)).at(0).size() <<std::endl;
                map[FORBIDDEN_IDS::LOBBY].value().end.at(index) = true;
            }
        }
    }
}

Entity System::SpawnEnemySystem::createEnemyFromSpec(Registry &registry, int enemyType, int lobby_id, std::size_t line, std::size_t map_size)
{
    std::cout << "Spawn enemy from spec" << _enemySpec.at(enemyType).type <<std::endl;
    Entity enemy = registry.spawn_entity_with(
        component::cdirection_t{ .x = _enemySpec.at(enemyType).direction.first, .y = _enemySpec.at(enemyType).direction.second },
        component::chitbox_t{ .height = _enemySpec.at(enemyType).hitbox.second, .width = _enemySpec.at(enemyType).hitbox.first },
        component::cposition_t{ .x = static_cast<float>(_mapDimension.first), .y = static_cast<float>(std::rand() % (_mapDimension.second / map_size) + (_mapDimension.second / map_size * line))},
        component::cvelocity_t{ .velocity = _enemySpec.at(enemyType).velocity },
        component::ctype_t{ .type = _enemySpec.at(enemyType).type },
        component::crect_t{ .height = _enemySpec.at(enemyType).rect.second, .width = _enemySpec.at(enemyType).rect.first },
        component::csceneid_t{ .sceneId = SCENE::GAME },
        component::clobby_id_t{ .id = lobby_id },
        component::chealth_t {_enemySpec.at(enemyType).health}
    );
    return enemy;
}

nlohmann::json System::SpawnEnemySystem::getJsonData(std::string const &filepath)
{
    nlohmann::json jsonData;
    std::ifstream confStream(filepath);

    if (!confStream.is_open()) {
        throw ("file " + filepath + " failed to open");
    }
    confStream >> jsonData;
    confStream.close();
    return jsonData;
}

void System::SpawnEnemySystem::loadAssets(std::string const &filepath)
{
    nlohmann::json jsonData;
    try {
        jsonData = getJsonData(filepath);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    for (auto oneData : jsonData) {
        _enemySpec.emplace_back(spec_t(oneData));
    }
    std::cout << "SpawnEnemySystem "<< _enemySpec.size() << std::endl;
}
