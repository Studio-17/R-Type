/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_

    #include <iostream>
    #include <functional>

    #include <asio/ip/udp.hpp>
    #include <asio/error_code.hpp>
    #include <asio/io_context.hpp>
    #include <asio/io_service.hpp>
    #include <asio/placeholders.hpp>

    #include <asio.hpp>

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
        void ReceivePackets();
        void SendPackets(asio::error_code const &e, std::size_t nbBytes);
        void CompleteExchnage(asio::error_code const &e, std::size_t nbBytes);

        asio::io_context _context;

        std::shared_ptr<UdpCommunication> _com;
        std::vector<byte> buffer_to_get;

};

#endif /* !SERVER_HPP_ */
