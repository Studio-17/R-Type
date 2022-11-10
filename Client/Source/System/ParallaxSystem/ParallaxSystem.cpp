/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** ParallaxSystem
*/

#include "ParallaxSystem.hpp"

System::ParallaxSystem::ParallaxSystem()
{
    _parallax = {
        "parallax-background1-img",
        "parallax-background2-img",
        "parallax-ground1-img",
        "parallax-ground2-img",
        "parallax-mountain1-img",
        "parallax-mountain2-img"
    };
}

void System::ParallaxSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::crefid_t> &refIds, Sparse_array<component::cposition_t> &pos)
{
    for (std::size_t i = 1; i < refIds.size() && i < pos.size(); i++) {
        if (refIds[i] && pos[i]) {
            for (auto &parallax : _parallax) {
                if (refIds[i].value().refId == parallax) {
                    if (pos[i].value().x <= -1930) {
                        pos[i].value().x = 1930;
                    }
                }
            }
        }
    }
}