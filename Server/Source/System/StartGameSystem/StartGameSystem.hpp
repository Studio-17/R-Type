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
    #include "CLobbiesToEntities.hpp"
    #include "CLobbyId.hpp"
    #include "CNetIdToClientId.hpp"
    #include "CPosition.hpp"
    #include "CType.hpp"


class StartGameSystem {
    public:
        StartGameSystem();
        ~StartGameSystem() = default;

        Entity createSpaceShip(Registry &registry); ///< Function that creates a spaceship

        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::clobby_id_t> &LobbyId, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities, Sparse_array<component::cposition_t> &position, Sparse_array<component::ctype_t> &type);
        void createSpaceShip(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::clobby_id_t> &LobbyId, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities);


    protected:
    private:
};

#endif /* !STARTGAMESYSTEM_HPP_ */
