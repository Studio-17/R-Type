/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Move
*/

#ifndef MOVE_HPP_
    #define MOVE_HPP_

    #include <cstdint>

/**
 * @brief A packet to handle the entity movements
 */
struct packet_move {
    enum DIRECTION {
        PLUS = 1,
        MINUS = 2
    }; ///< Direction of the axis
    uint16_t playerId; ///< Id of the Entity wich move
    float x; ///< X axis
    float y; ///< Y axis
};

#endif /* !MOVE_HPP_ */
