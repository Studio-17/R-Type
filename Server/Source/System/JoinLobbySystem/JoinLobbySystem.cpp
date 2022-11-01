/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** JoinLobbySystem
*/

#include "JoinLobbySystem.hpp"
#include "Constant.hpp"

JoinLobbySystem::JoinLobbySystem()
{
}

JoinLobbySystem::~JoinLobbySystem()
{
}

void JoinLobbySystem::operator()(Sparse_array<component::cnetwork_queue_t> &networkQueue, Sparse_array<component::clobby_id_t> &lobbyId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities)
{
    if (networkQueue[FORBIDDEN_IDS::NETWORK]) {
        while (!networkQueue[FORBIDDEN_IDS::NETWORK].value().joinLobbyQueue.empty()) {
            packet_join_lobby packet = networkQueue[FORBIDDEN_IDS::NETWORK].value().joinLobbyQueue.front();
            networkQueue[FORBIDDEN_IDS::NETWORK].value().joinLobbyQueue.pop();
            std::cout << "JoinLobbySystem lobby number : " << packet.id << std::endl;



    }
}
