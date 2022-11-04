/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** fileConfig
*/

#ifndef FILECONFIG_HPP_
    #define FILECONFIG_HPP_

    #include <nlohmann/json.hpp>

nlohmann::json getJsonData(std::string const &filepath);


#endif /* !FILECONFIG_HPP_ */
