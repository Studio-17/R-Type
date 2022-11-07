/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** GetLobbiesSystem
*/

#include "GetLobbiesSystem.hpp"
#include "Constant.hpp"

System::GetLobbiesSystem::GetLobbiesSystem() {
}

void System::GetLobbiesSystem::operator()([[maybe_unused]] Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue) {
    while (!netqueue[FORBIDDEN_IDS::NETWORK].value().getLobbiesQueue.empty()) {
        packet_send_lobbies &lobbiesInfos = netqueue[0].value().getLobbiesQueue.front();
        std::cout << "Lobbies Infos number of lobby: " << lobbiesInfos.nbOfLobbies << std::endl;
        std::cout << "Lobbies Infos number players in lobby one: " << lobbiesInfos.nbPlayersLobbyOne << std::endl;
        std::cout << "Lobbies Infos number players in two one: " << lobbiesInfos.nbPlayersLobbyTwo << std::endl;
        std::cout << "Lobbies Infos number players in three one: " << lobbiesInfos.nbPlayersLobbyThree << std::endl;

        netqueue[0].value().getLobbiesQueue.pop();
    }
}
