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
    : _socket(service, udp::endpoint(udp::v4(), port))
{
    startReceive();
}

Server::~Server()
{
}

void Server::startReceive()
{
    std::fill_n(_buffer.begin(), _buffer.size(), 0);
    _socket.async_receive_from(boost::asio::buffer(_buffer), _endpoint, boost::bind(&Server::handleReceive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Server::handleReceive(const boost::system::error_code &e, std::size_t nbBytes)
{
    if (!e) {
        std::string buffer = _buffer.data();

        std::cout << "message: " << _buffer.data() << " " << _endpoint.port() << std::endl;
        _socket.async_send_to(boost::asio::buffer(buffer, buffer.size()), _endpoint, boost::bind(&Server::handleSend, this, std::make_shared<std::string>(buffer), boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    }
}

void Server::handleSend(std::shared_ptr<std::string> message, const boost::system::error_code &ec, std::size_t bytes)
{
    startReceive();
}
