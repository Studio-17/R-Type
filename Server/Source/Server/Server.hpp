/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_

    #include <boost/asio.hpp>

    #include "Structure.hpp"
    #include "Serialization.hpp"


using boost::asio::ip::udp;

class Server {
    public:
        Server(boost::asio::io_service &service, short const port);
        ~Server();

        void CommunicationHandler(const boost::system::error_code& error, std::size_t bytes_transferred) {
            if (error) {
                std::cerr << error.message() << std::endl;
            } else {
                std::cerr << "bytes transferred: " << bytes_transferred << std::endl;
            }
        };

    protected:

    private:
        void ReceivePackets();
        void SendPackets(const boost::system::error_code &e, std::size_t nbBytes);
        void CompleteExchnage(const boost::system::error_code &e, std::size_t nbBytes);

        std::shared_ptr<udp::socket> _socket;
        udp::endpoint _destination;
        std::vector<byte> buffer_to_get;

};

#endif /* !SERVER_HPP_ */
