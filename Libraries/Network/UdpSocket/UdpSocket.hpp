/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** UdpSocket
*/

#ifndef UDPSOCKET_HPP_
#define UDPSOCKET_HPP_

#include <boost/asio.hpp>

class UdpSocket {
    public:
        UdpSocket() = default;
        ~UdpSocket();

        UdpSocket(boost::asio::io_context &context, std::string port) : _context(context),
        _socket(context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)) {};

        void send() {};

        void receive() {};



    protected:
    private:
        boost::asio::io_context &_context;
        boost::asio::ip::udp::socket _socket;
        boost::asio::ip::udp::endpoint _endpoint;
};

#endif /* !UDPSOCKET_HPP_ */
