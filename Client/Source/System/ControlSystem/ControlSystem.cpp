/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** ControlSystem
*/

#include "ControlSystem.hpp"
#include "CSprite.hpp"
#include "CRect.hpp"
#include "CPosition.hpp"

ControlSystem::ControlSystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
}

void ControlSystem::operator()(Registry &registry, Sparse_array<component::cposition_t> &positions, Sparse_array<component::velocity_t> &velocities, Sparse_array<component::ckeyboard_t> &keyboards)
{
    for (std::size_t i = 0; i < positions.size() && i < velocities.size() && i < keyboards.size(); i++) {
        auto &pos = positions[i];
        auto &vel = velocities[i];
        auto &key = keyboards[i];

        if (pos && vel) {
            if (key->keyboard->isBeingPressed(key->keyboard->getKeyUpCharCode()))
                pos->y -= vel->velocity;
            if (key->keyboard->isBeingPressed(key->keyboard->getKeyDownCharCode()))
                pos->y += vel->velocity;
            if (key->keyboard->isBeingPressed(key->keyboard->getKeyLeftCharCode()))
                pos->x -= vel->velocity;
            if (key->keyboard->isBeingPressed(key->keyboard->getKeyRightCharCode()))
                pos->x += vel->velocity;
            if (key->keyboard->hasBeenPressed(key->keyboard->getKeySpaceCharCode())) {
                Entity bullet = registry.spawn_entity();

                component::crect_t rect = {0, 0, 18, 17, 1, 8};
                registry.add_component<component::crect_t>(registry.entity_from_index(bullet), std::move(rect));

                component::csprite_t sprite = {.sprite = _graphicLib->createSprite("Assets/sprites/r-typesheet3.gif", 1, (Rectangle){.x = rect.x, .y = rect.y, .width = rect.width, .height = rect.height})};
                registry.add_component<component::csprite_t>(registry.entity_from_index(bullet), std::move(sprite));

                component::cposition_t position = {10, 150};
                registry.add_component<component::cposition_t>(registry.entity_from_index(bullet), std::move(position));
            }
        }
    }
}
