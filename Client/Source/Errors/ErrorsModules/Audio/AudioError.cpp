/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-martin.vanaud
** File description:
** AudioError
*/

#include "AudioError.hpp"

Error::AudioError::AudioError(std::string const &message) throw()
: Errors("Raylib Audio: " + message)
{
}

Error::AudioError::~AudioError()
{
}