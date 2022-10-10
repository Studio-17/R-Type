/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Server
*/

#include <functional>

#include "Server.hpp"

Server::Server(short const port) : _com(std::make_shared<UdpCommunication>(_context, port))
{
    ReceivePackets();
    _context.run();
}

Server::~Server()
{
}

void Server::ReceivePackets()
{
    std::cout << "receive" << std::endl;
    buffer_to_get.clear();
    buffer_to_get.resize(1500);
    _com->async_receive(buffer_to_get, std::bind(&Server::SendPackets, this, std::placeholders::_1, std::placeholders::_2));

}

void Server::SendPackets(asio::error_code const &e, std::size_t nbBytes)
{
    // std::map<std::size_t, std::function<void(std::vector<byte>)>> my_map;
    // int id;
    // std::memcpy(&id , buffer_to_get.data(), sizeof(int));
    // my_map.at(id)(buffer_to_get);
    Header tt = serializable_trait<Header>::unserialize(buffer_to_get);
    // Header tt = serializable_trait<packet<>>::unserialize(buffer_to_get);
    // function_to_call.at(tt.id)(tt.data);
    // Header tt = serializable_trait<Header>::unserialize(buffer_to_get);
    std::cout << "header: "<< tt.id << std::endl;
    ServerResponse ok = {
        .code = 200,

        .status = true,
    };

    std::vector<byte> buffer_to_send;

    buffer_to_send.reserve(sizeof(ServerResponse));

    std::memcpy(buffer_to_send.data(), &ok, sizeof(ServerResponse));

    _com->async_send(buffer_to_send, std::bind(&Server::CompleteExchnage, this, std::placeholders::_1, std::placeholders::_2));
}

void Server::CompleteExchnage(std::error_code const &e, std::size_t nbBytes)
{
    ReceivePackets();
}