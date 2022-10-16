/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Main
*/

#include <iostream>
#include <cstdlib>
#include <regex>

#include "Client.hpp"

static void printHelper()
{
	std::cout << "./r-type_client [ip] [port] [hostPort]" << std::endl;
}

static bool isGoodArguments(std::string const &ip, std::string const &port, std::string const &hostPort)
{
    std::regex portRegex("^[0-9]{1,5}$");
    std::regex ipRegex("^[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}$");

    if (std::regex_match(port, portRegex) && std::regex_match(hostPort, portRegex))
        return true;
    else {
        std::cout << "The port must be between 0 and 99999" << std::endl;
        return false;
    }

    if (std::regex_match(ip, ipRegex))
        return true;
    else {
        std::cout << "The ip address must match the following pattern ^[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}$" << std::endl;
        return false;
    }
}

int main(int ac, char const * const* av)
{
	if (ac != 4 || !isGoodArguments(av[1], av[2], av[3])) {
		printHelper();
		return (0);
	}

	std::string currentHost;
	strcmp(av[1], "localhost") == 0 ? currentHost = "127.0.0.1" : currentHost = av[1];

	Client client(currentHost, std::string(av[2]), std::atoi(av[3]));

    client.machineRun();

    return (0);
}
