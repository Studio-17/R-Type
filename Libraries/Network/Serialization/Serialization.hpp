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
    #include <cstring>
    #include "Shoot.hpp"

namespace NETWORK_CLIENT_TO_SERVER {
    enum PACKET_TYPE {
        SHOOT,
        DIRECTION
    };
};

namespace NETWORK_SERVER_TO_CLIENT {
    enum PACKET_TYPE {
        POSITION,
        NEW_ENTITY,
        DEAD
    };
};

/**
 * @brief An enum representing all the type an entity can take
 * 
 */
enum ENTITY_TYPE {
    PLAYER,
    WALL,
    ENEMY,
    BUTTON,
    TEXT,
    BULLET,
    UI,
    // GRAPHIC,
    // NETWORK
};

using byte = unsigned char;

template <class Serializable>
struct serializable_trait {
    static std::vector<byte> serialize(Serializable const &obj) {
        std::vector<byte> ret;

        ret.resize(sizeof(Serializable));
        std::memcpy(ret.data(), std::addressof(obj), sizeof(Serializable));
        return ret;
    }

    static Serializable unserialize(std::vector<byte> const &v) {
        Serializable s;

        std::memcpy(&s, v.data(), sizeof(Serializable));
        return s;
    }
};

struct serialize_header {
    template<class Seriazable>
    static std::vector<byte> serializeHeader(uint8_t id, Seriazable const &obj)
    {
        std::vector<byte> bytes;
        bytes.resize(sizeof(uint8_t));

        std::memcpy(bytes.data(), &id, sizeof(uint8_t));
        std::vector<byte> data = serializable_trait<Seriazable>::serialize(obj);
        bytes.insert(bytes.end(), data.begin(), data.end());
        return bytes;
    };

    static uint8_t getId(std::vector<byte> const &bytes)
    {
        uint8_t id;
        std::memcpy(&id, bytes.data(), sizeof(uint8_t));
        return id;
    };
};

#endif /* !SERIALIZATION_HPP_ */

