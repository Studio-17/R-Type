/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** StartGame
*/

#ifndef STARTGAME_HPP_
    #define STARTGAME_HPP_

/**
 * @brief A packet to tell the server that a client want to start the game in a certain lobby
 * 
 */
struct packet_start_game {
    int lobbyId;
};

#endif /* !STARTGAME_HPP_ */
