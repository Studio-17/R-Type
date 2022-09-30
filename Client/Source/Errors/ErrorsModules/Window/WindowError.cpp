/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-martin.vanaud
** File description:
** WindowError
*/

#include "WindowError.hpp"

Error::WindowError::WindowError(std::string const &message) throw()
: Errors("Raylib Window: " + message)
{
}

Error::WindowError::~WindowError()
{
}
