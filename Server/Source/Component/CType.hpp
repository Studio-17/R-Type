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
 * 
 */
namespace component {
    /**
     * @brief A structure representing the type component of an entity
     * 
     */
    typedef struct ctype_s {
        ENTITY_TYPE type;
    } ctype_t;
}

#endif /* !CTYPE_HPP_ */