/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Main
*/

#include <regex>

#include "Server.hpp"

static void printHelper()
{
    std::cout << "./r-type_server [port]" << std::endl;
}

static bool check_port(std::string const &port)
{
    if (std::regex_match(port, std::regex("^[0-9]{1,5}$")))
        return true;
    std::cout << "The port must be between 0 and 99999" << std::endl;
    return false;
}

int main(int ac, char **av)
{
    if (ac != 2 || !check_port(std::string(av[1]))) {
        printHelper();
        return 84;
    }

    Server server(std::stoi(av[1]));

    return 0;
}
