/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** MyMusic
*/

#include "MyMusic.hpp"
#include <stdexcept>

MyMusic::MyMusic(std::string const &filename) :
    _music(LoadMusicStream(filename.c_str()))
{
    if (_music.frameCount == 0)
        throw std::runtime_error("Error while loading music" + filename);
    _volume = 1;
}

MyMusic::~MyMusic()
{
    // UnloadMusicStream(_music);
}

void MyMusic::play()
{
    PlayMusicStream(_music);
}

void MyMusic::stop()
{
    StopMusicStream(_music);
}

void MyMusic::pause()
{
    PauseMusicStream(_music);
}

void MyMusic::resume()
{
    ResumeMusicStream(_music);
}

bool MyMusic::isPlaying() const
{
    return (IsMusicStreamPlaying(_music));
}

float MyMusic::getVolume() const
{
    return (_volume);
}

void MyMusic::setVolume(float volume)
{
    SetMusicVolume(_music, volume);
    _volume = volume;
}

void MyMusic::updateStream()
{
    UpdateMusicStream(_music);
}
