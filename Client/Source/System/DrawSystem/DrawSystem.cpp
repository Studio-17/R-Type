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

void DrawSystem::operator()(Registry &registry, Sparse_array<component::csprite_t> &sprites, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rectangles, Sparse_array<component::ckilled_t> &killed)
{
    for (std::size_t i = 1; i < sprites.size() && i < positions.size() && i < rectangles.size(); i++) {
        auto &sp = sprites[i];
        auto &pos = positions[i];
        auto &rect = rectangles[i];

        if (!killed[i]->isDead)
            _graphicLib->drawSprite(sp->sprite, (Position){pos->x, pos->y, 0}, (Rectangle){.x = rect->x, .y = rect->y, .width = rect->width, .height = rect->height});
    }
}
