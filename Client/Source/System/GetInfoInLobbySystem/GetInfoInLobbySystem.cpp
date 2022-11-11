/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** GetInfoInLobbySystem
*/

#include "GetInfoInLobbySystem.hpp"

/* Constant */
#include "Constant.hpp"

/* Packet */
#include "Lobbies.hpp"

System::GetInfoInLobbySystem::GetInfoInLobbySystem()
{
}

void System::GetInfoInLobbySystem::operator()([[ maybe_unused ]] Registry &registry, [[ maybe_unused ]] Sparse_array<component::cnetwork_queue_t> &netqueue, [[ maybe_unused ]] Sparse_array<component::cref_t> &refs, [[ maybe_unused ]] Sparse_array<component::ctext_t> &texts)
{
    while (!netqueue[FORBIDDEN_IDS::NETWORK].value().nbPlayerInLobbyQueue.empty()) {
        packet_nb_players_in_lobby &lobby = netqueue[FORBIDDEN_IDS::NETWORK].value().nbPlayerInLobbyQueue.front();

        std::cout << "Lobbies Infos number players in lobby: " << lobby.nbPlayers << std::endl;

        Entity nbPlayers = registry.entity_from_index(static_cast<std::size_t>(refs[FORBIDDEN_IDS::NETWORK].value().ref.at("nb-players-in-lobby-txt")));
        texts[nbPlayers].value().text = "Players: (" + std::to_string(lobby.nbPlayers) + "/4)";

        netqueue[FORBIDDEN_IDS::NETWORK].value().nbPlayerInLobbyQueue.pop();
    }
}
