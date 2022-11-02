/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CSceneId
*/

#ifndef CSCENEID_HPP_
    #define CSCENEID_HPP_

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
    typedef struct csceneid_s {
        SCENE sceneId; ///< Id of a scene linked to the enum SCENE
    } csceneid_t;
}

#endif /* !CSCENEID_HPP_ */
