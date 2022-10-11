/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CurrScene
*/

#ifndef CURRSCENE_HPP_
    #define CURRSCENE_HPP_

    #include "Constant.hpp"

/**
 * @brief Namespace for all components
 *
 */
namespace component {
    /**
     * @brief Structure representing the current scene loaded
     *
     */
    typedef struct currScene_s {
        SCENE currScene; ///< Current scene loaded
        bool isLoaded; ///< Is the scene loaded
    } currScene_t;
}

#endif /* !CURRSCENE_HPP_ */
