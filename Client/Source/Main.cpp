/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Main
*/

#include <iostream>
#include <cstdlib>
#include <regex>
#include <algorithm>

#include "Client.hpp"

static std::map<std::string, std::string> getConfigurationFiles(char const * const* av)
{
    std::map<std::string, std::string> configurations;
    std::regex jsonRegex("[A-Za-z0-9-_]+.json");

    for (int index = 1; av[index]; index += 1) {
        if (std::regex_search(av[index], jsonRegex)) {

            std::string filepath(av[index]);
            std::string base_filename = filepath.substr(filepath.find_last_of("/\\") + 1);
            std::string::size_type const p(base_filename.find_last_of('.'));
            std::string file_without_extension = base_filename.substr(0, p);
            std::for_each(file_without_extension.begin(), file_without_extension.end(), [](char & c) {
                c = ::toupper(c);
            });

            configurations.insert({file_without_extension, av[index]});
        }
    }

    if (configurations.empty())
        exit(84);

    return configurations;
}

int main([[maybe_unused]] int ac, char const * const* av)
{
    std::map<std::string, std::string> configurationFiles = getConfigurationFiles(av);

	Client client(std::string("localhost"), std::string("8080"), 8081, configurationFiles);
	// Client client(std::string("10.68.248.125"), std::string("8080"), 8081, configurationFiles);

    client.machineRun();

    return (0);
}
