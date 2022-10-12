/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_

    #include <iostream>
    #include <thread>
    #include <queue>
    #include <map>
    #include <unordered_map>

    #include <asio/ip/udp.hpp>
    #include <asio/error_code.hpp>
    #include <asio/io_context.hpp>
    #include <asio/io_service.hpp>
    #include <asio/placeholders.hpp>

    // #include <asio.hpp>

    #include "Structure.hpp"
    #include "Serialization.hpp"
    #include "UdpCommunication.hpp"


class Server {
    public:
        Server(short const port);
        ~Server();

        void CommunicationHandler(const std::error_code& error, std::size_t bytes_transferred) {
            if (error) {
                std::cerr << error.message() << std::endl;
            } else {
                std::cerr << "bytes transferred: " << bytes_transferred << std::endl;
            }
        };

    protected:

    private:
        void HandleReceive(asio::error_code const &e, std::size_t nbBytes);
        void ReceivePackets();
        void SendPackets(asio::error_code const &e, std::size_t nbBytes);
        void CompleteExchange(asio::error_code const &e, std::size_t nbBytes);

        void threadLoop();

        asio::io_context _context;

        std::queue<std::function<void(void)>> _responseQueue;

        std::shared_ptr<UdpCommunication> _com;
        std::vector<byte> buffer_to_get;

        std::unordered_map<asio::ip::address, std::unordered_map<unsigned short, bool>> _endpoints;

        void callback_packet1() { std::cout << "callback1" << std::endl; std::bind(&Server::CompleteExchange, this, std::placeholders::_1, std::placeholders::_2); };
        void callback_packet2() { std::cout << "callback2" << std::endl; std::bind(&Server::CompleteExchange, this, std::placeholders::_1, std::placeholders::_2); };
        void callback_packet3() { std::cout << "callback3" << std::endl; std::bind(&Server::CompleteExchange, this, std::placeholders::_1, std::placeholders::_2); };
        void callback_packet4() { std::cout << "callback4" << std::endl; std::bind(&Server::CompleteExchange, this, std::placeholders::_1, std::placeholders::_2); };
        void callback_packet5() { std::cout << "callback5" << std::endl; std::bind(&Server::CompleteExchange, this, std::placeholders::_1, std::placeholders::_2); };
        void callback_packet6() { std::cout << "callback6" << std::endl; std::bind(&Server::CompleteExchange, this, std::placeholders::_1, std::placeholders::_2); };
        void callback_packet7() { std::cout << "callback7" << std::endl; std::bind(&Server::CompleteExchange, this, std::placeholders::_1, std::placeholders::_2); };
        void callback_packet8() { std::cout << "callback8" << std::endl; std::bind(&Server::CompleteExchange, this, std::placeholders::_1, std::placeholders::_2); };
        void callback_packet9() { std::cout << "callback9" << std::endl; std::bind(&Server::CompleteExchange, this, std::placeholders::_1, std::placeholders::_2); };

    typedef std::function<void()> callback_function;
        std::map<int, callback_function> _callbacks;
};

#endif /* !SERVER_HPP_ */
