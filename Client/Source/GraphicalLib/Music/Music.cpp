/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Music
*/

#include "Music.hpp"

Music::Music(std::string const &filename) : _music(LoadMusicStream(filename.c_str()))
{
    if (!_music.ctxData)
        throw Error::AudioError("MyMusic initialization failed");
}

Music::~Music()
{
    UnloadMusicStream(_music);
}

void Music::play()
{
    PlayMusicStream(_music);
}

void Music::stop()
{
    StopMusicStream(_music);
}

void Music::pause()
{
    PauseMusicStream(_music);
}

void Music::resume()
{
    ResumeMusicStream(_music);
}

bool Music::isPlaying() const
{
    return (IsMusicStreamPlaying(_music));
}

void Music::setVolume(float volume)
{
    SetMusicVolume(_music, volume);
}

void Music::updateMusicStream()
{
    UpdateMusicStream(_music);
}
