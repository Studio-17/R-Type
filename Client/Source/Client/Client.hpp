/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

	#include "Network/Network.hpp"
	#include "Registry.hpp"

	#include <asio/buffer.hpp>
    #include <asio/ip/udp.hpp>
    #include <asio/error_code.hpp>
    #include <asio/io_context.hpp>
    #include <asio/io_service.hpp>
    #include <asio/placeholders.hpp>

class Client
{
	public:
		Client(std::string const &ip, std::string const &port);
		~Client();

		void setUpEcs(void);
		void machineRun(void);

	private:
		/// A enlever plus tard dans Network
		asio::io_service io_service_;

		std::shared_ptr<asio::ip::udp::socket> _socket;
		asio::ip::udp::endpoint _destination;
		///

		std::unique_ptr<Network> _network;
		std::unique_ptr<Registry> _registry;
		bool _working;
};

#endif /* !CLIENT_HPP_ */
