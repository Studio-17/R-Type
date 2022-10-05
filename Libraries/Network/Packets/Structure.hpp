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

struct IdCard {
    int id;

    int age;
    char sex;
};

struct ServerResponse {
    int code;

    bool status;
};

#endif /* !DATA_HPP_ */
