/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** StartGameSystem
*/

#include "StartGameSystem.hpp"

#include "Constant.hpp"
#include "NewEntity.hpp"
#include "Serialization.hpp"

#include "Component/CDirection.hpp"
#include "Component/CRect.hpp"
#include "Component/CVelocity.hpp"

System::StartGameSystem::StartGameSystem()
{
}

Entity System::StartGameSystem::createSpaceShip(Registry &registry) {
    Entity spaceShip = registry.spawn_entity_with(
        component::cdirection_t {0, 0},
        component::cposition_t {200, 200},
        component::cvelocity_t {10},
        component::ctype_t {ENTITY_TYPE::PLAYER},
        component::crect_t {17.2, 33},
        component::chealth_t {3}
    );
    return spaceShip;
}

void System::StartGameSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::clobby_id_t> &LobbyId, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities, Sparse_array<component::cposition_t> &position, Sparse_array<component::ctype_t> &type, Sparse_array<component::clobbies_status_t> &lobbiesStatus) {
    while (!netqueue[FORBIDDEN_IDS::NETWORK].value().startGameQueue.empty()) {
        std::pair<int, packet_start_game> &startGame = netqueue[FORBIDDEN_IDS::NETWORK].value().startGameQueue.front();

        std::cout << "StartGameSystem: this client wants to start game (networkid): " << startGame.first << std::endl;
        int lobbyId = LobbyId[netIdToClientId[FORBIDDEN_IDS::NETWORK].value().netIdToClientId.at(startGame.first)].value().id;
        lobbiesStatus[FORBIDDEN_IDS::NETWORK].value().lobbiesStatus[lobbyId] = true;

        for (auto &entity: lobbiesToEntities[FORBIDDEN_IDS::NETWORK].value().lobbiesToEntities.at(lobbyId)) {
            Entity spaceShip = createSpaceShip(registry);
            std::cout << spaceShip << std::endl;
            std::cout << "Start Game System : send new entity packet to client (network id) : " << (int)entity << std::endl;
            netqueue[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push({lobbyId, serialize_header::serializeHeader<packet_new_entity>(NETWORK_SERVER_TO_CLIENT::NEW_ENTITY, {static_cast<uint16_t>(spaceShip), position[spaceShip].value().x, position[spaceShip].value().y, 1, type[spaceShip].value().type, (int)entity})});
        }
        netqueue[FORBIDDEN_IDS::NETWORK].value().startGameQueue.pop();
    }
}
