/*
** EPITECH PROJECT, 2020
** DrawSpriteSystem.h
** File description:
** header for DrawSpriteSystem.c
*/

#ifndef R_TYPE_DRAWSPRITESYSTEM_H
    #define R_TYPE_DRAWSPRITESYSTEM_H

    /* Ecs */
    #include "Registry.hpp"

    /* Graphical Lib */
    #include "GraphicalLib.hpp"

    /* Component */
    #include "Component/CPosition.hpp"
    #include "Component/CRect.hpp"
    #include "Component/CAsset.hpp"
    #include "Component/CAssetId.hpp"
    #include "Component/CSceneId.hpp"
    #include "Component/CScale.hpp"
    #include "Component/CMusic.hpp"
    #include "Component/CMusicId.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief DrawSpriteSystem class that handles the drawing of all the sprite entities
     *
     */
    class DrawSpriteSystem {
        public:
            /**
             * @brief Construct a new Draw System object
             *
             */
            DrawSpriteSystem();
            ~DrawSpriteSystem() = default;

            /**
             * @brief Update the DrawSpriteSystem
             *
             * @param registry the registry of the server
             * @param positions the sparse array of position entities
             * @param rectangles the sparse array of rectangle entities
             * @param assets the sparse array of asset entities
             * @param assetsId the sparse array of assetId entities
             * @param scenesId the sparse array of sceneId entities
             * @param scales the sparse array of scale entities
             * @param musics the sparse array of music entities
             * @param musicsId the sparse array of musicId entities
             */
            void operator()(Registry &registry,
                            Sparse_array<component::cposition_t> &positions,
                            Sparse_array<component::crect_t> &rectangles,
                            Sparse_array<component::casset_t> &assets,
                            Sparse_array<component::cassetid_t> &assetsId,
                            Sparse_array<component::csceneid_t> &scenesId,
                            Sparse_array<component::cscale_t> &scales,
                            Sparse_array<component::cmusic_t> &musics,
                            Sparse_array<component::cmusicid_t> &musicsId);

            protected:
            private:
                std::shared_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
    };
}


#endif //R_TYPE_DRAWSPRITESYSTEM_H
