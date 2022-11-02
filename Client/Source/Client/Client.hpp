/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

	#include <thread>

	#include <asio/buffer.hpp>
    #include <asio/ip/udp.hpp>
    #include <asio/error_code.hpp>
    #include <asio/io_context.hpp>
    #include <asio/io_service.hpp>
    #include <asio/placeholders.hpp>

	#include "UdpCommunication.hpp"
	#include "Registry.hpp"
    #include "GraphicalLib.hpp"
	#include "DrawSystem.hpp"
	#include "RectSystem.hpp"
	#include "ControlSystem.hpp"
	#include "NewEntitySystem.hpp"
	#include "PositionSystem.hpp"
	#include "MoveSystem.hpp"
	#include "NetworkSystem.hpp"
	#include "KillSystem.hpp"
	#include "MouseSystem.hpp"
	#include "ButtonSystem.hpp"

	#include "AssetManager.hpp"

/**
 * @brief The Client class, it defines a client and its interactions with the server
 * 
 */
class Client
{
	public:
		/**
		 * @brief Construct a new Client object
		 * 
		 * @param ip ip of the client
		 * @param port port of the client
		 * @param hostPort port of the host
		 */
		Client(std::string const &ip, std::string const &port, int hostPort);

		/**
		 * @brief Destroy the Client object
		 * 
		 */
		~Client();

		/**
		 * @brief Set the Up Ecs object
		 * 
		 */
		void setUpEcs();

		/**
		 * @brief Set the Up Systems object
		 * 
		 */
		void setUpSystems();

		/**
		 * @brief Set the Up Components object
		 * 
		 */
		void setUpComponents();

		/**
		 * @brief A method to launch the core features of a client
		 * 
		 */
		void machineRun();

		/**
		 * @brief A method to try to connect to a target server 
		 * 
		 */
		void tryToConnect();

	private:
		/**
		 * @brief A method to recieve a packet through udp protocol
		 * 
		 */
		void handleReceive();

		/**
		 * @brief A method to send a packet through udp protocol
		 * 
		 */
		void SendPacket();

		/**
		 * @brief A method to push all the packets to the main queue
		 * 
		 * @param e error code of asio
		 * @param nbBytes nb of bytes to read
		 */
		void pushNewPacketsToQueue(asio::error_code const &e, std::size_t nbBytes);

		/**
		 * @brief A method to send a changement of direction
		 * 
		 * @param byte bytes to read
		 */
		void sendNewDirection(std::vector<byte> &byte);

		/**
		 * @brief A method to send a new shot has been fired by the client
		 * 
		 * @param byte bytes to read
		 */
		void sendNewShoot(std::vector<byte> &byte);

		/**
		 * @brief A method to configure and load the threadloop
		 * 
		 */
		void threadLoop();

		asio::io_context _context; ///< An asio context object to handle basic I/O

		std::vector<byte> _bufferToGet; ///< A buffer to receive as a vector of bytes

        std::unique_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
		std::unique_ptr<UdpCommunication> _com; ///< A shared pointer to a module used for communicating through udp sockets
        Registry _registry; ///< Registry that contains all the ECS
		std::thread _thread; ///< thread to handle ECS
		bool _connected; ///< A boolean to check if the clientis conncted to the server
		AssetManager _assetManager;

		// Systems
		NetworkSystem _networkSystem; ///< System that handle receive packet and dispatch them into specific queues
		DrawSystem _drawSystem; ///< System that draws the entities
		RectSystem _rectSystem; ///< System that a part of a entity
		ControlSystem _controlSystem; ///< System that controls the entities
		NewEntitySystem _newEntitySystem; ///< System that creates new entities
		PositionSystem _positionSystem; ///< System that updates the position of the entities
		MoveSystem _moveSystem; ///< System that updates the position of the entities using direction and velocity
		KillSystem _killSystem; ///< System that kill entity
		MouseSystem _mouseSystem; ///< System that handle mouse events
		ButtonSystem _buttonSystem; ///< System that handle button events
};

#endif /* !CLIENT_HPP_ */
