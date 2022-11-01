/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** NewClientSystem
*/

#ifndef NEWCLIENTSYSTEM_HPP_
#define NEWCLIENTSYSTEM_HPP_

#include "Component/CNetIdToClientId.hpp"
#include "Component/CNetworkId.hpp"
#include "Component/CNetworkQueue.hpp"
#include "Registry.hpp"
#include "CLobbiesToEntities.hpp"
#include "CNetworkQueue.hpp"

/**
 * @brief NewClientSystem class that handles the new client
 */
class NewClientSystem {
public:
    /**
     * @brief Construct a new New Client System object
     */
    NewClientSystem();
    ~NewClientSystem() = default;

    /**
     * @brief Function that will be automaticaly called while the client is working (on loop)
     *
     * @param registry registry of the client
     * @param netqueue sparse array of network entities
     */
    void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cnet_id_to_client_id_t> &netIdToClientId, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities);
    void sendLobbiesStatus(Sparse_array<component::cnetwork_queue_t> &networkQueue, Sparse_array<component::clobbies_to_entities_t> &lobbiesToEntities);

protected:
private:
};

#endif /* !NEWCLIENTSYSTEM_HPP_ */
