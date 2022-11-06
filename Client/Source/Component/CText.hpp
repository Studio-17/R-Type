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
 */
namespace component {
    /**
     * @brief A structure representing the text component to add text and font to an entity
     */
    struct ctext_t {
        std::string pathToFont; ///< path to load the font
        std::string textToPrint; ///< text to print
        size_t fontSize; ///< size of the text to print (of the font)
    };
}

#endif /* !CTEXT_HPP_ */
