/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
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