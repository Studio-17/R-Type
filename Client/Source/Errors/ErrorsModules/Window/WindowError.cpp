/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
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
