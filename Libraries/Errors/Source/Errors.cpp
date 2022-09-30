/*
** EPITECH PROJECT, 2022
** B-EPI-000-PAR-0-0-projectname-user.email
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