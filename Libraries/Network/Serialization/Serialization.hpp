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

struct serialize_header {
    template<class Seriazable>
    static std::vector<byte> serializeHeader(u_int8_t id, Seriazable const &obj)
    {
        std::vector<byte> bytes;
        bytes.resize(sizeof(u_int8_t));

        memcpy(bytes.data(), &id, sizeof(u_int8_t));
        std::vector<byte> data = serializable_trait<Seriazable>::serialize(obj);
        bytes.insert(bytes.end(), data.begin(), data.end());
        return bytes;
    };

    static u_int8_t getId(std::vector<byte> const &bytes)
    {
        u_int8_t id;
        memcpy(&id, bytes.data(), sizeof(u_int8_t));
        return id;
    };
};

#endif /* !SERIALIZATION_HPP_ */

