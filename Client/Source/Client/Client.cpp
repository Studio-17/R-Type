/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#include <iostream>

#include "Client.hpp"

Client::Client(boost::asio::io_service &io_service, std::string const &host, std::string const &port)
    : io_service_(io_service)
{
	_socket = std::make_shared<udp::socket>(io_service, udp::endpoint(udp::v4(), 8081));

	udp::resolver resolver(io_service_);
	udp::resolver::query query(udp::v4(), host, port);
	udp::resolver::iterator iter = resolver.resolve(query);
	_destination = *iter;
}

Client::~Client()
{
	_socket->close();
}

void Client::send()
{
	IdCard clement = {
		.id = 2,
		.age = 19,

		.sex = 'M',
	};

    std::vector<char> buffer_to_send;

    buffer_to_send.reserve(sizeof(IdCard));

    std::memcpy(buffer_to_send.data(), &clement, sizeof(IdCard));

	_socket->send_to(boost::asio::buffer(buffer_to_send.data(), sizeof(IdCard)), _destination);

	receive();
}

std::string Client::receive(void)
{
	ServerResponse response;

	std::vector<char> buffer_to_get;

    buffer_to_get.reserve(sizeof(ServerResponse));

    _socket->receive_from(boost::asio::buffer(buffer_to_get.data(), sizeof(ServerResponse)), _destination);

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
