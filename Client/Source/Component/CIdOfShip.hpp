/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CIdOfShip
*/

#ifndef CIDOFSHIP_HPP_
    #define CIDOFSHIP_HPP_

    #include <cstdint>

    /**
     * @brief Namespace for all components
     */
    namespace component {
        /**
         * @brief A structure representing the id of your ship
         */
        struct cid_of_ship_t {
            uint16_t id; ///< Server id of ship entity
        };
    }



#endif /* !CIDOFSHIP_HPP_ */
