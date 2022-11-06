/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CCallback
*/

#ifndef CCALLBACK_HPP_
    #define CCALLBACK_HPP_

    #include <functional>

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief Structure representing a callback function
     */
    struct ccallback_t {
        std::function<void(void)> callback; ///< callback function to call
    };
}

#endif /* !CCALLBACK_HPP_ */
