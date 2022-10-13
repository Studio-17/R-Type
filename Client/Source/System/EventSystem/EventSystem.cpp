/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** EventSystem
*/

#include "EventSystem.hpp"

systemNamespace::EventSystem::EventSystem()
{
    _graphicLib = 2; // Need to add graphical lib
}

void systemNamespace::EventSystem::operator()(Registry &registry, Sparse_array<component::mouseState_t> &mouses, Sparse_array<component::ckeyboard_t> &keyboards)
{
    for (size_t i = 0; i < keyboards.size(); i++) {
        
    }
    for (size_t i = 0; i < mouses.size(); i++) {
        mouses[i].value().xPos = 1;
    }
}
