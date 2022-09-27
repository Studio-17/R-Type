/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#include <iostream>

#include "Client.hpp"

Client::Client(boost::asio::io_service &io_service, std::string const &host, std::string const &port)
    : io_service_(io_service), _socket(io_service, udp::endpoint(udp::v4(), 0))
{
	udp::resolver resolver(io_service_);
	udp::resolver::query query(udp::v4(), host, port);
	udp::resolver::iterator iter = resolver.resolve(query);
	_destination = *iter;
    std::cout << _destination.port() << std::endl;
}

Client::~Client()
{
	_socket.close();
}

void Client::send(const std::string& msg)
{

}

std::string Client::receive(void)
{
	return ("empty");
}
