/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** LoadScene
*/

#ifndef LOADSCENE_HPP_
    #define LOADSCENE_HPP_

    #include "SparseArray.hpp"
    #include "Keyboard.hpp"
    #include "Mouse.hpp"
    #include "CurrScene.hpp"
    #include <functional>
    #include <map>

class LoadScene {
    public:
        LoadScene();
        LoadScene(LoadScene &&other) noexcept;
        ~LoadScene() = default;

        void operator()(Sparse_array<component::currScene_t> &currentScene, Sparse_array<component::keyboard_t> &keyboard, Sparse_array<component::mouseState_t> &mouse);

        // Menu Scene
        void setUpMenuScene();
        void setUpExecMenuScene();
        void setUpDelMenuScene();

        // Settings Scene
        void setUpSettingsScene();
        void setUpExecSettingsScene();
        void setUpDelSettingsScene();


    protected:
    private:
        int _graphicLib; // replace by unique_ptr to graphic lib

        std::map<SCENE, std::function<void()>> _removedScenes;
        std::map<SCENE, std::function<void(Sparse_array<component::currScene_t> &currentScenes)>> _setupScene;
        std::map<SCENE, std::function<void(Sparse_array<component::currScene_t> &currentScenes)>> _execScene;
};

#endif /* !LOADSCENE_HPP_ */
