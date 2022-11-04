/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** GetLobbiesSystem
*/

#ifndef GETLOBBIESSYSTEM_HPP_
    #define GETLOBBIESSYSTEM_HPP_

    #include "Registry.hpp"
    #include "CNetworkQueue.hpp"

class GetLobbiesSystem {
    public:
        GetLobbiesSystem();
        ~GetLobbiesSystem() = default;

        void operator()([[ maybe_unused ]]Registry &registry, Sparse_array<component::cnetwork_queue_t> &networkQueue);

    protected:
    private:
};

#endif /* !GETLOBBIESSYSTEM_HPP_ */
