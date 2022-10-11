/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Server
*/

#include <functional>

#include "Server.hpp"

Server::Server(short const port) : _com(std::make_shared<UdpCommunication>(_context, port))
    //_thread(&Server::threadLoop, this), _stop(false)
{
    ReceivePackets();
    _context.run();
}

Server::~Server()
{
    // _stop = true;
    // _thread.join();
    _context.stop();
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
    std::cout << "readed" << std::endl;
    std::pair<asio::ip::address, unsigned short> endpointData = _com->getEnpointInfo();
    _endpoints.try_emplace(endpointData.first, std::unordered_map<unsigned short, bool>());
    _endpoints.at(endpointData.first).try_emplace(endpointData.second, true);

    Header tt = serializable_trait<Header>::unserialize(buffer_to_get);
    std::cout << "header: "<< tt.id << std::endl;
    ServerResponse ok = {
        .code = 200,

        .status = true,
    };

    std::vector<byte> buffer_to_send = serializable_trait<ServerResponse>::serialize(ok);

    for (auto const &[address, portList] : _endpoints) {
        for (auto const &port : portList) {
            _com->async_send(buffer_to_send, std::bind(&Server::CompleteExchnage, this, std::placeholders::_1, std::placeholders::_2), address, port.first);
            std::cout << "send " << address<<" "<< port.first << std::endl;
        }
    }
}

void Server::CompleteExchnage(std::error_code const &e, std::size_t nbBytes)
{
    ReceivePackets();
}

void Server::threadLoop()
{
    // while (!_stop) {
    // }
}