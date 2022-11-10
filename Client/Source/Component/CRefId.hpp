/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CRefId
*/

#ifndef CREFID_HPP_
    #define CREFID_HPP_

    #include <string>
    #include <map>
    #include <vector>

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the ref component that holds the ref of an entity text or button
     */
    struct crefid_t {
        std::string refId; ///< ref of the entity
    };
}

#endif /* !CREFID_HPP_ */
