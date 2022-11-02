/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** MouseSystem
*/

#include "MouseSystem.hpp"

MouseSystem::MouseSystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
}

void MouseSystem::operator()([[ maybe_unused ]] Registry &registry, [[ maybe_unused ]] Sparse_array<component::cposition_t> &positions, [[ maybe_unused ]] Sparse_array<component::crect_t> &rects, [[ maybe_unused ]] Sparse_array<component::csceneid_t> &scenesId, [[ maybe_unused ]] Sparse_array<component::ctype_t> &types)
{
    Position mouse = _graphicLib->getMousePosition();

    for (std::size_t i = 1; i < positions.size() && i < rects.size() && i < scenesId.size() && i < types.size(); i++) {
        if (positions[i] && rects[i] && scenesId[i] && types[i]) {
            auto &rect = rects[i];
            auto &scene = scenesId[i];
            auto &type = types[i];
            auto &pos = positions[i];

            if (type->type == ENTITY_TYPE::BUTTON && scenesId[FORBIDDEN_IDS::NETWORK].value().sceneId == scene->sceneId && _graphicLib->checkMouseCollision(_graphicLib->getMousePosition(), pos->x, pos->y, rect->width, rect->height) && _graphicLib->IsLeftMouseButtonPressed())
                scenesId[FORBIDDEN_IDS::NETWORK].value().sceneId = SCENE::GAME;
        }
    }
}