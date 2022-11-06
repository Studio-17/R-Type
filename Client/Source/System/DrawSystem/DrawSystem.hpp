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

    /* Component */
    #include "Component/CPosition.hpp"
    #include "Component/CRect.hpp"
    #include "Component/CAsset.hpp"
    #include "Component/CAssetId.hpp"
    #include "Component/CSceneId.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief DrawSystem class that handles the drawing of all the entities
     */
    class DrawSystem {
        public:
            /**
             * @brief Construct a new Event System object
             */
            DrawSystem();
            ~DrawSystem() = default;

            /**
             * @brief Update the DrawSystem
             *
             * @param registry The registry of the server
             * @param positions The sparse array of position entities
             * @param rectangles The sparse array of rectangle entities
             * @param assets The sparse array of asset entities
             * @param assetsId The sparse array of assetId entities
             * @param scenesId The sparse array of sceneId entities
             */
            void operator()(Registry &registry, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rectangles, Sparse_array<component::casset_t> &assets, Sparse_array<component::cassetid_t> &assetsId, Sparse_array<component::csceneid_t> &scenesId);


        protected:
        private:
            std::shared_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
    };
}


#endif //R_TYPE_DRAWSYSTEM_H
