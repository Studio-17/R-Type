/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** RectSystem
*/

#include "RectSystem.hpp"

RectSystem::RectSystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
}

void RectSystem::operator()(Registry &registry, Sparse_array<component::csprite_t> &sprites, Sparse_array<component::crect_t> &rectangles)
{
    for (std::size_t i = 0; i < sprites.size() && i < rectangles.size(); i++) {
        auto &sp = sprites[i];
        auto &rect = rectangles[i];

        if (rect->current_frame == rect->nb_frames)
            rect->current_frame = 1;
        rect->x = sp->sprite->getWidth() / rect->nb_frames * rect->current_frame;
        rect->current_frame++;
    }
}