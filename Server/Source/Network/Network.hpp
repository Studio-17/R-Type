/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NetworkManager
*/

#ifndef NETWORKMANAGER_HPP_
#define NETWORKMANAGER_HPP_

#include "INetwork.hpp"

class NetworkManager : public INetwork {
    public:
        NetworkManager();
        ~NetworkManager();

        template<typename Structure>
        void Send(std::shared_ptr<boost::asio::ip::udp::socket> socket, boost::asio::ip::udp::endpoint endpoint, Structure struct_to_send) override {
            std::vector<char> buffer_to_send;

            buffer_to_send.reserve(sizeof(Structure));

            std::memcpy(buffer_to_send.data(), &struct_to_send, sizeof(Structure));

            socket->send_to(boost::asio::buffer(buffer_to_send.data(), sizeof(Structure)), endpoint);
        
        };
        template<typename Structure>
        void AsynchronousSend(std::shared_ptr<boost::asio::ip::udp::socket> socket, boost::asio::ip::udp::endpoint endpoint, Structure struct_to_send) override {

            std::vector<char> buffer_to_send;

            buffer_to_send.reserve(sizeof(Structure));

            std::memcpy(buffer_to_send.data(), &struct_to_send, sizeof(Structure));

            socket->async_send_to(boost::asio::buffer(buffer_to_send.data(), sizeof(Structure)), endpoint, boost::bind(&Communication::CommunicationHandler, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
        };

        template<typename Structure>
        void Receive(std::shared_ptr<boost::asio::ip::udp::socket> socket, boost::asio::ip::udp::endpoint endpoint, Structure struct_to_get) override {
            std::vector<char> buffer_to_get;

            buffer_to_get.reserve(sizeof(struct_to_get));

            socket->receive_from(boost::asio::buffer(buffer_to_get.data(), sizeof(struct_to_get)), endpoint);

            std::memcpy(reinterpret_cast<char *>(&struct_to_get), buffer_to_get.data(), sizeof(struct_to_get));

            return (struct_to_get);
        }; 
        template<typename Structure>
        Structure AsynchronousReceive(std::shared_ptr<boost::asio::ip::udp::socket> socket, boost::asio::ip::udp::endpoint endpoint, Structure struct_to_get) override {

            std::vector<char> buffer_to_get;

            buffer_to_get.reserve(sizeof(struct_to_get));

            socket->async_receive_from(boost::asio::buffer(buffer_to_get.data(), sizeof(struct_to_get)), endpoint, boost::bind(&Communication::CommunicationHandler, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

            std::memcpy(reinterpret_cast<char *>(&struct_to_get), buffer_to_get.data(), sizeof(struct_to_get));

            return (struct_to_get);
        };

    protected:

    private:
        void CommunicationHandler(const boost::system::error_code& error, std::size_t bytes_transferred) {
            if (error) {
                std::cerr << error.message() << std::endl;
            } else {
                std::cerr << "bytes transferred: " << bytes_transferred << std::endl;
            }
        };
};

#endif /* !NETWORKMANAGER_HPP_ */
