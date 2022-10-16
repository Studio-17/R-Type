/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** ReceiveSytem
*/

#ifndef RECEIVESYSTEM_HPP_
    #define RECEIVESYSTEM_HPP_

    #include <functional>

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
            void addHitOnQueue(std::vector<byte> const &data, Sparse_array<component::cnetwork_queue_t> &queues);
            void addMoveOnQueue(std::vector<byte> const &data, Sparse_array<component::cnetwork_queue_t> &queues);
            void addShootOnQueue(std::vector<byte> const &data, Sparse_array<component::cnetwork_queue_t> &queues);

            std::unordered_map<uint8_t, std::function<void(std::vector<byte> const &, Sparse_array<component::cnetwork_queue_t> &)>> callBacks {
                // {0, std::bind(&ReceiveSystem::addHitOnQueue, this, std::placeholders::_1, std::placeholders::_2)},
                {NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::DIRECTION, std::bind(&ReceiveSystem::addMoveOnQueue, this, std::placeholders::_1, std::placeholders::_2)},
                {NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::SHOOT, std::bind(&ReceiveSystem::addShootOnQueue, this, std::placeholders::_1, std::placeholders::_2)}
            };
    };
};

#endif /* !RECEIVESYSTEM_HPP_ */
