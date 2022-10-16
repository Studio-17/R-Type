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

/**
 * @brief A templated class to serialize and unserialize a packet (as a std::vector of bytes)
 * 
 * @tparam Serializable 
 */
template <class Serializable>
struct serializable_trait {
    /**
     * @brief A method to serialize an object (the object passed as template argument) into a vector of byte
     * 
     * @param obj 
     * @return std::vector<byte> 
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
     * @param v 
     * @return Serializable 
     */
    static Serializable unserialize(std::vector<byte> &v) {
        Serializable s;

        std::memcpy(&s, v.data(), sizeof(Serializable));
        // CALL_HANDLER<Serializable>(s);
        return s;
    }
};

#endif /* !SERIALIZATION_HPP_ */

