/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewClientResponseSystem
*/

#ifndef NEWCLIENTRESPONSESYSTEM_HPP_
    #define NEWCLIENTRESPONSESYSTEM_HPP_

    #include "Registry.hpp"
    #include "CNetworkQueue.hpp"
    #include "CClientNetworkId.hpp"

class NewClientResponseSystem {
    public:
        NewClientResponseSystem();
        ~NewClientResponseSystem() = default;

        void operator()([[ maybe_unused ]]Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cclient_network_id> &clientNetworkId);

    protected:
    private:
};

#endif /* !NEWCLIENTRESPONSESYSTEM_HPP_ */
