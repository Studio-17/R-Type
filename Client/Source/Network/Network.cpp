/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Network
*/

#include <iostream>
#include "Network.hpp"

Network::Network(std::string const &host, std::string const &port)
{
	// udp::resolver resolver(io_service_);
	// udp::resolver::query query(udp::v4(), host, port);
	// udp::resolver::iterator iter = resolver.resolve(query);
	// endpoint_ = *iter;
    // std::cout << endpoint_.port() << std::endl;
}

Network::~Network()
{
}

void Network::send(const std::string& msg)
{
	    struct position p = {
            .id = 2,
            .x = 20,
            .y = 14
        };
        std::vector<char> buffer_to_send;

        buffer_to_send.reserve(sizeof(p));
        std::memcpy(buffer_to_send.data(), &p, sizeof(p));
        // socket_.send_to(asio::buffer(buffer_to_send.data(), sizeof(p)), endpoint_);
}

std::string Network::receive(void)
{

	std::vector<char> buffer_to_get;
    position struct_to_get;
    buffer_to_get.reserve(sizeof(struct_to_get));

    // socket_.receive_from(asio::buffer(buffer_to_get.data(), sizeof(struct_to_get)), endpoint_);
    std::memcpy(reinterpret_cast<char *>(&struct_to_get), buffer_to_get.data(), sizeof(struct_to_get));

    std::cout << "id: " << struct_to_get.id << std::endl;
    std::cout << "x: " << struct_to_get.x << std::endl;
    std::cout << "y: " << struct_to_get.y << std::endl;

	return ("hello");
}

void Network::test(void)
{
    send("Hello, World!");
    std::cout << receive()<< std::endl;
    // io_service_.run();
}