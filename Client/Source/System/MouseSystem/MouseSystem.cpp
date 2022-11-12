/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** MouseSystem
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>

#include "MouseSystem.hpp"

/* Constant */
#include "Constant.hpp"

System::MouseSystem::MouseSystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
}

void System::MouseSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rects, Sparse_array<component::csceneid_t> &scenesId, Sparse_array<component::ctype_t> &types, Sparse_array<component::ccallback_t> &callbacks, [[ maybe_unused ]] Sparse_array<component::cref_t> &refs, Sparse_array<component::crefid_t> &refIds, Sparse_array<component::csound_t> &sounds, Sparse_array<component::csoundid_t> &soundIds)
{
    for (std::size_t i = 1; i < positions.size() && i < rects.size() && i < scenesId.size() && i < types.size() && i < refIds.size() && i < soundIds.size(); i++) {
        if (positions[i] && rects[i] && scenesId[i] && types[i] && refIds[i]) {
            auto &rect = rects[i];
            auto &scene = scenesId[i];
            auto &type = types[i];
            auto &pos = positions[i];
            auto &callback = callbacks[i];

            if (scenesId[FORBIDDEN_IDS::NETWORK].value().sceneId == scene->sceneId && _graphicLib->checkMouseCollision(_graphicLib->getMousePosition(), pos->x, pos->y, rect->width, rect->height)) {
                if (type->type == ENTITY_TYPE::INPUT_BOX) {
                    callback.value().callback();
                }
                if (type->type == ENTITY_TYPE::BUTTON && _graphicLib->IsLeftMouseButtonPressed()) {
                    _graphicLib->playASound(sounds[FORBIDDEN_IDS::NETWORK].value().sounds.at(soundIds[i].value().sound).getSound());
                    callback.value().callback();
                }
            }
        }
    }
}