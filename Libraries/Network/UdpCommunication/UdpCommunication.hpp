/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** UdpCommunication
*/

#ifndef UDPCOMMUNICATION_HPP_
    #define UDPCOMMUNICATION_HPP_

    #include <functional>

    #include <asio/ip/udp.hpp>
    #include <asio/error_code.hpp>
    #include <asio/io_context.hpp>

using byte = unsigned char;
class UdpCommunication {
    public:
        UdpCommunication() = default;
        ~UdpCommunication() {
            _socket.close();
        };

        UdpCommunication(asio::io_context &context, asio::ip::port_type const &port) : _context(context),
        _socket(_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)) {};

        UdpCommunication(asio::io_context &context, asio::ip::port_type const &port, std::string const &connexionPort, std::string const &ip) : _context(context),
        _socket(_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)) {
            asio::ip::udp::resolver resolver(context);
	        asio::ip::udp::resolver::query query(asio::ip::udp::v4(), ip, connexionPort);
	        asio::ip::udp::resolver::iterator iter = resolver.resolve(query);
	        _endpoint = *iter;
        };
        void send(std::vector<byte> const &data) {
            _socket.send_to(asio::buffer(data.data(), data.size()), _endpoint);
        };

        void async_send(std::vector<byte> const &data, std::function<void(std::error_code const &, std::size_t)> callBack) {
            _socket.async_send_to(asio::buffer(data.data(), data.size()), _endpoint, callBack);
        };

        void receive(std::vector<byte> &data) {
            data.clear();
            data.resize(1500);
            _socket.receive_from(asio::buffer(data.data(), 1500), _endpoint);
        };

        void async_receive(std::vector<byte> &data, std::function<void(std::error_code const &, std::size_t)> callBack) {
            data.clear();
            data.resize(1500);
            _socket.async_receive_from(asio::buffer(data.data(), 1500), _endpoint, callBack);
        };

    protected:
    private:
        asio::io_context &_context;
        asio::ip::udp::socket _socket;
        asio::ip::udp::endpoint _endpoint;
};


#endif /* !UDPCOMMUNICATION_HPP_ */
