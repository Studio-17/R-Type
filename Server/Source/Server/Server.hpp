/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_
    
    #include <iostream>

    #include <asio/ip/udp.hpp>
    #include <asio/error_code.hpp>
    #include <asio/io_context.hpp>
    #include <asio/io_service.hpp>
    #include <asio/placeholders.hpp>

    #include "Structure.hpp"
    #include "Serialization.hpp"

class Server {
    public:
        Server(asio::io_service &service, short const port);
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
        void SendPackets(const std::error_code &e, std::size_t nbBytes);
        void CompleteExchnage(const std::error_code &e, std::size_t nbBytes);

        std::shared_ptr<asio::ip::upd::socket> _socket;
        asio::ip::udp::endpoint _destination;
        std::vector<byte> buffer_to_get;

};

#endif /* !SERVER_HPP_ */
