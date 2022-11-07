/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** DrawTextSystem
*/

#ifndef DRAWTEXTSYSTEM_HPP_
    #define DRAWTEXTSYSTEM_HPP_

    #include "Registry.hpp"
    #include "GraphicalLib.hpp"
    #include "CPosition.hpp"
    #include "CSceneId.hpp"
    #include "CScale.hpp"
    #include "CColor.hpp"
    #include "CText.hpp"
    #include "Constant.hpp"

/**
 * @brief DrawTextSystem class that handles the drawing of all the sprite entities
 *
 */
class DrawTextSystem {
    public:
        /**
        * @brief Construct a new Event System object
         *
         */
        DrawTextSystem();
        /**
         * @brief Destroy the Event System object
         *
         */
        ~DrawTextSystem() = default;

        /**
         * @brief Update the DrawTextSystem
         * 
         * @param registry the registry of the server
         * @param positions the sparse array of position entities
         * @param scenesId the sparse array of sceneId entities
         * @param scales the sparse array of scale entities
         * @param colors the sparse array of color entities
         * @param texts the sparse array of text entities
         */
        void operator()(Registry &registry,
                        Sparse_array<component::cposition_t> &positions,
                        Sparse_array<component::csceneid_t> &scenesId,
                        Sparse_array<component::cscale_t> &scales,
                        Sparse_array<component::ccolor_t> &colors,
                        Sparse_array<component::ctext_t> &texts);

    protected:
    private:
        std::shared_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
};

#endif /* !DRAWTEXTSYSTEM_HPP_ */
