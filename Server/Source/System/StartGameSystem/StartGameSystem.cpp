/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** StartGameSystem
*/

#include "StartGameSystem.hpp"
#include "CDirection.hpp"
#include "CPosition.hpp"
#include "CRect.hpp"
#include "CType.hpp"
#include "CVelocity.hpp"
#include "Constant.hpp"
#include "NewEntity.hpp"
#include "Serialization.hpp"

StartGameSystem::StartGameSystem()
{
}

Entity StartGameSystem::createSpaceShip(Registry &registry) {
    Entity spaceShip = registry.spawn_entity();

    component::cdirection_t dir = {0, 0};
    registry.add_component<component::cdirection_t>(spaceShip, std::move(dir));

    component::cposition_t pos = {10, 10};
    registry.add_component<component::cposition_t>(spaceShip, std::move(pos));

    component::cvelocity_t vel = {10};
    registry.add_component<component::cvelocity_t>(spaceShip, std::move(vel));

    component::ctype_t type = {ENTITY_TYPE::PLAYER};
    registry.add_component<component::ctype_t>(spaceShip, std::move(type));

    component::crect_t rect = {17.2, 33};
    registry.add_component<component::crect_t>(spaceShip, std::move(rect));
    return spaceShip;
}


void StartGameSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::clobby_id_t> &LobbyId, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities, Sparse_array<component::cposition_t> &position, Sparse_array<component::ctype_t> &type) {
    while (!netqueue[FORBIDDEN_IDS::NETWORK].value().startGameQueue.empty()) {
        std::pair<int, packet_start_game> startGame = netqueue[FORBIDDEN_IDS::NETWORK].value().startGameQueue.front();

        std::cout << "StartGameSystem: this client wants to start game : " << startGame.first << std::endl;
        int lobbyId = LobbyId[netIdToClientId[FORBIDDEN_IDS::NETWORK].value().netIdToClientId.at(startGame.first)].value().id;
        for (auto &entity: lobbiesToEntities[FORBIDDEN_IDS::NETWORK].value().lobbiesToEntities.at(lobbyId)) {
            Entity spaceShip = createSpaceShip(registry);
            netqueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({lobbyId, serialize_header::serializeHeader<packet_new_entity>(NETWORK_SERVER_TO_CLIENT::NEW_ENTITY, {static_cast<uint16_t>(registry.entity_from_index(spaceShip)), position[spaceShip].value().x, position[spaceShip].value().y, 1, type[spaceShip].value().type, (int)entity})});
        }
        netqueue[FORBIDDEN_IDS::NETWORK].value().startGameQueue.pop();


    }
}
