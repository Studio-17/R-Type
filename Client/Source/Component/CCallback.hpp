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
 *
 */
namespace component {
    /**
     * @brief Structure representing a callback function
     *
     */
    typedef struct ccallback_s {
        std::function<void(void)> callback;
    } ccallback_t;
}

#endif /* !CCALLBACK_HPP_ */
