/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CTimer
*/

#ifndef CTIMER_HPP_
    #define CTIMER_HPP_

    #include <chrono>

    namespace component {
        struct ctimer_t {
            std::chrono::steady_clock::time_point deltaTime;
            std::chrono::steady_clock::time_point animTimer;
        };
    }

#endif /* !CTIMER_HPP_ */
