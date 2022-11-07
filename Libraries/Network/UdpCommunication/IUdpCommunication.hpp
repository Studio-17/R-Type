/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** IUdpCommunication
*/

#ifndef IUDPCOMMUNICATION_HPP_
    #define IUDPCOMMUNICATION_HPP_

    #include <functional>
    #include <utility>

    #include <asio/ip/udp.hpp>
    #include <asio/error_code.hpp>
    #include <asio/io_context.hpp>

using byte = unsigned char; ///< Using to represent what type of data is contained

/**
 * @brief Interface representing UdpCommunication
 */
class IUdpCommunication {
    public:

        /**
         * @brief Destroy the IUdpCommunication object
         */
        virtual ~IUdpCommunication() = default;

        /**
         * @brief A method to send a message to the already known ip adress and port adress
         *
         * @param data The serialized message
         */
        virtual void send(std::vector<byte> const &data) = 0;

        /**
         * @brief A method to send a message to an ip adress and port adress
         *
         * @param data The serialized message
         * @param address The ip adress to send the message
         * @param port The port adress to send the message
         */
        virtual void send(std::vector<byte> const &data, asio::ip::address const &address, unsigned short const &port) = 0;

        /**
         * @brief A method to send a message to an already known ip adress and port adress in an async way
         *
         * @param data The serilized
         * @param callBack The function to call once the message is sent
         */
        virtual void async_send(std::vector<byte> const &data, std::function<void(std::error_code const &, std::size_t)> callBack) = 0;

        /**
         * @brief A method to send a message to a ip adress and port adress in an async way
         *
         * @param data The serialized message
         * @param callBack The function called once the message is sent
         * @param address The ip adress to send the message
         * @param port The port adress to send the message
         */
        virtual void async_send(std::vector<byte> const &data, std::function<void(std::error_code const &, std::size_t)> callBack, asio::ip::address const &address, unsigned short const &port) = 0;

        /**
         * @brief A method to receive a message
         *
         * @param data The buffer to fill when the message is received
         * @return std::pair<asio::ip::address, unsigned short> The ip adress and the port adress where the message came from
         */
        virtual std::pair<asio::ip::address, unsigned short> receive(std::vector<byte> &data) = 0;

        /**
         * @brief A method to receive a message in an async way
         *
         * @param data The buffer to fill when the message is received
         * @param callBack The function called once the message is received
         */
        virtual void async_receive(std::vector<byte> &data, std::function<void(std::error_code const &, std::size_t)> callBack) = 0;

        /**
         * @brief Get the Enpoint Info object
         *
         * @return std::pair<asio::ip::address, unsigned short> Pair with the ip address and the port of the endpoint
         */
        virtual std::pair<asio::ip::address, unsigned short> getEnpointInfo() const = 0;

        /**
         * @brief Set the Enpoint Info object
         *
         * @param endpointInfo Pair with the ip address and the port of the endpoint
         */
        virtual void setEnpointInfo(std::pair<asio::ip::address, unsigned short> const &endpointInfo) = 0;

        /**
         * @brief Set the Enpoint Info object
         *
         * @param address Ip address of the endpoint
         * @param port Port of the endpoint
         */
        virtual void setEnpointInfo(asio::ip::address const &address, unsigned short const &port) = 0;

    protected:
    private:
};

#endif /* !IUDPCOMMUNICATION_HPP_ */
