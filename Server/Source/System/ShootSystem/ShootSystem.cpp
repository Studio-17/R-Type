/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#include "ShootSystem.hpp"

/* Constant */
#include "Constant.hpp"

/* Packets */
#include "Shoot.hpp"
#include "Serialization.hpp"
#include "NewEntity.hpp"

/* Components */
#include "Component/CVelocity.hpp"
#include "Component/CType.hpp"
#include "Component/CRect.hpp"
#include "Component/CHealth.hpp"
#include "Component/COwnerId.hpp"

System::ShootSystem::ShootSystem()
{
}

void System::ShootSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position, Sparse_array<component::clobby_id_t> &LobbyId, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId)
{
    while (!netqueue[FORBIDDEN_IDS::NETWORK].value().shootQueue.empty()) {
        std::pair<int, packet_shoot> &packet = netqueue[0].value().shootQueue.front();
        if (position[packet.second.id]) {
            int lobbyId = LobbyId[netIdToClientId[FORBIDDEN_IDS::NETWORK].value().netIdToClientId.at(packet.first)].value().id;
            Entity bullet = createBullet(registry, position, packet.second.id, lobbyId);

            netqueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({lobbyId, serialize_header::serializeHeader<packet_new_entity>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::NEW_ENTITY, {static_cast<uint16_t>(bullet), position[bullet].value().x, position[bullet].value().y, 1, ENTITY_TYPE::BULLET, 0})});
        }
        netqueue[FORBIDDEN_IDS::NETWORK].value().shootQueue.pop();
    }
}

Entity System::ShootSystem::createBullet(Registry &registry, Sparse_array<component::cposition_t> &position, uint16_t playerId, int lobbyId)
{
    Entity bullet = registry.spawn_entity_with(
        component::cdamage_t{ .damage = 0},
        component::cdirection_t{ .x = 1, .y = 0},
        component::chitbox_t{ .height = 10, .width = 10},
        component::cposition_t{ .x = position[playerId].value().x, .y = position[playerId].value().y},
        component::cvelocity_t{ .velocity = 14},
        component::ctype_t{ .type = ENTITY_TYPE::BULLET},
        component::crect_t{ .height = 18, .width = 17},
        component::clobby_id_t{ .id = lobbyId},
        component::chealth_t {1},
        component::cowner_id_t {.id = playerId}
    );
    return bullet;
}
