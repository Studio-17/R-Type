/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** EndGame
*/

#ifndef ENDGAME_HPP_
    #define ENDGAME_HPP_

/**
 * @brief A packet to tell the server that a client want to end the game in a certain lobby
 */
struct packet_end_game {
    int lobbyId; ///< Id of the 
    bool status; ///< Boolean to know if the game is lost or winned. true : win, false : lost
};

#endif /* !ENDGAME_HPP_ */
