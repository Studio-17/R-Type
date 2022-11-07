/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_

    #include <iostream>
    #include <thread>
    #include <queue>
    #include <map>
    #include <unordered_map>
    #include <functional>

    #include <asio/ip/udp.hpp>
    #include <asio/error_code.hpp>
    #include <asio/io_context.hpp>
    #include <asio/io_service.hpp>
    #include <asio/placeholders.hpp>

    #include "Registry.hpp"

    /* System */
    #include "System/MoveSystem/MoveSystem.hpp"
    #include "System/ReceiveSystem/ReceiveSystem.hpp"
    #include "System/DirectionSystem/DirectionSystem.hpp"
    #include "ShootSystem.hpp"
    // #include "System/NewPlayerSystem/NewPlayerSystem.hpp"
    #include "System/SpawnEnemySystem/SpawnEnemySystem.hpp"
    #include "System/HitboxSystem/HitboxSystem.hpp"
    #include "System/DisconnectionSystem/DisconnectionSystem.hpp"
    #include "System/NewClientSystem/NewClientSystem.hpp"
    #include "System/JoinLobbySystem/JoinLobbySystem.hpp"
    #include "System/StartGameSystem/StartGameSystem.hpp"

    // #include "Serialization.hpp"
    #include "UdpCommunication.hpp"
    #include "IUdpCommunication.hpp"

/**
 * @brief Server class to handle Server
 */
class Server {
    public:
        /**
         * @brief Construct a new Server object
         *
         * @param port The port where init the server
         */
        Server(short const port);

        /**
         * @brief Destroy the Server object
         */
        ~Server();

        /**
         * @brief Set the Up Ecs object
         */
        void setUpEcs();

        /**
         * @brief Set the Up Components object
         */
        void setUpComponents();

    protected:
    private:
        /**
         * @brief A method to recivie a packet using the communication module
         */
        void ReceivePackets();

        /**
         * @brief A method to handle the reception of a packet and dispatch it to the appropriate system
         *
         * @param e In case of error, this is the error code
         * @param nbBytes Number of bytes transferred
         */
        void HandleReceive(asio::error_code const &e, std::size_t nbBytes);

        /**
         * @brief A method to send a packet using the communication module and systems
         */
        void HandleSendPacket();

        /**
         * @brief A method to configure and handle the threadloop
         */
        void threadLoop();

        asio::io_context _context; ///< An asio context object that handles basic I/O

        std::queue<std::function<void(void)>> _responseQueue; ///< A queue that manages the tasks to be done by the systems using the packets received

        std::shared_ptr<IUdpCommunication> _com; ///< A shared pointer to a module used for communicating through udp sockets

        std::vector<byte> _buffer_to_get; ///< A buffer as a vector of bytes to communicate packets

        std::thread _thread; ///< A thread object to concurently run the asio context and the systems

        bool _isRunning; ///< A boolean to handle the server's main loop

        std::unordered_map<asio::ip::address, std::unordered_map<unsigned short, int>> _endpoints; ///< A map containing all the clients addresses and ports
        int client_id = 0; ///< An index incremented to set the client id
        Registry _registry; ///< An object Registry for the server to interact with it

        System::MoveSystem _moveSystem; ///< An object MoveSystem to manage it in the server
        System::DirectionSystem _directionSystem; ///< An object DirectionSystem to manage it in the server
        System::ShootSystem _shootSystem; ///< An object ShootSystem to manage it in the server
        // System::NewPlayerSystem _newPlayerSystem; ///< An object NewPlayerSystem to manage it in the server
        System::SpawnEnemySystem _spawnEnemySystem; ///< An object SpawnEnemySystem to manage it in the server
        System::ReceiveSystem _receiveSystem; ///< An object ReceiveSystem to manage it in the server
        System::HitboxSystem _hitboxSystem; ///< An object HitboxSystem to manage it in the server
        System::DisconnectionSystem _disconnectionSystem; ///< An object DisconnectionSystem to manage it in the server
        System::NewClientSystem _newClientSystem; ///< An object NewClientSystem to manage it in the server
        System::JoinLobbySystem _joinLobbySystem; ///< An object JoinLobbySystem to manage it in the 
        System::StartGameSystem _startGameSystem; ///< An object StartGameSystem to manage it in the 

        bool _serverIsRunning = true; ///< A boolean to manage the server loop
};

#endif /* !SERVER_HPP_ */
