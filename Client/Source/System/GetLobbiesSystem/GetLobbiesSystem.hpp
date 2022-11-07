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
    #include "CAsset.hpp"

class GetLobbiesSystem {
    public:
        GetLobbiesSystem();
        ~GetLobbiesSystem() = default;

        void operator()([[ maybe_unused ]]Registry &registry, Sparse_array<component::cnetwork_queue_t> &networkQueue, Sparse_array<component::casset_t> &assets);

        void createLobby(Registry &registry, packet_send_lobbies &lobbiesInfos, Sparse_array<component::casset_t> &assets);

    protected:
    private:
};

#endif /* !GETLOBBIESSYSTEM_HPP_ */
