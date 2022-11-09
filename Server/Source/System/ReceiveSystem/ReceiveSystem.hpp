/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** ReceiveSytem
*/

#ifndef RECEIVESYSTEM_HPP_
    #define RECEIVESYSTEM_HPP_

    #include <functional>
    #include <unordered_map>

    /* Ecs */
    #include "Registry.hpp"

    /* Serialization */
    #include "Serialization.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief System in charge of dispatch in specific queues sended request from queue
     */
    class ReceiveSystem {
        public:
            /**
             * @brief Construct a new Event System object
             */
            ReceiveSystem();
            ~ReceiveSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry The registry that contains all the ECS
             * @param queues The sparse array of network queue entities
             */
            void operator()(
                Registry &registry,
                Sparse_array<component::cnetwork_queue_t> &queues
            );

        protected:
        private:
            /**
             * @brief Adds a packet to the queue of movement handling
             *
             * @param data Vector of byte containing data to unserialize
             * @param clientId Id of the client who sent the packet
             * @param queues The sparse array of network queue entities
             */
            void addMoveOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues);

            /**
             * @brief Adds a packet to the queue of shoot handling
             *
             * @param data Vector of byte containing data to unserialize
             * @param clientId Id of the client who sent the packet
             * @param queues The sparse array of network queue entities
             */
            void addShootOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues);

            /**
             * @brief Adds a packet to the queue of new player handling
             *
             * @param data Vector of byte containing data to unserialize
             * @param clientId Id of the client who sent the packet
             * @param queues The sparse array of network queue entities
             */
            void addNewPLayerOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues);

            /**
             * @brief Adds a packet to the queue of new player handling
             *
             * @param data Vector of byte containing data to unserialize
             * @param clientId Id of the client who sent the packet
             * @param queues The sparse array of network queue entities
             */
            void addDisconnectionOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues);

            /**
             * @brief Add a packet to the queue of join lobby handling
             *
             * @param data Vector of byte containing data to unserialize
             * @param clientId Id of the client who sent the packet
             * @param queues The sparse array of network queue entities
             */
            void addJoinLobbyOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues);

            /**
             * @brief Add a packet to the queue of start game handling
             *
             * @param data Vector of byte containing data to unserialize
             * @param clientId Id of the client who sent the packet
             * @param queues The sparse array of network queue entities
             */
            void addStartGameOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues);

            std::unordered_map<uint8_t, std::function<void(std::vector<byte> const &, int, Sparse_array<component::cnetwork_queue_t> &)>> callBacks {
                {NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::NEW_CLIENT, std::bind(&ReceiveSystem::addNewPLayerOnQueue, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)},
                {NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::DIRECTION, std::bind(&ReceiveSystem::addMoveOnQueue, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)},
                {NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::SHOOT, std::bind(&ReceiveSystem::addShootOnQueue, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)},
                {NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::DISCONNECTION, std::bind(&ReceiveSystem::addDisconnectionOnQueue, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)},
                {NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::JOIN_LOBBY, std::bind(&ReceiveSystem::addJoinLobbyOnQueue, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)},
                {NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::START_GAME, std::bind(&ReceiveSystem::addStartGameOnQueue, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)}
            }; ///< A map that links every OnQueue method to a type of packet
    };
};

#endif /* !RECEIVESYSTEM_HPP_ */
