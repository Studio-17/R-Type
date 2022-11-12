/*
** EPITECH PROJECT, 2020
** DrawSystem.cpp
** File description:
** header for DrawSystem.c
*/

#include "DrawSpriteSystem.hpp"

/* Constant */
#include "Constant.hpp"

System::DrawSpriteSystem::DrawSpriteSystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
}

void System::DrawSpriteSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rectangles, Sparse_array<component::casset_t> &assets, Sparse_array<component::cassetid_t> &assetsId, Sparse_array<component::csceneid_t> &scenesId, Sparse_array<component::cscale_t> &scales, Sparse_array<component::cmusic_t> &musics, Sparse_array<component::cmusicid_t> &musicsId)
{
    for (std::size_t i = 1; i < positions.size() && i < rectangles.size() && i < scenesId.size() && i < assetsId.size() && i < scales.size(); i++) {
        if (positions[i] && scenesId[i] && scales[i] && rectangles[i]) {
            auto &pos = positions[i];
            auto &scene = scenesId[i];
            auto &scale = scales[i];
            auto &rect = rectangles[i];

            // (void)musicsId;
            _graphicLib->updateAMusic(musics[FORBIDDEN_IDS::NETWORK].value().musics.at(musicsId[FORBIDDEN_IDS::NETWORK].value().music).getMusic());
            if (!assets[FORBIDDEN_IDS::NETWORK])
                continue;
            if (scene.value().sceneId == scenesId[FORBIDDEN_IDS::NETWORK].value().sceneId || scene.value().sceneId == SCENE::ALL) {
                std::array<float, 4> rectSource = {rect.value().x, rect.value().y, rect.value().width * scale.value().scale, rect.value().height * scale.value().scale};
                std::array<float, 4> rectDest = {pos.value().x, pos.value().y, rect.value().width * scale.value().scale, rect.value().height * scale.value().scale};
                _graphicLib->drawSprite(assets[FORBIDDEN_IDS::NETWORK].value().assets.at(assetsId[i].value().assets).getTexture(), rectSource, rectDest, std::pair<float, float>{0, 0}, 0, scale.value().scale);
            }
        }
    }
}
