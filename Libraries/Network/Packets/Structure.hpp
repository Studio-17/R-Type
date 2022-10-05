/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Data
*/

#ifndef DATA_HPP_
#define DATA_HPP_

#include <string>
#include <cstdbool>

#include <boost/cstdint.hpp>

struct IdCard {
    int_least32_t id;

    int_least32_t age;
    char sex;
};

struct ServerResponse {
    int_least32_t code;

    bool status;
};

struct Header {
    int id;
};

#endif /* !DATA_HPP_ */
