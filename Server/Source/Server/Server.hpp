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
    #include "Component/CDamage.hpp"
    #include "Component/CDirection.hpp"
    #include "Component/CHealth.hpp"
    #include "Component/CHitBox.hpp"
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CPosition.hpp"
    // #include "Component/CVelocity.hpp"

    #include "System/MoveSystem/MoveSystem.hpp"
    #include "System/ReceiveSystem/ReceiveSystem.hpp"
    #include "System/DirectionSystem/DirectionSystem.hpp"
    #include "ShootSystem.hpp"
    #include "System/NewPlayerSystem/NewPlayerSystem.hpp"
    #include "System/SpawnEnemySystem/SpawnEnemySystem.hpp"
    #include "System/HitboxSystem/HitboxSystem.hpp"

    #include "Serialization.hpp"
    #include "UdpCommunication.hpp"
    #include "IUdpCommunication.hpp"

    #include "Constant.hpp"

/**
 * @brief 
 * 
 */
class Server {
    public:
        /**
         * @brief Construct a new Server object
         * 
         * @param port 
         */
        Server(short const port);

        /**
         * @brief Destroy the Server object
         * 
         */
        ~Server();

        /**
         * @brief A method to handle the packets received if an error occurs
         * 
         * @param error 
         * @param bytes_transferred 
         */
        void CommunicationHandler(const std::error_code& error, std::size_t bytes_transferred) {
            if (error) {
                std::cerr << error.message() << std::endl;
            } else {
                std::cerr << "bytes transferred: " << bytes_transferred << std::endl;
            }
        };

        /**
         * @brief Set the Up Ecs object
         * 
         */
        void setUpEcs();

        /**
         * @brief Set the Up Components object
         * 
         */
        void setUpComponents();

    protected:

    private:
        /**
         * @brief A method to recivie a packet using the communication module
         * 
         */
        void ReceivePackets();

        /**
         * @brief A method to handle the reception of a packet and dispatch it to the appropriate system
         * 
         * @param e 
         * @param nbBytes 
         */
        void HandleReceive(asio::error_code const &e, std::size_t nbBytes);

        /**
         * @brief A method to send a packet using the communication module and systems
         * 
         */
        void HandleSendPacket();

        /**
         * @brief A method to configure and handle the threadloop
         * 
         */
        void threadLoop();

        /**
         * @brief An asio context object that handles basic I/O
         * 
         */
        asio::io_context _context;

        /**
         * @brief A queue that manages the tasks to be done by the systems using the packets received
         * 
         */
        std::queue<std::function<void(void)>> _responseQueue;

        /**
         * @brief A shared pointer to a module used for communicating through udp sockets
         * 
         */
        std::shared_ptr<IUdpCommunication> _com;

        /**
         * @brief A buffer as a vector of bytes to communicate packets
         * 
         */
        std::vector<byte> _buffer_to_get;

        /**
         * @brief A thread object to concurently run the asio context and the systems
         * 
         */
        std::thread _thread;

        /**
         * @brief A boolean to handle the server's main loop
         * 
         */
        bool _isRunning;

        /**
         * @brief A map containing all the clients addresses and ports
         * 
         */
        std::unordered_map<asio::ip::address, std::unordered_map<unsigned short, bool>> _endpoints;

        /**
         * @brief An object Registry for the server to interact with it
         * 
         */
        Registry _registry;

        /**
         * @brief An object MoveSystem to manage it in the server
         * 
         */
        MoveSystem _moveSystem;

        /**
         * @brief An object DirectionSystem to manage it in the server
         * 
         */
        DirectionSystem _directionSystem;

        /**
         * @brief An object ShootSystem to manage it in the server
         * 
         */
        ShootSystem _shootSystem;
        /**
         * @brief An object NewPlayerSystem to manage it in the server
         *
         */
        NewPlayerSystem _newPlayerSystem;

        /**
         * @brief An object SpawnEnemySystem to manage it in the server
         * 
         */
        SpawnEnemySystem _spawnEnemySystem;

        /**
         * @brief An object ReceiveSystem to manage it in the server
         * 
         */
        System::ReceiveSystem _receiveSystem;

        /**
         * @brief An object HitboxSystem to manage it in the server
         * 
         */
        System::HitboxSystem _hitboxSystem;
        /**
         * @brief A boolean to manage the server loop
         * 
         */
        bool _serverIsRunning = true;
};

#endif /* !SERVER_HPP_ */
