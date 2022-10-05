/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Server
*/

#include "Server.hpp"

Server::Server(asio::io_service &service, short const port)
{
    _socket = std::make_shared<asio::ip::udp::socket>(service, asio::ip::udp::endpoint(asio::ip::udp::v4(), port));

    ReceivePackets();
}

Server::~Server()
{
}

void Server::ReceivePackets()
{
    buffer_to_get.clear();
    buffer_to_get.resize(1500);
    _socket->async_receive_from(asio::buffer(buffer_to_get.data(), 1500), _destination, bind(&Server::SendPackets, this, asio::placeholders::error, asio::placeholders::bytes_transferred));
}

void Server::SendPackets(const std::error_code &e, std::size_t nbBytes)
{
    buffer_to_get.shrink_to_fit();

    std::cout << "unserialized "<< serializable_trait<Header>::unserialize(buffer_to_get).id << std::endl;
    ServerResponse ok = {
        .code = 200,

        .status = true,
    };

    std::vector<char> buffer_to_send;

    buffer_to_send.reserve(sizeof(ServerResponse));

    std::memcpy(buffer_to_send.data(), &ok, sizeof(ServerResponse));

    _socket->async_send_to(asio::buffer(buffer_to_send.data(), sizeof(ServerResponse)), _destination, bind(&Server::CompleteExchnage, this, asio::placeholders::error, asio::placeholders::bytes_transferred));
}

void Server::CompleteExchnage(const std::error_code &e, std::size_t nbBytes)
{
    ReceivePackets();
}