/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** SetNbPlayerInLobbySystem
*/

#include "SetNbPlayerInLobbySystem.hpp"
#include "Constant.hpp"

System::SetNbPlayerInLobbySystem::SetNbPlayerInLobbySystem()
{
}

void System::SetNbPlayerInLobbySystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cnetwork_queue_t> &networkQueue)
{
    while (!networkQueue[FORBIDDEN_IDS::NETWORK].value().nbPlayerInLobbyQueue.empty()) {
        packet_nb_players_in_lobby &packet = networkQueue[FORBIDDEN_IDS::NETWORK].value().nbPlayerInLobbyQueue.front();
        std::cout << "nb Players in Lobby " << packet.nbPlayers << std::endl;
        networkQueue[FORBIDDEN_IDS::NETWORK].value().nbPlayerInLobbyQueue.pop();
    }
}