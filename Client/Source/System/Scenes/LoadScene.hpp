/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** LoadScene
*/

#ifndef LOADSCENE_HPP_
    #define LOADSCENE_HPP_

    #include "SparseArray.hpp"
    #include "CKeyboard.hpp"
    #include "Mouse.hpp"
    #include "CurrScene.hpp"
    #include "GraphicalLib.hpp"
    #include "Registry.hpp"

    #include <functional>
    #include <map>
    #include <memory>

class LoadScene {
    public:
        LoadScene();
        LoadScene(LoadScene &&other) noexcept;
        ~LoadScene() = default;

        void operator()(Registry &registry, Sparse_array<component::currScene_t> &currentScene, Sparse_array<component::ckeyboard_t> &keyboard, Sparse_array<component::mouseState_t> &mouse);

        // Graphic
        std::shared_ptr<rtype::GraphicalLib> getGraphicalLib() const
        {
            return _graphicLib;
        };


    protected:
    private:
         std::shared_ptr<rtype::GraphicalLib> _graphicLib;

         std::map<SCENE, std::function<void(Registry &registry)>> _removedScenes;
         std::map<SCENE, std::function<void(Registry &registry, Sparse_array<component::currScene_t> &currentScenes)>> _setupScene;
         std::map<SCENE, std::function<void(Registry &registry, Sparse_array<component::currScene_t> &currentScenes)>> _execScene;
};

#endif /* !LOADSCENE_HPP_ */
