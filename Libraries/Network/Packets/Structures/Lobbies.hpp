/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Lobbys
*/

#ifndef LOBBIES_HPP_
#define LOBBIES_HPP_

#include <cstring>
#include <vector>

/**
 * @brief A packet to get the different lobbys from newtork
 * 
 */
struct packet_get_lobbies {
    int id;
};

/**
 * @brief A packet to send the content of lobbys
 * 
 */
struct packet_send_lobbies {
    int nbOfLobbies;
    int nbPlayersLobbyOne;
    int nbPlayersLobbyTwo;// number of players per lobbys
    int nbPlayersLobbyThree;
};

/**
 * @brief A packet to create a lobby
 * 
 */
struct packet_create_lobby {
    int id;
};

/**
 * @brief A packet to get the id of the created lobby
 * 
 */
struct packet_create_lobby_response {
    int id;// id of created lobby
};

/**
 * @brief A packet to tell the server you want to join a room
 * 
 */
struct packet_join_lobby {
    int id;
};

/**
 * @brief A packet to tell the server you want to join a room
 */
struct packet_nb_players_in_lobby {
    int nbPlayers;
};

#endif /* !LOBBIES_HPP_ */
