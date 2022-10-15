/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CDamage
*/

#ifndef CDAMAGE_HPP_
    #define CDAMAGE_HPP_

    #include <iostream>

/**
 * @brief Namespace for all components
 * 
 */
namespace component {
    /**
     * @brief A structure representing the damage component that holds the damage of an entity
     * 
     */
    typedef struct cdamage_s {
        size_t damage;
    } cdamage_t;
}

#endif /* !CDAMAGE_HPP_ */
