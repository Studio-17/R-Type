/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Move
*/

#ifndef MOVE_HPP_
    #define MOVE_HPP_

    #include <cstdint>

struct packet_move {
    enum Direction {
        UP,
        LEFT,
        RIGHT,
        DOWN
    };
    uint16_t playerId;
    uint16_t direction;
};

#endif /* !MOVE_HPP_ */
