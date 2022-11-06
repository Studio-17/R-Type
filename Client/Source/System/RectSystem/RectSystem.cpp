/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** RectSystem
*/

#include "RectSystem.hpp"
#include "Constant.hpp"

System::RectSystem::RectSystem()
{
}

void System::RectSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::crect_t> &rectangles, Sparse_array<component::ctimer_t> &timer, [[ maybe_unused ]] Sparse_array<component::ctype_t> &types, Sparse_array<component::casset_t> &assets, Sparse_array<component::cassetid_t> &assetId)
{
    if ((std::chrono::steady_clock::now() - timer[FORBIDDEN_IDS::NETWORK].value().animTimer) > (std::chrono::nanoseconds)100000000)
        timer[FORBIDDEN_IDS::NETWORK].value().animTimer = std::chrono::steady_clock::now();
    else
        return;
    for (std::size_t i = 0; i < rectangles.size(); i++) {
        if (rectangles[i] && assetId[i]) {
            auto &rect = rectangles[i];
            auto &id = assetId[i];
            // auto &type = types[i];

            if (id) {
                if (rect.value().current_frame == rect.value().nb_frames)
                    rect.value().current_frame = 0;
                rect.value().x = assets[FORBIDDEN_IDS::NETWORK].value().assets.at(assetId[i].value().assets).getTexture().getWidth() / rect.value().nb_frames * rect.value().current_frame;
                rect.value().current_frame++;
            }
        }
    }
}