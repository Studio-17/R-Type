/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Systems
*/

#ifndef SYSTEMS_HPP_
#define SYSTEMS_HPP_

#include "Registry.hpp"
#include "SparseArray.hpp"
#include "raylib.h"

void loggingSystem(Sparse_array<component::position_t> &pos, Sparse_array<component::velocity_t> &velo)
{
    for (size_t i = 0; i < pos.size() && i < velo.size(); i++) {
        if (pos[i] && velo[i]) {
            std::cout << "Object position (x): " << pos[i].value().x << std::endl;
            std::cout << "Object position (y): " << pos[i].value().y << std::endl;
            std::cout << "Object velocity (x): " << velo[i].value().vx << std::endl;
            std::cout << "Object velocity (y): " << velo[i].value().vy << std::endl;
        }
    }
}

void printSystem(Sparse_array<component::position_t> &pos, Sparse_array<component::drawable_t> &draw)
{
    for (size_t i = 0; i < pos.size() && i < draw.size(); i++) {
        if (pos[i] && draw[i]) {
            std::cout << "print system" << std::endl;
            DrawTexture(draw[i].value().texture, pos[i].value().x, pos[i].value().y, WHITE);
        }
    }
}

void controlSystem(Sparse_array<component::position_t> &pos, Sparse_array<component::velocity_t> &velo, Sparse_array<component::controllable_t> &control)
{
    for (size_t i = 0; i < pos.size() && i < velo.size() && i < control.size(); i++) {
        if (pos[i] && velo[i] && control[i] && control[i].value().isControllable) {
            if (IsKeyPressed(KEY_LEFT)) {
                pos[i].value().x = pos[i].value().x - 10;
            }
        }
    }
}

#endif /* !SYSTEMS_HPP_ */
