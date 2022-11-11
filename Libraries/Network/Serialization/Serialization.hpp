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

/**
 * @brief Enum representing Type of request sent from Client to Network
 */
namespace NETWORK_CLIENT_TO_SERVER {
    enum PACKET_TYPE {
        SHOOT,
        DIRECTION,
        NEW_CONNECTION,
        DISCONNECTION,
        NEW_CLIENT,
        GET_LOBBYS,
        CREATE_LOBBY,
        START_GAME,
        JOIN_LOBBY
    };
};

/**
 * @brief Enum representing Type of request sent from Network to Client
 */
namespace NETWORK_SERVER_TO_CLIENT {
    enum PACKET_TYPE {
        POSITION,
        NEW_ENTITY,
        KILL_ENTITY,
        KILL_ENTITY_TYPE,
        NEW_CLIENT_RESPONSE,
        SEND_LOBBYS,
        NUMBER_PLAYERS_IN_LOBBY,
        UPDATE_ENTITY_HEALTH,
        UPDATE_ENTITY_SCORE,
        END_GAME
    };
};

/**
 * @brief An enum representing all the type an entity can take
 */
enum ENTITY_TYPE {
    WALL,
    PLAYER,
    GREENSPACESHIP,
    REDSPACESHIP,
    PURPLESPACESHIP,
    MARINESPACESHIP,
    ENEMY,
    BULLET,
    PARALLAX,
    BUTTON,
    TEXT,
    IMAGE,
    UI,
    NET,
    ENEMY2,
    INPUT_BOX
};

using byte = unsigned char; ///< Using to represent what type of data is contained

/**
 * @brief A templated class to serialize and unserialize a packet (as a std::vector of bytes)
 *
 * @tparam Serializable Type of Structure to handle
 */
template <class Serializable>
struct serializable_trait {
    /**
     * @brief A method to serialize an object (the object passed as template argument) into a vector of byte
     *
     * @param obj Object to serialize
     * @return std::vector<byte> Serialized object
     */
    static std::vector<byte> serialize(Serializable const &obj) {
        std::vector<byte> ret;

        ret.resize(sizeof(Serializable));
        std::memcpy(ret.data(), std::addressof(obj), sizeof(Serializable));
        return ret;
    }

    /**
     * @brief A method to unserialize a vector of byte into an object (passed as template argument)
     *
     * @param v Object to unserialize
     * @return Serializable Unserialized object
     */
    static Serializable unserialize(std::vector<byte> const &v) {
        Serializable s;

        std::memcpy(&s, v.data(), sizeof(Serializable));
        return s;
    }
};

/**
 * @brief Class to serialize and unserialize a packet (as a std::vector of bytes) with an id representing the type of data
 */
struct serialize_header {
    /**
     * @brief A method to serialize an object (the object passed as template argument) into a vector of byte with his type at front
     *
     * @tparam Seriazable Type of Structure to serialize
     * @param id Type of structure represented with an enum
     * @param obj Object to serialize
     * @return std::vector<byte> Serialized object
     */
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

    /**
     * @brief Get the Id object from the bytes
     *
     * @param bytes Unkwown type Serialized Object with an id representing his type at front
     * @return uint8_t Id representing the type of Object contained in bytes
     */
    static uint8_t getId(std::vector<byte> const &bytes)
    {
        uint8_t id;
        std::memcpy(&id, bytes.data(), sizeof(uint8_t));
        return id;
    };
};

#endif /* !SERIALIZATION_HPP_ */

