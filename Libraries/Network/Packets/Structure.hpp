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

    #include "Serialization.hpp"

struct IdCard {
    int id;

    int age;
    char sex;
};

struct ServerResponse {
    int code;

    bool status;
};

struct td {
    int pt;
    int second;
};
struct Header {
    int id;
    int data;
    td pr;
};

template <>
struct serializable_trait<Header> {
    static std::vector<byte> serialize(Header const &obj) {
        std::vector<byte> ret;

        ret = serializable_trait<int>::serialize(obj.id);
        auto tmp = serializable_trait<int>::serialize(obj.data);
        ret.insert(ret.end(), tmp.begin(), tmp.end());
        tmp = serializable_trait<td>::serialize(obj.pr);
        ret.insert(ret.end(), tmp.begin(), tmp.end());
        return ret;
    };

    static Header unserialize(std::vector<byte> &v) {
        Header s;
        std::vector<byte> tmp;
        tmp.resize(sizeof(td));
        std::memcpy(&s.id , v.data(), sizeof(int));
        std::memcpy(&s.data , v.data() + sizeof(int), sizeof(int));
        std::memcpy(&s.pr, v.data() + (sizeof(int) * 2), sizeof(td));
        return s;
    }
};

#endif /* !DATA_HPP_ */
