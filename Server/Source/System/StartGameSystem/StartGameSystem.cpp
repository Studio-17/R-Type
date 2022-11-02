/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** StartGameSystem
*/

#include "StartGameSystem.hpp"
#include "Constant.hpp"

StartGameSystem::StartGameSystem()
{
}

void StartGameSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue)
{
    while (!netqueue[FORBIDDEN_IDS::NETWORK].value().startGameQueue.empty()) {
        std::pair<int, packet_start_game> startGame = netqueue[FORBIDDEN_IDS::NETWORK].value().startGameQueue.front();
        std::cout << "StartGameSystem: this client wants to start game : " << startGame.first << std::endl;
    }
}
