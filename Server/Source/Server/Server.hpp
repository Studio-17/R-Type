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
    #include <functional>

    #include <asio/ip/udp.hpp>
    #include <asio/error_code.hpp>
    #include <asio/io_context.hpp>
    #include <asio/io_service.hpp>
    #include <asio/placeholders.hpp>

    #include "Registry.hpp"
    #include "Component/CDamage.hpp"
    #include "Component/CDirection.hpp"
    #include "Component/CHealth.hpp"
    #include "Component/CHitBox.hpp"
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CPosition.hpp"
    // #include "Component/CVelocity.hpp"

    #include "System/MoveSystem/MoveSystem.hpp"

    #include "Serialization.hpp"
    #include "UdpCommunication.hpp"

    #include "Constant.hpp"


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

        void setUpEcs();
        void setUpComponents();

    protected:

    private:
        void ReceivePackets();
        void HandleReceive(asio::error_code const &e, std::size_t nbBytes);
        void HandleSendPacket();
        void CompleteExchange(asio::error_code const &e, std::size_t nbBytes);

        void threadLoop();

        asio::io_context _context;

        std::queue<std::function<void(void)>> _responseQueue;

        std::shared_ptr<UdpCommunication> _com;
        std::vector<byte> _buffer_to_get;

        std::unordered_map<asio::ip::address, std::unordered_map<unsigned short, bool>> _endpoints;

        Registry _registry;
        MoveSystem _moveSystem;

        bool _serverIsRunning = true;
};

#endif /* !SERVER_HPP_ */
