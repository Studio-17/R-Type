/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** MenuScene
*/

#include "LoadScene.hpp"

#include "Constant.hpp"

void LoadScene::setUpMenuScene()
{
    _setupScene[SCENE::MENU] = std::function(
        [this](Sparse_array<component::currScene_t> &currentScene) -> void {
            auto &scene = currentScene[FORBIDDEN_IDS::GRAPHIC];

            if (scene)
                scene->isLoaded = true;
        }
    );
}

void LoadScene::setUpExecMenuScene()
{
    _execScene[SCENE::MENU] = std::function(
        [this](Sparse_array<component::currScene_t> &currentScene) -> void {
            std::cout << "Exec menu" << std::endl;
        }
    );
}

void LoadScene::setUpDelMenuScene()
{
    _removedScenes[SCENE::MENU] = std::function(
        [this]() -> void {
            std::cout << "Del menu" << std::endl;
        }
    );
}
