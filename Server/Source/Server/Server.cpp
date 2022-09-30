/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Server
*/

#include <iostream>

#include <boost/bind.hpp>
#include <boost/function.hpp>

#include "Server.hpp"

Server::Server(boost::asio::io_service &service, short const port)
{
    _socket = std::make_shared<udp::socket>(service, udp::endpoint(udp::v4(), port));

    ReceivePackets();
}

Server::~Server()
{
}

void Server::ReceivePackets()
{
    IdCard martin;

    std::vector<char> buffer_to_get;

    buffer_to_get.reserve(sizeof(IdCard));

    _socket->async_receive_from(boost::asio::buffer(buffer_to_get.data(), sizeof(IdCard)), _destination, boost::bind(&Server::SendPackets, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

    std::memcpy(reinterpret_cast<char *>(&martin), buffer_to_get.data(), sizeof(IdCard));

    std::cout << "------------HEADER-------------" << std::endl;
	std::cout << "    source: 127.0.0.1:8080     " << std::endl;
	std::cout << "  destination: " << _destination.address() << ":" << _destination.port() << "  " << std::endl;
	std::cout << "     size: " << buffer_to_get.size() << "      " << std::endl;
    std::cout << "         BODY  RECEIVED        " << std::endl;
    std::cout << "-------------BEGIN-------------" << std::endl;
    std::cout << martin.id << std::endl;
    std::cout << martin.age << std::endl;
    std::cout << martin.sex << std::endl;
    std::cout << "--------------END--------------" << std::endl;

}

void Server::SendPackets(const boost::system::error_code &e, std::size_t nbBytes)
{
    ServerResponse ok = {
        .code = 200,

        .status = true,
    };

    std::vector<char> buffer_to_send;

    buffer_to_send.reserve(sizeof(ServerResponse));

    std::memcpy(buffer_to_send.data(), &ok, sizeof(ServerResponse));

    _socket->async_send_to(boost::asio::buffer(buffer_to_send.data(), sizeof(ServerResponse)), _destination, boost::bind(&Server::CompleteExchnage, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void Server::CompleteExchnage(const boost::system::error_code &e, std::size_t nbBytes)
{
    ReceivePackets();
}
