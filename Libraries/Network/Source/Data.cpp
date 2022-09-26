/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Data
*/

#include "Data.hpp"

Data::Data(std::string const &data)
{
    _data = data;
}

Data::~Data()
{
}

Data::operator std::string()
{
    return _data;
}
