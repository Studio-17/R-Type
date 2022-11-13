/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewLevel
*/

#ifndef NEWLEVEL_HPP_
    #define NEWLEVEL_HPP_

/**
 * @brief A packet to tell the client that a new level has started in a certain lobby
 */
struct packet_new_level {
    int level; ///< New level
    int totalLevels; ///< Total number of levels
};


#endif /* !NEWLEVEL_HPP_ */
