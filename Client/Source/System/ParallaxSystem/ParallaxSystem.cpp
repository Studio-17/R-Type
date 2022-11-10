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

void System::ParallaxSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cref_t> &refs, Sparse_array<component::cposition_t> &pos)
{
    for (std::size_t i = 1; i < refs.size() && i < pos.size(); i++) {
        if (refs[i] && pos[i]) {
            for (auto &parallax : _parallax) {
                // std::string tmp = refs[0].value().ref.at(parallax);
                // refs[0].value().ref.at("nb-players-in-lobby-txt")

                // if (refs[0].value().ref.find(parallax) != refs[0].value().ref.end()) {
                //     if (pos[i].value().x <= -1930) {
                //         std::cout << "ParallaxSystem: " << parallax << " reset" << std::endl;
                //         pos[i].value().x = 1930;
                //     }
                // }
            }
        }
    }
}