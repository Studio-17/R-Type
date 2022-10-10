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
    _working(true)
{
    _socket = std::make_shared<asio::ip::udp::socket>(io_service_, asio::ip::udp::endpoint(asio::ip::udp::v4(), 8081));

	asio::ip::udp::resolver resolver(io_service_);
	asio::ip::udp::resolver::query query(asio::ip::udp::v4(), ip, port);
	asio::ip::udp::resolver::iterator iter = resolver.resolve(query);
	_destination = *iter;

    _network = std::make_unique<Network>(ip, port);
    _registry = std::make_unique<Registry>();
    setUpEcs();
    machineRun();
}

Client::~Client()
{
	_socket->close();
}

void Client::machineRun(void)
{
	Header header {.id = 8, .data = 4, .pr = {.pt = 3, .second = 9}};
	auto buffer_to_send = serializable_trait<Header>::serialize(header);
	_socket->send_to(asio::buffer(buffer_to_send.data(), buffer_to_send.size()), _destination);
    std::cout << "sended" << std::endl;
	// // receive();
    // while (_working) {
    //     _registry.get()->run_systems();
    // }
}

void Client::setUpEcs(void)
{
}
