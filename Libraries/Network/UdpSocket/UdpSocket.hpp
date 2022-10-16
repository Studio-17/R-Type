/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** UdpSocket
*/

#ifndef UDPSOCKET_HPP_
#define UDPSOCKET_HPP_

#include <asio.hpp>

class UdpSocket {
    public:
        /**
         * @brief Construct a new Udp Socket object
         * 
         */
        UdpSocket() = default;

        /**
         * @brief Destroy the Udp Socket object
         * 
         */
        ~UdpSocket();

        /**
         * @brief Construct a new Udp Socket object
         * 
         * @param context 
         * @param port 
         */
        UdpSocket(asio::io_context &context, std::string port) : _context(context),
        _socket(context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)) {};

        /**
         * @brief A method to send a pack through udp
         * 
         */
        void send() {};

        /**
         * @brief A method to receive a packet through udp
         * 
         */
        void receive() {};

    protected:
    private:
        /**
         * @brief An asio;;io_context, it provides core I/O functionality.
         * 
         */
        asio::io_context &_context;

        /**
         * @brief The UDP socket type.
         * 
         */
        asio::ip::udp::socket _socket;

        /**
         * @brief The type of a UDP endpoint.
         * 
         */
        asio::ip::udp::endpoint _endpoint;
};


#endif /* !UDPSOCKET_HPP_ */
