/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Click
*/

#ifndef CLICK_HPP_
    #define CLICK_HPP_

    #include "Registry.hpp"

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief Structure representing the click component to know if a entity is pressed and a call back to call when the entity is pressed
     */
    struct cclick_t {
        bool isPressed; ///< Boolean to know if is pressed
        std::function<void(Registry &registry)> callBack; ///< Callback function
    };
}

#endif /* !CLICK_HPP_ */
