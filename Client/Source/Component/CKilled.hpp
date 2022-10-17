/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CKilled
*/

#ifndef CKILLED_HPP_
    #define CKILLED_HPP_

/**
 * @brief Namespace for all components
 *
 */
namespace component {
    /**
     * @brief Structure representing the status of the entity. if true, entity is dead
     *
     */
    typedef struct ckilled_s {
        bool isDead;
    } ckilled_t;
}

#endif /* !CKILLED_HPP_ */
