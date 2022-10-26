/*
** EPITECH PROJECT, 2020
** DrawSystem.h
** File description:
** header for DrawSystem.c
*/

#ifndef R_TYPE_DRAWSYSTEM_H
    #define R_TYPE_DRAWSYSTEM_H

    #include "Registry.hpp"
    #include "GraphicalLib.hpp"
    #include "CSprite.hpp"
    #include "CPosition.hpp"
    #include "CRect.hpp"

/**
 * @brief DrawSystem class that handles the drawing of all the entities
 *
 */
class DrawSystem {
    public:
        /**
        * @brief Construct a new Event System object
         *
         */
        DrawSystem();
        /**
         * @brief Destroy the Event System object
         *
         */
        ~DrawSystem() = default;

        /**
         * @brief Function that will be automaticaly called while the client is working (on loop)
         *
         * @param registry The registry that contains all the ECS
         * @param positions Sparse array of all position component of all entities
         * @param rectangles Sparse array of all rectangle component of all entities
         */
        void operator()(Registry &registry, Sparse_array<component::csprite_t> &sprites, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rectangles);

    protected:
    private:
        std::shared_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
};


#endif //R_TYPE_DRAWSYSTEM_H
