/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Keyboard
*/

#ifndef CKEYBOARD_HPP_
    #define CKEYBOARD_HPP_

    #include "Keyboard.hpp"

/**
 * @brief Namespace for all components
 * 
 */
namespace component {
    /**
     * @brief Structure representing the keyboard component in charge of keyboard state
     * 
     */
    typedef struct ckeyboard_s {
        std::shared_ptr<Keyboard> keyboard; /**< Keyboard object */
    } ckeyboard_t;
}

#endif /* !CKEYBOARD_HPP_ */
