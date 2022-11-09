/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

    #if defined(_WIN32)
    #define NOGDI // All GDI defines and routines
    #define NOUSER// All USER defines and routines
    #endif
    #define CLIENT_HPP_

    #include <thread>

    #include "UdpCommunication.hpp"

    /* System */
    #include "System/NetworkSystem/NetworkSystem.hpp"
    #include "System/DrawTextSystem/DrawTextSystem.hpp"
    #include "System/DrawSpriteSystem/DrawSpriteSystem.hpp"
    #include "System/EndGameSystem/EndGameSystem.hpp"
    #include "System/RectSystem/RectSystem.hpp"
    #include "System/ControlSystem/ControlSystem.hpp"
    #include "System/NewEntitySystem/NewEntitySystem.hpp"
    #include "System/PositionSystem/PositionSystem.hpp"
    #include "System/MoveSystem/MoveSystem.hpp"
    #include "System/KillSystem/KillSystem.hpp"
    #include "System/KillEntityTypeSystem/KillEntityTypeSystem.hpp"
    #include "System/GetLobbiesSystem/GetLobbiesSystem.hpp"
    #include "System/SetNbPlayerInLobbySystem/SetNbPlayerInLobbySystem.hpp"
    #include "System/NewClientResponseSystem/NewClientResponseSystem.hpp"
    #include "System/MouseSystem/MouseSystem.hpp"

/**
 * @brief The Client class, it defines a client and its interactions with the server
 */
class Client {
    public:
        /**
		 * @brief Construct a new Client object
		 *
		 * @param ip Ip of the client
		 * @param port Port of the client
		 * @param hostPort Port of the host
		 * @param configurationFiles All configuration files
		 */
        Client(std::string const &ip, std::string const &port, int hostPort, std::map<std::string, std::string> &configurationFiles);

        /**
         * @brief Destroy the Client object
         */
        ~Client();

        /**
         * @brief Set the Up Ecs object
         */
        void setUpEcs();

        /**
         * @brief Set the Up Systems object
         */
        void setUpSystems();

        /**
         * @brief Set the Up Components object
         */
        void setUpComponents();

        /**
         * @brief A method to launch the core features of a client
         */
        void machineRun();

        /**
         * @brief A method to try to connect to a target server
         */
        void tryToConnect();

        /**
         * @brief A method to call juste before a client is deconected
         */
        void disconnect();

        /**
         * @brief A method to load the assets of the buttons
         *
         * @param filepath Path of the file containing all buttons
         * @param assets The sparse array of assets
         */
        void loadButtons(std::string const &filepath, Sparse_array<component::casset_t> &assets);

        /**
         * @brief A method to load the assets of the images
         *
         * @param filepath Path of the file containing all images
         * @param assets The sparse array of assets
         */
        void loadImages(std::string const &filepath, Sparse_array<component::casset_t> &assets);

        /**
         * @brief A method to load the assets of the text
         *
         * @param filepath Path of the file containing all texts
         */
        void loadTexts(std::string const &filepath);

        /**
         * @brief Create a Text object
         *
         * @param oneData Json Data where is stored the data
         * @param pos Position of the text
         * @param scene Scene id where add the text
         */
        void createText(nlohmann::json const &oneData, std::array<float, 2> pos, int scene, std::string const &ref);

    private:
        /**
         * @brief A method to recieve a packet through udp protocol
         */
        void handleReceive();

        /**
         * @brief A method to send a packet through udp protocol
         */
        void SendPacket();

        /**
         * @brief A method to push all the packets to the main queue
         *
         * @param e Error code of asio
         * @param nbBytes Number of bytes to read
         */
        void pushNewPacketsToQueue(asio::error_code const &e, std::size_t nbBytes);

        /**
         * @brief A method to send a changement of direction
         *
         * @param byte Bytes to read
         */
        void sendNewDirection(std::vector<byte> &byte);

        /**
         * @brief A method to send a new shot has been fired by the client
         *
         * @param byte Bytes to read
         */
        void sendNewShoot(std::vector<byte> &byte);

        /**
         * @brief Call back function executed when connect button is pressed to connect client to a server
         *
         */
        void connectToServer();

        void nameInput();
        void ipInput();
        void portInput();

        /**
         * @brief Call back function executed when rooms button is pressed to see all the rooms
         *
         */

        void seeRooms();
        /**
         * @brief Call back function executed when exit button is pressed to exit client on a server
         *
         */
        void backToConnection();

        /**
         * @brief Call back function executed when start button is pressed to start the game
         *
         */
        void startGame();

        /**
         * @brief Call back function executed when back button is pressed to go back to the main menu
         *
         */
        void backToMainMenu();

        /**
         * @brief Call back function executed when join room one button is pressed to join the room one
         *
         */
        void joinRoomOne();

        /**
         * @brief Call back function executed when join room two button is pressed to join the room two
         *
         */
        void joinRoomtwo();

        /**
         * @brief Call back function executed when join room three button is pressed to join the room three
         *
         */
        void joinRoomThree();

        /**
         * @brief Call back function executed when join lobby button is pressed to join the selected lobby
         *
         */
        void joinLobby();

        /**
         * @brief A method to configure and load the threadloop
         */
        void threadLoop();


        asio::io_context _context; ///< An asio context object to handle basic I/O

        std::unique_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
        std::unique_ptr<UdpCommunication> _com; ///< A shared pointer to a module used for communicating through udp sockets
        Registry _registry; ///< Registry that contains all the ECS
        std::thread _thread; ///< thread to handle ECS
        bool _connected; ///< A boolean to check if the clientis conncted to the server
        AssetManager _assetManager; ///< Asset manager to load all the assets

        std::vector<byte> _bufferToGet; ///< A buffer to receive as a vector of bytes

        std::map<std::string, std::function<void(void)>> _callbackMap; ///< A map of callbacks
        std::map<std::string, std::string> _configurationFiles;

        // Systems
        System::NetworkSystem _networkSystem; ///< System that handle receive packet and dispatch them into specific queues
        System::DrawSpriteSystem _drawSpriteSystem; ///< System that draws the entities
        System::DrawTextSystem _drawTextSystem; ///< System that draws the entities
        System::RectSystem _rectSystem; ///< System that a part of a entity
        System::ControlSystem _controlSystem; ///< System that controls the entities
        System::NewEntitySystem _newEntitySystem; ///< System that creates new entities
        System::PositionSystem _positionSystem; ///< System that updates the position of the entities
        System::MoveSystem _moveSystem; ///< System that updates the position of the entities using direction and velocity
        System::KillEntityTypeSystem _killEntityTypeSystem; ///< System that kill entity type
        System::KillSystem _killSystem; ///< System that kill entity
        System::GetLobbiesSystem _getLobbiesSystem;
        System::SetNbPlayerInLobbySystem _setNbPlayerInLobbySystem;
        System::NewClientResponseSystem _newClientResponseSystem;
        System::MouseSystem _mouseSystem; ///< System that handle mouse events
        System::EndGameSystem _endGameSystem; ///< System that end Game
};

#endif /* !CLIENT_HPP_ */
