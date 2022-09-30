/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-martin.vanaud
** File description:
** PositionError
*/

#include "PositionError.hpp"

Error::PositionError::PositionError(std::string const &message) throw()
: Errors("Position: " + message)
{
}

Error::PositionError::~PositionError()
{
}