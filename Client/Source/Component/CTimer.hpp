/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CTimer
*/

#ifndef CTIMER_HPP_
    #define CTIMER_HPP_

    #include <chrono>

/**
 * @brief A namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the timer component of an entity
     */
    struct ctimer_t {
        std::chrono::steady_clock::time_point deltaTime; ///< delta time
        std::chrono::steady_clock::time_point animTimer; ///< delta time to handle animation
    };
}

#endif /* !CTIMER_HPP_ */
