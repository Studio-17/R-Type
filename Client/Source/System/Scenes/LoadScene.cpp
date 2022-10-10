/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** LoadScene
*/

#include "LoadScene.hpp"
#include "Constant.hpp"

#include "Component/Mouse.hpp"
#include "Component/CSprite.hpp"
#include "Component/Keyboard.hpp"
#include "Component/CPosition.hpp"

LoadScene::LoadScene()
{
    _graphicLib = std::make_shared<rtype::GraphicalLib>(800, 600, "R-Type", 60);
}

LoadScene::LoadScene(LoadScene &&other) noexcept : _graphicLib(other._graphicLib), _execScene(other._execScene)
{
}

void LoadScene::operator()(Registry &registry, Sparse_array<component::currScene_t> &currentScene, Sparse_array<component::keyboard_t> &keyboard, Sparse_array<component::mouseState_t> &mouse)
{
    std::vector<int> spriteID;

    if (!currentScene[FORBIDDEN_IDS::GRAPHIC].value().isLoaded) {
        Entity spaceshipId = registry.spawn_entity();
        component::csprite_t sprite = {1.0, 0, 0, 300, 100, "Assets/sprites/r-typesheet5.gif"};
        component::cposition_t position = {0, 0};

        registry.add_component<component::csprite_t>(registry.entity_from_index(spaceshipId), std::move(sprite));
        registry.add_component<component::cposition_t>(registry.entity_from_index(spaceshipId), std::move(position));
        _graphicLib->createSprite(spaceshipId, registry.get_components<component::csprite_t>()[spaceshipId].value().spritePath, {0, 0}, 1);
        spriteID.push_back(spaceshipId);
        auto &scene = currentScene[FORBIDDEN_IDS::GRAPHIC];

        if (scene)
            scene->isLoaded = true;
    }
    _graphicLib->startDrawingWindow();
        for (auto &i : spriteID)
            _graphicLib->drawSprite(i);
    _graphicLib->endDrawingWindow();

    for (auto &i : spriteID) {
        _graphicLib->destroySprite(i);
    }
}