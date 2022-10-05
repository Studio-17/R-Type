/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Main
*/

#include <iostream>

//#include "Client.hpp"
//#include "Network/Network.hpp"

void printHelper(void)
{
	std::cout << "Helper" << std::endl;
}

bool isGoodArguments(std::string ip, std::string port)
{
	return true;
}

int main(int ac, char **av)
{
	if (ac != 3 || !isGoodArguments(av[1], av[2])) {
		printHelper();
		return (0);
	}
//	std::string currentHost;
//	strcmp(av[1], "localhost") == 0 ? currentHost = "127.0.0.1" : currentHost = av[1];
//	Client client(currentHost, av[2]);
	return (0);
}
