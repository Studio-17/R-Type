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
    _nameInput = "";
    _ipInput = "";
    _portInput = "";

    _input =  {
        {"name-input", std::bind(&System::MouseSystem::updateNameInput, this, std::placeholders::_1)},
        {"ip-input", std::bind(&System::MouseSystem::updateIpInput, this, std::placeholders::_1)},
        {"port-input", std::bind(&System::MouseSystem::updatePortInput, this, std::placeholders::_1)}
    };
}

void System::MouseSystem::updateNameInput(Registry &registry)
{
    int key = _graphicLib->getPressedCharcode();
    Sparse_array<component::cref_t> &ref = registry.get_components<component::cref_t>();
    Sparse_array<component::ctext_t> &content = registry.get_components<component::ctext_t>();
    Entity test = registry.entity_from_index(static_cast<std::size_t>(ref[FORBIDDEN_IDS::NETWORK].value().ref.at("text-name-input")));

    while (key > 0) {
        if ((key >= 32) && (key <= 125) && _nameInput.length() < 10) {
            _nameInput += static_cast<char>(key);
            content[test].value().text = _nameInput;
        }
        key = _graphicLib->getPressedCharcode();
    }
    if (_graphicLib->hasBeenReleased(KEY_BACKSPACE) && _nameInput.length() > 0) {
        _nameInput.pop_back();
        content[test].value().text = _nameInput;
    }
}

void System::MouseSystem::updateIpInput(Registry &registry)
{
    int key = _graphicLib->getPressedCharcode();
    Sparse_array<component::cref_t> &ref = registry.get_components<component::cref_t>();
    Sparse_array<component::ctext_t> &content = registry.get_components<component::ctext_t>();
    Entity test = registry.entity_from_index(static_cast<std::size_t>(ref[FORBIDDEN_IDS::NETWORK].value().ref.at("text-ip-input")));

    while (key > 0) {
        if ((key >= 32) && (key <= 125) && _ipInput.length() < 16) {
            _ipInput += static_cast<char>(key);
            content[test].value().text = _ipInput;
        }
        key = _graphicLib->getPressedCharcode();
    }
    if (_graphicLib->hasBeenReleased(KEY_BACKSPACE) && _ipInput.length() > 0) {
        _ipInput.pop_back();
        content[test].value().text = _ipInput;
    }
}

void System::MouseSystem::updatePortInput(Registry &registry)
{
    int key = _graphicLib->getPressedCharcode();
    Sparse_array<component::cref_t> &ref = registry.get_components<component::cref_t>();
    Sparse_array<component::ctext_t> &content = registry.get_components<component::ctext_t>();
    Entity test = registry.entity_from_index(static_cast<std::size_t>(ref[FORBIDDEN_IDS::NETWORK].value().ref.at("text-port-input")));

    while (key > 0) {
        if ((key >= 32) && (key <= 125) && _portInput.length() < 5) {
            _portInput += static_cast<char>(key);
            content[test].value().text = _portInput;
        }
        key = _graphicLib->getPressedCharcode();
    }
    if (_graphicLib->hasBeenReleased(KEY_BACKSPACE) && _portInput.length() > 0) {
        _portInput.pop_back();
        content[test].value().text = _portInput;
    }
}

void System::MouseSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rects, Sparse_array<component::csceneid_t> &scenesId, Sparse_array<component::ctype_t> &types, Sparse_array<component::ccallback_t> &callbacks, [[ maybe_unused ]] Sparse_array<component::cref_t> &refs, Sparse_array<component::crefid_t> &refIds)
{
    for (std::size_t i = 1; i < positions.size() && i < rects.size() && i < scenesId.size() && i < types.size() && i < refIds.size(); i++) {
        if (positions[i] && rects[i] && scenesId[i] && types[i] && refIds[i]) {
            auto &rect = rects[i];
            auto &scene = scenesId[i];
            auto &type = types[i];
            auto &pos = positions[i];
            auto &callback = callbacks[i];
            auto &refId = refIds[i];

            if (scenesId[FORBIDDEN_IDS::NETWORK].value().sceneId == scene->sceneId && _graphicLib->checkMouseCollision(_graphicLib->getMousePosition(), pos->x, pos->y, rect->width, rect->height)) {
                if (type->type == ENTITY_TYPE::INPUT_BOX) {
                    if (_input.find(refId.value().refId) != _input.end())
                        _input.at(refId.value().refId)(registry);
                }
                if (type->type == ENTITY_TYPE::BUTTON && _graphicLib->IsLeftMouseButtonPressed()) {
                    callback.value().callback();
                }
            }
        }
    }
}