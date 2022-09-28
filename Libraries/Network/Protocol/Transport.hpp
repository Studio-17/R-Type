/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Transport
*/

#ifndef TRANSPORT_HPP_
#define TRANSPORT_HPP_

#include <functional>

#include <boost/asio.hpp>

using boost::asio::ip::udp;

class Transport {
    public:
        Transport() {};
        ~Transport() {};

        bool setTransport() {};

    protected:
    private:
        // udp::socket _socket;
        // udp::endpoint _endpoint;
};

#endif /* !TRANSPORT_HPP_ */
