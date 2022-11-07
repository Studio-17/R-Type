/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CColor
*/

#ifndef CCOLOR_HPP_
    #define CCOLOR_HPP_

    #include <array>

/**
 * @brief Namespace for all components
 * 
 */
namespace component {
    /**
     * @brief A structure representing the color component
     *
     */
    struct ccolor_t {
        std::array<float, 4> color;
    };
}

#endif /* !CCOLOR_HPP_ */
