/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** SettingsScene
*/

#include "LoadScene.hpp"


void LoadScene::setUpSettingsScene()
{
    _setupScene[SCENE::SETTINGS] = std::function(
        [this](Sparse_array<component::currScene_t> &currentScene) -> void {
            auto &scene = currentScene[FORBIDDEN_IDS::GRAPHIC];

            if (scene)
                scene->isLoaded = true;
        }
    );
}

void LoadScene::setUpExecSettingsScene()
{
    _execScene[SCENE::SETTINGS] = std::function(
        [this](Sparse_array<component::currScene_t> &currentScene) -> void {
            // std::cout << "Exec settings" << std::endl;
        }
    );
}

void LoadScene::setUpDelSettingsScene()
{
    _removedScenes[SCENE::SETTINGS] = std::function(
        [this]() -> void {
            // std::cout << "Del settings" << std::endl;
        }
    );
}
