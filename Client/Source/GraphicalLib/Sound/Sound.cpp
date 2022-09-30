/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Sound
*/

#include "Sound.hpp"

Sound::Sound(std::string const &filename)
{
}

Sound::~Sound()
{
    UnloadSound(_sound);
}

void Sound::play()
{
    PlaySound(_sound);
}

void Sound::stop()
{
    StopSound(_sound);
}

void Sound::pause()
{
    PauseSound(_sound);
}

void Sound::resume()
{
    ResumeSound(_sound);
}

bool Sound::isPlaying()
{
    return (IsSoundPlaying(_sound));
}

void Sound::setVolume(float volume)
{
    SetSoundVolume(_sound, volume);
}