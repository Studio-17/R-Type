/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Packet
*/

#ifndef PACKET_HPP_
#define PACKET_HPP_

/**
 * @brief A class to handle packets that will be used to communicate through udp protocol
 * 
 */
class Packet {
    public:
        /**
         * @brief Construct a new Packet object
         * 
         */
        Packet();

        /**
         * @brief Destroy the Packet object
         * 
         */
        ~Packet();

        /**
         * @brief A method to pack a packet before sending it
         * 
         */
        void pack(void) {};

        /**
         * @brief A method to unpack a received packet
         * 
         */
        void unpack(void) {};

    protected:
    private:
};

#endif /* !PACKET_HPP_ */
