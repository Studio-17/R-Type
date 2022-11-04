/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** CNetIdToClientId
*/

#ifndef CNETIDTOCLIENTID_HPP_
#define CNETIDTOCLIENTID_HPP_

#include <unordered_map>
#include "Entity.hpp"

/**
 * @brief A namespace for all components
 * 
 */
namespace component {
    /**
     * @brief A structure representing the network id corresponding to the client id
     */
    struct cnet_id_to_client_id_t {
        std::unordered_map<int, Entity> netIdToClientId;
    };
}

#endif /* !CNETIDTOCLIENTID_HPP_ */
