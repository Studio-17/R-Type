/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Communication
*/

#ifndef COMMUNICATION_HPP_
#define COMMUNICATION_HPP_

#include <boost/asio.hpp>
#include <iostream>

class Communication {
    public:
        Communication() {};
        ~Communication() {};

        template<typename Structure>
        void receive(boost::asio::ip::udp::socket socket, boost::asio::ip::udp::endpoint endpoint, void(handler)(const boost::system::error_code &e, std::size_t nbBytes)) {
            std::vector<char> buffer_to_get;
            Structure struct_to_get;
            buffer_to_get.reserve(sizeof(struct_to_get));

            socket.async_receive_from(boost::asio::buffer(buffer_to_get.data(), sizeof(struct_to_get)), endpoint, &handler);
            std::memcpy(reinterpret_cast<char *>(&struct_to_get), buffer_to_get.data(), sizeof(struct_to_get));
        };

        template<typename Structure>
        void send(boost::asio::ip::udp::socket socket, boost::asio::ip::udp::endpoint endpoint, Structure struct_to_send, void(handler)(const boost::system::error_code &e, std::size_t nbBytes)) {
            std::vector<char> buffer_to_send;

            buffer_to_send.reserve(sizeof(Structure));
            std::memcpy(buffer_to_send.data(), &struct_to_send, sizeof(Structure));
            socket.async_send_to(boost::asio::buffer(buffer_to_send.data(), sizeof(Structure)), endpoint, &handler);
        };

    protected:
    private:
};

#endif /* !COMMUNICATION_HPP_ */
