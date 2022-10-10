/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Mouse
*/

#ifndef MOUSE_HPP_
    #define MOUSE_HPP_

/**
 * @brief Namespace for all component
 *
 */
namespace component {
    /**
     * @brief Strucrue reprensenting the mouse component in charge of mouse state
     *
     */
    typedef struct mouseState_s {
        int xPos;
        int yPos;
        bool isButtonPressed;
    } mouseState_t;
}

#endif /* !MOUSE_HPP_ */
