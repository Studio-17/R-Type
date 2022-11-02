/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** JoinLobbySystem
*/

#ifndef JOINLOBBYSYSTEM_HPP_
    #define JOINLOBBYSYSTEM_HPP_

    #include "Registry.hpp"
    #include "CNetworkQueue.hpp"
    #include "CLobbyId.hpp"
    #include "CLobbiesToEntities.hpp"

class JoinLobbySystem {
    public:
        JoinLobbySystem();
        ~JoinLobbySystem() = default;

        void operator()(Sparse_array<component::cnetwork_queue_t> &networkQueue, Sparse_array<component::clobby_id_t> &lobbyId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities);

    protected:
    private:
};

#endif /* !JOINLOBBYSYSTEM_HPP_ */
