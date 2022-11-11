/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** GetLobbiesSystem
*/

#include "GetLobbiesSystem.hpp"

/* Constant */
#include "Constant.hpp"

/* Packet */
#include "Lobbies.hpp"

System::GetLobbiesSystem::GetLobbiesSystem()
{
}

static std::string blankSpaces(int nbSpaces)
{
    std::string spaces = "";

    for (int i = 0; i < nbSpaces; i++)
        spaces += " ";
    return spaces;
}

void System::GetLobbiesSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cref_t> &refs, Sparse_array<component::ctext_t> &texts)
{
    while (!netqueue[FORBIDDEN_IDS::NETWORK].value().getLobbiesQueue.empty()) {
        packet_send_lobbies &lobbiesInfos = netqueue[FORBIDDEN_IDS::NETWORK].value().getLobbiesQueue.front();
        std::cout << "Lobbies Infos number of lobby: " << lobbiesInfos.nbOfLobbies << std::endl;
        std::cout << "Lobbies Infos number players in lobby one: " << lobbiesInfos.nbPlayersLobbyOne << std::endl;
        std::cout << "Lobbies Infos number players in two one: " << lobbiesInfos.nbPlayersLobbyTwo << std::endl;
        std::cout << "Lobbies Infos number players in three one: " << lobbiesInfos.nbPlayersLobbyThree << std::endl;

        Entity roomOne = registry.entity_from_index(static_cast<std::size_t>(refs[FORBIDDEN_IDS::NETWORK].value().ref.at("text-room-one-btn")));
        texts[roomOne].value().text = "Room 1" + blankSpaces(51) + "(" + std::to_string(lobbiesInfos.nbPlayersLobbyOne) + "/4)";

        Entity roomTwo = registry.entity_from_index(static_cast<std::size_t>(refs[FORBIDDEN_IDS::NETWORK].value().ref.at("text-room-two-btn")));
        texts[roomTwo].value().text = "Room 2" + blankSpaces(50) + "(" + std::to_string(lobbiesInfos.nbPlayersLobbyTwo) + "/4)";

        Entity roomThree = registry.entity_from_index(static_cast<std::size_t>(refs[FORBIDDEN_IDS::NETWORK].value().ref.at("text-room-three-btn")));
        texts[roomThree].value().text = "Room 3" + blankSpaces(50) + "(" + std::to_string(lobbiesInfos.nbPlayersLobbyThree) + "/4)";

        netqueue[FORBIDDEN_IDS::NETWORK].value().getLobbiesQueue.pop();
    }
}
