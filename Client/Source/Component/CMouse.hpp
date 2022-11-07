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
 */
namespace component {
    /**
     * @brief Strucrue reprensenting the mouse component in charge of mouse state
     */
    struct cmouseState_t {
        int xPos; ///< Position x of the mouse
        int yPos; ///< Position y of the mouse
        bool isButtonPressed; ///< If the mouse button is pressed, it's true
    };
}

#endif /* !MOUSE_HPP_ */
