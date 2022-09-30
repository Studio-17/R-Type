/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#include <iostream>

#include "Client.hpp"

Client::Client(std::string const &ip, std::string const &port) :
    _working(true)
{
    _network = std::make_unique<Network>(ip, port);
    _registry = std::make_unique<Registry>();
    setUpEcs();
    machineRun();
}

void Client::machineRun(void)
{
    while (_working) {
        _registry.get()->run_systems();
    }
}

void Client::setUpEcs(void)
{
}

Client::~Client()
{
}