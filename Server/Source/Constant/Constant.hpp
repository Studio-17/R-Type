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
    NETWORK = 0,
    GRAPHIC = 1
};

/**
 * @brief An enum for all scenes
 * 
 */
enum SCENE {
    MENU = 0,
    SETTINGS = 1,
    GAME = 2,
    END = 3
};

#endif /* !CONSTANT_HPP_ */
