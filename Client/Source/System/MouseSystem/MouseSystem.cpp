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

void MouseSystem::operator()(Registry &registry, Sparse_array<component::cposition_t> &positions, Sparse_array<component::crect_t> &rects, Sparse_array<component::csceneid_t> &sceneId, Sparse_array<component::ctype_t> &types)
{

}