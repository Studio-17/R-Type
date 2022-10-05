/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#include <iostream>

#include "Client.hpp"
#include "Serialization.hpp"

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
	_socket->close();
}

void Client::send()
{
	Header header {.id = 8};
	auto buffer_to_send = serializable_trait<Header>::serialize(header);
	_socket->send_to(asio::buffer(buffer_to_send.data(), buffer_to_send.size()), _destination);
	// receive();
}

std::string Client::receive(void)
{
	ServerResponse response;

	std::vector<char> buffer_to_get;

    buffer_to_get.reserve(sizeof(ServerResponse));

    _socket->receive_from(asio::buffer(buffer_to_get.data(), sizeof(ServerResponse)), _destination);

    std::memcpy(reinterpret_cast<char *>(&response), buffer_to_get.data(), sizeof(ServerResponse));

    std::cout << "------------HEADER-------------" << std::endl;
	std::cout << "    source: 127.0.0.1:8080     " << std::endl;
	std::cout << "  destination: " << _destination.address() << ":" << _destination.port() << "  " << std::endl;
	std::cout << "     size: " << buffer_to_get.size() << "      " << std::endl;
    std::cout << "         BODY  RECEIVED        " << std::endl;
    std::cout << "-------------BEGIN-------------" << std::endl;
	std::cout << "code: " << response.code << std::endl;
	std::cout << "status: " << response.status << std::endl;
    std::cout << "--------------END--------------" << std::endl;
}
