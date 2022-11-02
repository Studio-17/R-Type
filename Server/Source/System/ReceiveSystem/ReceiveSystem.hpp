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

    #include "Registry.hpp"
    #include "Component/CNetworkQueue.hpp"
    #include "Serialization.hpp"

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
            /**
             * @brief Destroy the Event System object
             */
            ~ReceiveSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry The registry that contains all the ECS
             */
            void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &queues);

        protected:
        private:
            // /**
            //  * @brief Adds a packet to the queue of hits handling
            //  * 
            //  * @param data 
            //  * @param queues 
            //  */
            // void addHitOnQueue(std::vector<byte> const &data, Sparse_array<component::cnetwork_queue_t> &queues);

            /**
             * @brief Adds a packet to the queue of movement handling
             * 
             * @param data 
             * @param queues 
             */
            void addMoveOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues);

            /**
             * @brief Adds a packet to the queue of shoot handling
             * 
             * @param data 
             * @param queues 
             */
            void addShootOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues);

            /**
             * @brief Adds a packet to the queue of new player handling
             * 
             * @param data 
             * @param queues 
             */
            void addNewPLayerOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues);

            /**
             * @brief Adds a packet to the queue of new player handling
             * 
             * @param data 
             * @param queues 
             */
            void addDisconnectionOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues);

            void addJoinLobbyOnQueue(std::vector<byte> const &data, int clientId, Sparse_array<component::cnetwork_queue_t> &queues);


            /**
             * @brief A map that links every OnQueue method to a type of packet
             * 
             */
            std::unordered_map<uint8_t, std::function<void(std::vector<byte> const &, int, Sparse_array<component::cnetwork_queue_t> &)>> callBacks {
                // {0, std::bind(&ReceiveSystem::addHitOnQueue, this, std::placeholders::_1, std::placeholders::_2)},
                // Rework
                // {NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::NEW_CONNECTION, std::bind(&ReceiveSystem::addNewPLayerOnQueue, this, std::placeholders::_1, std::placeholders::_2)},
                {NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::NEW_CLIENT, std::bind(&ReceiveSystem::addNewPLayerOnQueue, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)},
                //*
                {NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::DIRECTION, std::bind(&ReceiveSystem::addMoveOnQueue, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)},
                {NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::SHOOT, std::bind(&ReceiveSystem::addShootOnQueue, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)},
                {NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::DISCONNECTION, std::bind(&ReceiveSystem::addDisconnectionOnQueue, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)},
                {NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::JOIN_LOBBY, std::bind(&ReceiveSystem::addJoinLobbyOnQueue, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)}
            };
    };
};

#endif /* !RECEIVESYSTEM_HPP_ */
