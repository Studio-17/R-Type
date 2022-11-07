/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** UdpCommunication
*/

#ifndef UDPCOMMUNICATION_HPP_
    #define UDPCOMMUNICATION_HPP_

    #include "IUdpCommunication.hpp"

/**
 * @brief Class that handle Udp Communication
 */
class UdpCommunication : public IUdpCommunication {
    public:
        /**
         * @brief Construct a new Udp Communication object
         */
        UdpCommunication() = default;
        /**
         * @brief Destroy the Udp Communication object
         */
        ~UdpCommunication() {
            _socket.close();
        };

        /**
         * @brief Construct a new Udp Communication object
         *
         * @param context IO Context of the communication
         * @param port Port where start the communication
         */
        UdpCommunication(asio::io_context &context, asio::ip::port_type const &port) : _context(context),
        _socket(_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)) {};

        /**
         * @brief Construct a new Udp Communication object
         *
         * @param context IO Context of the communication
         * @param port Port where start the communication
         * @param connectionPort Port where connect the communication
         * @param ip Ip address where connect the communication
         */
        UdpCommunication(asio::io_context &context, asio::ip::port_type const &port, std::string const &connectionPort, std::string const &ip) : _context(context),
        _socket(_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)) {
            asio::ip::udp::resolver resolver(context);
	        asio::ip::udp::resolver::query query(asio::ip::udp::v4(), ip, connectionPort);
	        asio::ip::udp::resolver::iterator iter = resolver.resolve(query);
	        _endpoint = *iter;
        };

        /**
         * @brief A method to send a message to the already known ip adress and port adress
         *
         * @param data The serialized message
         */
        void send(std::vector<byte> const &data) override {
            _socket.send_to(asio::buffer(data.data(), data.size()), _endpoint);
        };

        /**
         * @brief A method to send a message to an ip adress and port adress
         *
         * @param data The serialized message
         * @param address The ip adress to send the message
         * @param port The port adress to send the message
         */
        void send(std::vector<byte> const &data, asio::ip::address const &address, unsigned short const &port) override {
            setEnpointInfo(address, port);
            _socket.send_to(asio::buffer(data.data(), data.size()), _endpoint);
        };

        /**
         * @brief A method to send a message to an already known ip adress and port adress in an async way
         *
         * @param data The serilized
         * @param callBack The function to call once the message is sent
         */
        void async_send(std::vector<byte> const &data, std::function<void(std::error_code const &, std::size_t)> callBack) override {
            _socket.async_send_to(asio::buffer(data.data(), data.size()), _endpoint, callBack);
        };

        /**
         * @brief A method to send a message to a ip adress and port adress in an async way
         *
         * @param data The serialized message
         * @param callBack The function called once the message is sent
         * @param address The ip adress to send the message
         * @param port The port adress to send the message
         */
        void async_send(std::vector<byte> const &data, std::function<void(std::error_code const &, std::size_t)> callBack, asio::ip::address const &address, unsigned short const &port) override {
            setEnpointInfo(address, port);
            _socket.async_send_to(asio::buffer(data.data(), data.size()), _endpoint, callBack);
        };

        /**
         * @brief A method to receive a message
         *
         * @param data The buffer to fill when the message is received
         * @return std::pair<asio::ip::address, unsigned short> The ip adress and the port adress where the message came from
         */
        std::pair<asio::ip::address, unsigned short> receive(std::vector<byte> &data) override {
            data.clear();
            data.resize(1500);
            _socket.receive_from(asio::buffer(data.data(), 1500), _endpoint);
            return getEnpointInfo();
        };

        /**
         * @brief A method to receive a message in an async way
         *
         * @param data The buffer to fill when the message is received
         * @param callBack The function called once the message is received
         */
        void async_receive(std::vector<byte> &data, std::function<void(std::error_code const &, std::size_t)> callBack) override {
            data.clear();
            data.resize(1500);
            _socket.async_receive_from(asio::buffer(data.data(), 1500), _endpoint, callBack);
        };

        /**
         * @brief Get the Enpoint Info object
         *
         * @return std::pair<asio::ip::address, unsigned short> Pair with the ip address and the port of the endpoint
         */
        std::pair<asio::ip::address, unsigned short> getEnpointInfo() const override {
            return std::make_pair<asio::ip::address, unsigned short>(_endpoint.address(), _endpoint.port());
        }

        /**
         * @brief Set the Enpoint Info object
         *
         * @param endpointInfo Pair with the ip address and the port of the endpoint
         */
        void setEnpointInfo(std::pair<asio::ip::address, unsigned short> const &endpointInfo) override {
            _endpoint.address(endpointInfo.first);
            _endpoint.port(endpointInfo.second);
        }

        /**
         * @brief Set the Enpoint Info object
         *
         * @param address Ip address of the endpoint
         * @param port Port of the endpoint
         */
        void setEnpointInfo(asio::ip::address const &address, unsigned short const &port) override {
            _endpoint.address(address);
            _endpoint.port(port);
        }

    protected:
    private:
        asio::io_context &_context; ///< IO context of the communication
        asio::ip::udp::socket _socket; ///< Socket that handle communication
        asio::ip::udp::endpoint _endpoint; ///< Endpoint from where the message will be received / sent
};


#endif /* !UDPCOMMUNICATION_HPP_ */
