/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CRef
*/

#ifndef CREF_HPP_
    #define CREF_HPP_

    #include <string>
    #include <map>

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the ref component that holds the ref of an entity text or button
     */
    struct cref_t {
        std::map<std::string, Entity> ref; ///< ref of the entity
    };
}

#endif /* !CREF_HPP_ */
