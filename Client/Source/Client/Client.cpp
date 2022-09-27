/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#include <iostream>

#include "Client.hpp"

Client::Client(boost::asio::io_service &io_service, std::string const &host, std::string const &port)
    : io_service_(io_service), socket_(io_service, udp::endpoint(udp::v4(), 0))
{
	udp::resolver resolver(io_service_);
	udp::resolver::query query(udp::v4(), host, port);
	udp::resolver::iterator iter = resolver.resolve(query);
	endpoint_ = *iter;
    std::cout << endpoint_.port() << std::endl;
}

Client::~Client()
{
	socket_.close();
}

void Client::send(const std::string& msg)
{
	socket_.send_to(boost::asio::buffer(msg, msg.size()), endpoint_);
}

std::string Client::receive(void) {
    std::array<char, 1024> buffer;
	socket_.receive_from(boost::asio::buffer(buffer), endpoint_);
    return buffer.data();
}