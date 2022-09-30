/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** FileError
*/

#include "FileError.hpp"

Error::FileError::FileError(std::string const &message) throw()
: Errors("File: " + message)
{
}

Error::FileError::~FileError()
{
}