/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#include "MoveSystem.hpp"
#include "Constant.hpp"
#include "Move.hpp"
#include "Serialization.hpp"
#include "Position.hpp"
#include "KillEntity.hpp"

System::MoveSystem::MoveSystem()
{
}

void System::MoveSystem::operator()(Registry &registry, [[ maybe_unused ]] Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cdirection_t> &direction, Sparse_array<component::cposition_t> &position, Sparse_array<component::cvelocity_t> &velocity, Sparse_array<component::ctimer_t> &timer, Sparse_array<component::clobby_id_t> &LobbyId, Sparse_array<component::clobbies_status_t> &lobbiesStatus)
{
    if (std::chrono::steady_clock::now() - timer[FORBIDDEN_IDS::NETWORK].value().deltaTime > (std::chrono::nanoseconds)100000000)
        timer[FORBIDDEN_IDS::NETWORK].value().deltaTime = std::chrono::steady_clock::now();
    else
        return;
    for (std::size_t index = 0; index < position.size() && index < velocity.size() && index < direction.size() && index < LobbyId.size(); index++) {
        if (position[index] && velocity[index] && direction[index] && LobbyId[index]) {
            if (!lobbiesStatus[FORBIDDEN_IDS::NETWORK].value().lobbiesStatus.at(LobbyId[index].value().id).first)
                continue;
            if (position[index]->x > 1920 || position[index]->x < 0) {
                registry.kill_entity(registry.entity_from_index(index));
                // sendKillEntityPacket(registry, index, netqueue);
            }
            position[index]->x += (velocity[index]->velocity * direction[index]->x);
            position[index]->y += (velocity[index]->velocity * direction[index]->y);
        }
    }
}

void System::MoveSystem::sendKillEntityPacket(Registry &registry, uint16_t id, Sparse_array<component::cnetwork_queue_t> &netqueue)
{
    packet_kill_entity packet = {.id = id};
    std::vector<byte> bytes = serialize_header::serializeHeader<packet_kill_entity>(NETWORK_SERVER_TO_CLIENT::KILL_ENTITY, packet);
    registry.kill_entity(registry.entity_from_index(id));

    netqueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({1, bytes});
}
