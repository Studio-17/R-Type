/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Errors
*/

#include "Errors.hpp"

Error::Errors::Errors(std::string const &message) throw() : _message(message)
{
}

Error::Errors::~Errors() throw()
{
}

const char *Error::Errors::what() const throw()
{
	return _message.c_str();
}