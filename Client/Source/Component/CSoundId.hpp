/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CSoundId
*/

#ifndef CSOUNDID_HPP_
    #define CSOUNDID_HPP_

    #include <string>

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing sound id from sound manager
     */
    struct csoundid_t {
        std::string sound; ///< sound string to find in sound list
    };
}

#endif /* !CSOUNDID_HPP_ */
