/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** RectSystem
*/

#ifndef RECTSYSTEM_HPP_
    #define RECTSYSTEM_HPP_

    #include "Registry.hpp"
    #include "GraphicalLib.hpp"
    #include "CSprite.hpp"
    #include "CRect.hpp"

/**
 * @brief System that draws a part of all entities
 */
class RectSystem {
    public:
        /**
        * @brief Construct a new Rect System object
         *
         */
        RectSystem();
        /**
         * @brief Destroy the Rect System object
         *
         */
        ~RectSystem() = default;

         /**
         * @brief Function that will be automaticaly called while the client is working (on loop)
         *
         * @param registry The registry that contains all the ECS
         * @param sprites Sparse array of all sprite component of all entities
         * @param rectangles Sparse array of all rectangle component of all entities
         */
        void operator()(Registry &registry, Sparse_array<component::csprite_t> &sprites, Sparse_array<component::crect_t> &rectangles);

    protected:
    private:
        std::shared_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
};

#endif /* !RECTSYSTEM_HPP_ */
