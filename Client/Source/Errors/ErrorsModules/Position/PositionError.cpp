/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
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