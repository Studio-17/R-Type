/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Sound
*/

#include <array>
#include <iostream>

#include "ASound.hpp"

ASound::ASound(nlohmann::json const &jsonData) :
    _sound(jsonData.value("soundPath", "Assets/Sounds/click_sound.ogg"))
{
}

MySound &ASound::getSound()
{
    return _sound;
}