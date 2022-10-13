/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

	#include <asio/buffer.hpp>
    #include <asio/ip/udp.hpp>
    #include <asio/error_code.hpp>
    #include <asio/io_context.hpp>
    #include <asio/io_service.hpp>
    #include <asio/placeholders.hpp>

	#include "Network/Network.hpp"
	#include "UdpCommunication.hpp"
	#include "Registry.hpp"
    #include "GraphicalLib.hpp"
	#include "DrawSystem.hpp"
	#include "RectSystem.hpp"
	#include "ControlSystem.hpp"
	#include "NewEntitySystem.hpp"
	#include "PositionSystem.hpp"

class Client
{
	public:
		Client(std::string const &ip, std::string const &port, int hostPort);
		~Client();

		void setUpEcs();
		void setUpSystems();
		void setUpComponents();
		void machineRun();

	private:
		void handleReceive();
		void handleSendPacket();

		void sendNewDirection(std::vector<byte> &byte);

		void parsePacket(std::vector<byte> &bytes);
		asio::io_context _context;
		std::vector<byte> _bufferToGet;

        std::unique_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
		std::unique_ptr<UdpCommunication> _com;
        Registry _registry; ///< Registry that contains all the ECS
		bool _working;

		// Systems
		DrawSystem _drawSystem; ///< System that draws the entities
		RectSystem _rectSystem; ///< System that a part of a entity
		ControlSystem _controlSystem; ///< System that controls the entities
		NewEntitySystem _newEntitySystem; ///< System that creates new entities
		PositionSystem _positionSystem; ///< System that updates the position of the entities
};

#endif /* !CLIENT_HPP_ */
