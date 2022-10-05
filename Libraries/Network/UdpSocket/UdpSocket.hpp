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
        UdpSocket() = default;
        ~UdpSocket();

        UdpSocket(asio::io_context &context, std::string port) : _context(context),
        _socket(context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)) {};

        void send() {};

        void receive() {};



    protected:
    private:
        asio::io_context &_context;
        asio::ip::udp::socket _socket;
        asio::ip::udp::endpoint _endpoint;
};


#endif /* !UDPSOCKET_HPP_ */
