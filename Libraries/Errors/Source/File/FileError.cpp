/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-martin.vanaud
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