/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CType
*/

#ifndef CTYPE_HPP_
    #define CTYPE_HPP_

    #include "Serialization.hpp"

/**
 * @brief A namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the type component of an entity
     */
    struct ctype_t {
        ENTITY_TYPE type; ///< type of the entity
    };
}

#endif /* !CTYPE_HPP_ */
