/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** GetLobbiesSystem
*/

#include "GetLobbiesSystem.hpp"
#include "Constant.hpp"

#include "CPosition.hpp"
#include "CSceneId.hpp"
#include "CAssetId.hpp"
#include "CRect.hpp"

System::GetLobbiesSystem::GetLobbiesSystem() {
}

void System::GetLobbiesSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::casset_t> &assets) {
    while (!netqueue[FORBIDDEN_IDS::NETWORK].value().getLobbiesQueue.empty()) {
        packet_send_lobbies &lobbiesInfos = netqueue[0].value().getLobbiesQueue.front();
        std::cout << "Lobbies Infos number of lobby: " << lobbiesInfos.nbOfLobbies << std::endl;
        std::cout << "Lobbies Infos number players in lobby one: " << lobbiesInfos.nbPlayersLobbyOne << std::endl;
        std::cout << "Lobbies Infos number players in two one: " << lobbiesInfos.nbPlayersLobbyTwo << std::endl;
        std::cout << "Lobbies Infos number players in three one: " << lobbiesInfos.nbPlayersLobbyThree << std::endl;

        createLobby(registry, lobbiesInfos, assets);

        netqueue[0].value().getLobbiesQueue.pop();
    }
}

void System::GetLobbiesSystem::createLobby( [[ maybe_unused ]] Registry &registry, [[ maybe_unused ]] packet_send_lobbies &lobbiesInfos, [[ maybe_unused ]] Sparse_array<component::casset_t> &assets)
{
    // Entity lobbyOne = registry.spawn_entity_with(
    //     component::csceneid_t { SCENE::ROOMS },
    //     component::cposition_t { .x = 200, .y = 200 },
    //     component::cassetid_t { .assets = "button" },
    //     component::crect_t { .width = 200, .height = 100 }
    // );

    // Entity lobbyTwo = registry.spawn_entity_with(
    //     component::csceneid_t { SCENE::ROOMS },
    //     component::cposition_t { .x = 200, .y = 400 },
    //     component::cassetid_t { .assets = "button" }
    // );

    // Entity lobbyThree = registry.spawn_entity_with(
    //     component::csceneid_t { SCENE::ROOMS },
    //     component::cposition_t { .x = 200, .y = 600 },
    //     component::cassetid_t { .assets = "button" }
    // );
}
