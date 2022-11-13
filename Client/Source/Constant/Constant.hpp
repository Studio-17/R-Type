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
 */
enum FORBIDDEN_IDS {
    NETWORK = 0,
    GRAPHIC = 1
};

/**
 * @brief An enum for all scenes
 */
enum SCENE {
    ALL = 0,
    LOAD_ASSETS,
    GAME,
    INTRODUCTION,
    CONNECTION,
    MAIN_MENU,
    ROOMS,
    CREATE_ROOM,
    OPTIONS,
    CREATE_LOBBY,
    LOBBY,
    EXIT,
    ENDGAME,
    INFORMATIONS,
    CREDITS,
    AUDIO,
    HELP,
    CONTROLS
};

#endif /* !CONSTANT_HPP_ */
