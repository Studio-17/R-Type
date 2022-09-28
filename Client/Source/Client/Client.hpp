/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

    #include <boost/asio.hpp>

	#include "Communication.hpp"
    #include "Structure.hpp"

using boost::asio::ip::udp;

class Client
{
	public:
		Client(boost::asio::io_service &io_service, std::string const &host, std::string const &port);
		~Client();

		void send();
    	std::string receive();

	private:
		boost::asio::io_service& io_service_;

		std::shared_ptr<udp::socket> _socket;
		udp::endpoint _destination;

		Communication _communicationModule;
};

#endif /* !CLIENT_HPP_ */
