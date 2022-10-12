/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NetworkSystem
*/

#ifndef NETWORKSYSTEM_HPP_
    #define NETWORKSYSTEM_HPP_

    #include "Registry.hpp"
    #include "CNetworkQueue.hpp"

class NetworkSystem {
    public:
        NetworkSystem();
        ~NetworkSystem() = default;

        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network);



    protected:
    private:
};

#endif /* !NETWORKSYSTEM_HPP_ */
