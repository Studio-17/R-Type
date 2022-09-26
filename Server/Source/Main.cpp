/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Main
*/

#include <iostream>

#include "Server.hpp"
#include "Data.hpp"

int main(void)
{
    try {
        boost::asio::io_service service;

        Server server(service, 8080);

        service.run();
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
