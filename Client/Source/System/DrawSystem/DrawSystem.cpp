/*
** EPITECH PROJECT, 2020
** DrawSystem.cpp
** File description:
** header for DrawSystem.c
*/

#include "DrawSystem.hpp"

DrawSystem::DrawSystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
}

void DrawSystem::operator()(Registry &registry, Sparse_array<component::csprite_t> &sprites, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rectangles)
{
    for (std::size_t i = 1; i < sprites.size() && i < positions.size() && i < rectangles.size(); i++) {
        if (sprites[i] && positions[i] && rectangles[i]) {
            auto &sp = sprites[i];
            auto &pos = positions[i];
            auto &rect = rectangles[i];

            _graphicLib->drawSprite(sp.value().sprite, (Position){pos.value().x, pos.value().y, 0}, (Rectangle){.x = rect.value().x, .y = rect.value().y, .width = rect.value().width, .height = rect.value().height});
        }
    }
}
