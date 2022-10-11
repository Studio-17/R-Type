/*
** EPITECH PROJECT, 2020
** DrawSystem.cpp
** File description:
** header for DrawSystem.c
*/

#include "DrawSystem.hpp"

DrawSystem::DrawSystem()
{
    _graphicLib = std::make_shared<rtype::GraphicalLib>();
}

void  DrawSystem::operator()(Registry &registry, Sparse_array<component::csprite_t> &sprites, Sparse_array<component::cposition_t> &positions)
{
    for (std::size_t i = 0; i < sprites.size() && i < positions.size(); i++) {
        auto &sp = sprites[i];
        auto &pos = positions[i];

        _graphicLib->drawSprite(sp->sprite, (Position){pos->x, pos->y, 0});
    }
}
