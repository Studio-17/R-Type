/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Constant
*/

#ifndef CONSTANT_HPP_
    #define CONSTANT_HPP_

/**
 * @brief An enum for all the IDs that cannot be taken for a new entity
 * 
 */
enum FORBIDDEN_IDS {
    GRAPHIC = 0,
    NETWORK = 1
};

/**
 * @brief An enum representing all the type an entity can take
 * 
 */
enum ENTITY_TYPE {
    PLAYER,
    WALL,
    ENEMY,
    BUTTON,
    TEXT,
    UI,
    GRAPHIC,
    NETWORK
};

/**
 * @brief An enum representing the different kind of ZAxis
 * 
 */
enum ZAXIS {
    BACK,
    MID,
    FRONT
};

/**
 * @brief An enum representing the different kind of scenes
 * 
 */
enum SCENES {
    MAIN_MENU,
    SELECT_ROOM,
    GAME,
    PAUSE
};

#endif /* !CONSTANT_HPP_ */
