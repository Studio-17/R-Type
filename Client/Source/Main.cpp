/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Main
*/

#include <iostream>
#include <cstdlib>

#include "Client.hpp"
#include "Network/Network.hpp"

static void printHelper()
{
	std::cout << "Helper" << std::endl;
}

static bool isGoodArguments(std::string const &ip, std::string const &port, std::string const &hostPort)
{
	return true;
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
