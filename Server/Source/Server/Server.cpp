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
    std::vector<char> buffer_to_get;
    position struct_to_get;
    buffer_to_get.reserve(sizeof(struct_to_get));

    _socket->receive_from(boost::asio::buffer(buffer_to_get.data(), sizeof(struct_to_get)), _endpoint);
    std::memcpy(reinterpret_cast<char *>(&struct_to_get), buffer_to_get.data(), sizeof(struct_to_get));

    std::cout << "id: " << struct_to_get.id << std::endl;
    std::cout << "x: " << struct_to_get.x << std::endl;
    std::cout << "y: " << struct_to_get.y << std::endl;
}

void Server::handleReceive(const boost::system::error_code &e, std::size_t nbBytes)
{
    if (!e) {
        struct position p = {
            .id = 1,
            .x = 10,
            .y = 7
        };

        std::vector<char> buffer_to_send;

        buffer_to_send.reserve(sizeof(p));
        std::memcpy(buffer_to_send.data(), &p, sizeof(p));
        _socket->send_to(boost::asio::buffer(buffer_to_send.data(), sizeof(p)), _endpoint);
    } else {
        std::cout << e.message() << std::endl;
    }
}

void Server::handleSend(std::shared_ptr<std::string> message, const boost::system::error_code &ec, std::size_t bytes)
{
    startReceive();
}
