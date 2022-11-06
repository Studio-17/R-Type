/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Text
*/

#ifndef CTEXT_HPP_
    #define CTEXT_HPP_

    #include <string>

/**
 * @brief A namespace for all components
 * 
 */
namespace component {
    /**
     * @brief A structure representing the text component to add text and font to an entity
     * 
     */
    typedef struct ctext_s {
        std::string text;
    } ctext_t;
}

#endif /* !CTEXT_HPP_ */
