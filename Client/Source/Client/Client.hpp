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

class Client
{
	public:
		Client(std::string const &ip, std::string const &port);
		~Client();

		void setUpEcs(void);
		void machineRun(void);

	private:
		std::unique_ptr<Network> _network;
		std::unique_ptr<Registry> _registry;
		bool _working;
};

#endif /* !CLIENT_HPP_ */
