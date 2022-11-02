/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** SetNbPlayerInLobbySystem
*/

#ifndef SETNBPLAYERINLOBBYSYSTEM_HPP_
    #define SETNBPLAYERINLOBBYSYSTEM_HPP_

    #include "Registry.hpp"
    #include "CNetworkQueue.hpp"

class SetNbPlayerInLobbySystem {
    public:
        /**
         * @brief Set the Nb Player In Lobby System object
         * 
         */
        SetNbPlayerInLobbySystem();
        /**
         * @brief Destroy the Set Nb Player In Lobby System object
         * 
         */
        ~SetNbPlayerInLobbySystem() = default;

        /**
         * @brief Function that will be automaticaly called while the client is working (on loop)
         *
         * @param registry registry of the client
         * @param sprites sparse array of sprite entities
         * @param rectangles sparse array of rectangle entities
         * @param timer sparse array of timer entities
         * @param types sparse array of type entities
         */
        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &networkQueue);

    protected:
    private:
};

#endif /* !SETNBPLAYERINLOBBYSYSTEM_HPP_ */
