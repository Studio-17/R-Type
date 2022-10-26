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

void DrawSystem::operator()(Registry &registry, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rectangles, Sparse_array<component::ckilled_t> &killed, Sparse_array<component::casset_t> &assets, Sparse_array<component::cassetid_t> &assetsId)
{
    for (std::size_t i = 1;/* i < sprites.size() &&*/ i < positions.size() && i < rectangles.size(); i++) {
        // auto &sp = sprites[i];
        auto &pos = positions[i];
        auto &rect = rectangles[i];
        if (!assets[FORBIDDEN_IDS::NETWORK])
            continue;
        if (!killed[i]->isDead) {
            _graphicLib->drawSprite(assets[FORBIDDEN_IDS::NETWORK]->assets.at(assetsId[i]->assets).getTexture(), (Position){pos->x, pos->y, 0}, (Rectangle){.x = rect->x, .y = rect->y, .width = rect->width, .height = rect->height});
            // _graphicLib->drawSprite(sp->sprite, (Position){pos->x, pos->y, 0}, (Rectangle){.x = rect->x, .y = rect->y, .width = rect->width, .height = rect->height});
        }
    }
}
