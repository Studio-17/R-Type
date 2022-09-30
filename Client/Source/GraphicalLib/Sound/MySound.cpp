/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Sound
*/

#include "MySound.hpp"

MySound::MySound(std::string const &filename)
{
}

MySound::~MySound()
{
    UnloadSound(_sound);
}

void MySound::play()
{
    PlaySound(_sound);
}

void MySound::stop()
{
    StopSound(_sound);
}

void MySound::pause()
{
    PauseSound(_sound);
}

void MySound::resume()
{
    ResumeSound(_sound);
}

bool MySound::isPlaying()
{
    return (IsSoundPlaying(_sound));
}

void MySound::setVolume(float volume)
{
    SetSoundVolume(_sound, volume);
}