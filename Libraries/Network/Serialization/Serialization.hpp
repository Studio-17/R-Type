/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Serialization
*/

#ifndef SERIALIZATION_HPP_
    #define SERIALIZATION_HPP_

    #include <vector>
    #include <iostream>

using byte = unsigned char;

template <class Serializable>
struct serializable_trait {
    static std::vector<byte> serialize(Serializable const &obj) {
        std::vector<byte> ret;

        ret.resize(sizeof(Serializable));
        std::memcpy(ret.data(), std::addressof(obj), sizeof(Serializable));
        return ret;
    }

    static Serializable unserialize(std::vector<byte> &v) {
        Serializable s;

        std::memcpy(&s, v.data(), sizeof(Serializable));
        // CALL_HANDLER<Serializable>(s);
        return s;
    }
};

#endif /* !SERIALIZATION_HPP_ */

