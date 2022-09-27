/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Main
*/

#include <iostream>
#include "Client.hpp"

int main()
{
	boost::asio::io_service io_service;
	Client client(io_service, "localhost", "8080");

	client.send("Hello, World!");
    std::cout << client.receive()<< std::endl;
    io_service.run();

}