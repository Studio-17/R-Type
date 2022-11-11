/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** EndGameSystem
*/

#include <algorithm>

#include "EndGameSystem.hpp"
#include "Constant.hpp"

/* Packet */
#include "KillEntity.hpp"
#include "EndGame.hpp"

System::EndGameSystem::EndGameSystem()
{
    _entityToKill = {ENTITY_TYPE::BULLET, ENTITY_TYPE::PLAYER, ENTITY_TYPE::ENEMY};
}

std::size_t countNbEntityInLobby(int lobbyId, ENTITY_TYPE entityType, Sparse_array<component::ctype_t> &type, Sparse_array<component::clobby_id_t> &lobbyIds)
{
    std::size_t count = 0;
    for (std::size_t index = 0; index < type.size() && index < lobbyIds.size(); index++) {
        if (!type[index] || !lobbyIds[index])
            continue;
        if (lobbyIds[index].value().id != lobbyId)
            continue;
        if (type[index].value().type == entityType)
            count += 1;
    }
    return count;
}

void System::EndGameSystem::operator()([[ maybe_unused ]] Registry &registry, [[ maybe_unused ]]Sparse_array<component::cnetwork_queue_t> &network_queues, [[ maybe_unused ]]Sparse_array<component::ctype_t> &type,[[ maybe_unused ]] Sparse_array<component::clobby_id_t> &lobbyIds, [[ maybe_unused ]]Sparse_array<component::clobbies_status_t> &lobbiesStatus, Sparse_array<component::cmap_t> &map)
{
    for (int lobbyId = 1; lobbyId <= 3; lobbyId++) {
        if ((!countNbEntityInLobby(lobbyId, ENTITY_TYPE::PLAYER, type, lobbyIds) || (map[FORBIDDEN_IDS::LOBBY].value().end && !countNbEntityInLobby(lobbyId, ENTITY_TYPE::ENEMY, type, lobbyIds))) && lobbiesStatus[FORBIDDEN_IDS::LOBBY].value().lobbiesStatus.at(lobbyId).first) {
            std::cout << "EndGame System no spaceship alive"<<std::endl;
            for (std::size_t index = 0; index < lobbyIds.size() && index < type.size(); index++) {
                if (!lobbyIds[index] || !type[index])
                    continue;
                if (lobbyIds[index].value().id == lobbyId && std::find(_entityToKill.begin(), _entityToKill.end(), type[index].value().type) != _entityToKill.end())
                    registry.kill_entity(registry.entity_from_index(index));
            }
            lobbiesStatus[FORBIDDEN_IDS::LOBBY].value().lobbiesStatus.at(lobbyId).first = false;
            lobbiesStatus[FORBIDDEN_IDS::LOBBY].value().lobbiesStatus.at(lobbyId).second = 1;
            for (auto &entity : _entityToKill)
                network_queues[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({lobbyId, serialize_header::serializeHeader<packet_kill_entity_type>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY_TYPE, {static_cast<int>(entity)})});
            network_queues[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({lobbyId, serialize_header::serializeHeader<packet_end_game>(NETWORK_SERVER_TO_CLIENT::END_GAME, {lobbyId})});
        }
    }
}