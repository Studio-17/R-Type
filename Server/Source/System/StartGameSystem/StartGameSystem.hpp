/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** StartGameSystem
*/

#ifndef STARTGAMESYSTEM_HPP_
    #define STARTGAMESYSTEM_HPP_

    #include "Registry.hpp"
    #include "CNetworkQueue.hpp"


class StartGameSystem {
    public:
        StartGameSystem();
        ~StartGameSystem() = default;

        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue);

    protected:
    private:
};

#endif /* !STARTGAMESYSTEM_HPP_ */
