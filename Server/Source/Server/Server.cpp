/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Server
*/

#include <iostream>
#include <boost/bind.hpp>

#include "Server.hpp"

Server::Server(boost::asio::io_service &service, short const port)
{
    _socket = std::make_shared<boost::asio::ip::udp::socket>(service, udp::endpoint(udp::v4(), port));

    startReceive();
}

Server::~Server()
{
}

void Server::startReceive()
{
    // _communicationModule.receive(_socket, _destination, &handleReceive);
}

void Server::handleReceive(const boost::system::error_code &e, std::size_t nbBytes)
{
    // _communicationModule.send(_socket, _destination, structure, &handleSend);
}

void Server::handleSend(std::shared_ptr<std::string> message, const boost::system::error_code &ec, std::size_t bytes)
{
    startReceive();
}
