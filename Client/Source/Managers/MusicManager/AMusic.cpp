/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** AMusic
*/

#include <array>
#include <iostream>

#include "AMusic.hpp"

AMusic::AMusic(nlohmann::json const &jsonData) :
    _music(jsonData.value("musicPath", "Assets/Sounds/menu-music.ogg"))
{
}

MyMusic &AMusic::getMusic()
{
    return _music;
}
