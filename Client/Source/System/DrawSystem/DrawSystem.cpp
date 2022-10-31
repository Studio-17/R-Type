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
    _currScene = SCENE::GAME;
}

void DrawSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rectangles, Sparse_array<component::casset_t> &assets, Sparse_array<component::cassetid_t> &assetsId, Sparse_array<component::ccurrscene_t> &currScene)
{
    for (std::size_t i = 1; i < positions.size() && i < rectangles.size() && i < currScene.size(); i++) {
        if (positions[i] && rectangles[i] && currScene[i]) {
            auto &pos = positions[i];
            auto &rect = rectangles[i];
            auto &scene = currScene[i];

            if (!assets[FORBIDDEN_IDS::NETWORK])
                continue;
            if (scene.value().currScene == _currScene || scene.value().currScene == SCENE::ALL)
                _graphicLib->drawSprite(assets[FORBIDDEN_IDS::NETWORK].value().assets.at(assetsId[i].value().assets).getTexture(), (Position){pos.value().x, pos.value().y, 0}, (Rectangle){.x = rect.value().x, .y = rect.value().y, .width = rect.value().width, .height = rect.value().height});
        }
    }
}
