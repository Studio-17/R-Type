/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Text
*/

#ifndef TEXT_HPP_
    #define TEXT_HPP_

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
    typedef struct text_s {
        std::string pathToFont;
        std::string textToPrint;
        size_t fontSize;
    } text_t;
}

#endif /* !TEXT_HPP_ */
