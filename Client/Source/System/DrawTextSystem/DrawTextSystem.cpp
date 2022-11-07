/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** DrawTextSystem
*/

#include "DrawTextSystem.hpp"
#include "Constant.hpp"

System::DrawTextSystem::DrawTextSystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
}

void System::DrawTextSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cposition_t> &positions, Sparse_array<component::csceneid_t> &scenesId, Sparse_array<component::cscale_t> &scales, Sparse_array<component::ccolor_t> &colors, Sparse_array<component::ctext_t> &texts)
{
    for (std::size_t i = 1; i < positions.size() && i < scenesId.size() && i < scales.size() && i < texts.size() && i < colors.size(); i++) {
        if (positions[i] && scenesId[i] && scales[i] && texts[i] && colors[i]) {
            auto &pos = positions[i];
            auto &scene = scenesId[i];
            auto &scale = scales[i];
            auto &text = texts[i];
            auto &color = colors[i];

            if (scene.value().sceneId == scenesId[FORBIDDEN_IDS::NETWORK].value().sceneId || scene.value().sceneId == SCENE::ALL)
                _graphicLib->drawText(text.value().text, (Position){pos.value().x, pos.value().y, 0}, static_cast<std::size_t>(scale.value().scale), color.value().color);
        }
    }
}