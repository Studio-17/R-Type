/*
** EPITECH PROJECT, 2020
** DrawSystem.cpp
** File description:
** header for DrawSystem.c
*/

#include "DrawSystem.hpp"
#include "Constant.hpp"

DrawSystem::DrawSystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
}

void DrawSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rectangles, Sparse_array<component::casset_t> &assets, Sparse_array<component::cassetid_t> &assetsId, Sparse_array<component::csceneid_t> &scenesId, Sparse_array<component::cscale_t> &scales)
{
    for (std::size_t i = 1; i < positions.size() && i < rectangles.size() && i < scenesId.size() && i < scales.size(); i++) {
        if (positions[i] && rectangles[i] && scenesId[i] && scales[i]) {
            auto &pos = positions[i];
            auto &rect = rectangles[i];
            auto &scene = scenesId[i];
            auto &scale = scales[i];

            if (!assets[FORBIDDEN_IDS::NETWORK])
                continue;
            if (scene.value().sceneId == scenesId[FORBIDDEN_IDS::NETWORK].value().sceneId || scene.value().sceneId == SCENE::ALL) {
                std::array<float, 4> rectSource = {rect.value().x, rect.value().y, rect.value().width * scale.value().scale, rect.value().height * scale.value().scale};
                std::array<float, 4> rectDest = {pos.value().x, pos.value().y, rect.value().width * scale.value().scale, rect.value().height * scale.value().scale};
                _graphicLib->drawRectanglePro(assets[FORBIDDEN_IDS::NETWORK].value().assets.at(assetsId[i].value().assets).getTexture(), rectSource, rectDest, std::pair<float, float>{0, 0}, 0, scale.value().scale);
            }
        }
    }
}
