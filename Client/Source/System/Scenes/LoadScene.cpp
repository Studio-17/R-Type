/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** LoadScene
*/

#include "LoadScene.hpp"
#include "Constant.hpp"

LoadScene::LoadScene()
{
    _removedScenes = {};
    _setupScene = {};
    _execScene = {};
    setUpMenuScene();
    setUpExecMenuScene();
    setUpDelMenuScene();
    setUpSettingsScene();
    setUpExecSettingsScene();
    setUpDelSettingsScene();
}

LoadScene::LoadScene(LoadScene &&other) noexcept : _graphicLib(other._graphicLib), _removedScenes(other._removedScenes), _setupScene(other._setupScene), _execScene(other._execScene)
{
}

void LoadScene::operator()(Sparse_array<component::currScene_t> &currentScene, Sparse_array<component::keyboard_t> &keyboard, Sparse_array<component::mouseState_t> &mouse)
{
    SCENE prevScene = SCENE::MENU;

    for (auto &scene : currentScene) {
        if (!scene->isLoaded) {
            _removedScenes[prevScene]();
            _setupScene[currentScene[FORBIDDEN_IDS::GRAPHIC]->currScene](currentScene);
        }
    }
    _execScene[currentScene[FORBIDDEN_IDS::GRAPHIC]->currScene](currentScene);
}