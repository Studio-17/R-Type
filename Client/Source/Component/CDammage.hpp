/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CDammage
*/

#ifndef CDAMMAGE_HPP_
    #define CDAMMAGE_HPP_

    #include <cstddef>

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the dammage component that holds the dammage of an entity
     */
    struct cdammage_t {
        std::size_t dammage; ///< dammage of the entity
    };
}

#endif /* !CDAMMAGE_HPP_ */
