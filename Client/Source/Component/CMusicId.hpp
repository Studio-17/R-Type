/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CMusicId
*/

#ifndef CMUSICID_HPP_
    #define CMUSICID_HPP_

    #include <string>

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing music id from music manager
     */
    struct cmusicid_t {
        std::string music; ///< music string to find in music list
    };
}

#endif /* !CMUSICID_HPP_ */
