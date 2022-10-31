/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** DisconnectionSystem
*/

#ifndef DISCONNECTIONSYSTEM_HPP_
    #define DISCONNECTIONSYSTEM_HPP_

    #include "Registry.hpp"
    #include "CNetworkQueue.hpp"

/**
 * @brief The Disconnection System class, it handles disconnection of a client
 */
class DisconnectionSystem {
    public:
        /**
         * @brief Construct a new Disconnection System object
         */
        DisconnectionSystem();
        /**
         * @brief Destroy the Disconnection System object
         */
        ~DisconnectionSystem() = default;

        /**
         * @brief The main handler for the Disconnection System
         *
         * @param registry the registry of the server
         */
        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network_queues);

    protected:
    private:
};

#endif /* !DISCONNECTIONSYSTEM_HPP_ */
