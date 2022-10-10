/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#include <iostream>

#include "Client.hpp"
#include "Serialization.hpp"
#include "Structure.hpp"

Client::Client(std::string const &ip, std::string const &port) :
    _working(true), _com(std::make_unique<UdpCommunication>(_context, 8081, port, ip)),
    _registry(std::make_unique<Registry>())
{
    _context.run();
    setUpEcs();
    machineRun();
}

Client::~Client()
{
}

void Client::machineRun(void)
{
	Header header {.id = 8, .data = 4, .pr = {.pt = 3, .second = 9}};
	auto buffer_to_send = serializable_trait<Header>::serialize(header);
	_com->send(buffer_to_send);
    std::cout << "sended" << std::endl;
	// // receive();
    // while (_working) {
    //     _registry.get()->run_systems();
    // }
}

void Client::setUpEcs(void)
{
}
