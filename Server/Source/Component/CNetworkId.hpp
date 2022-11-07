/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CNetworkId
*/

#ifndef CNETWORKID_HPP_
    #define CNETWORKID_HPP_

/**
 * @brief A namespace for all components
 */
namespace component {
    /**
     * @brief A strucure representing in the ECS the id of a client in the network
     */
    struct cnetwork_id_t {
        int id; ///< id representing index of client in network endpoints map
    };
}

#endif /* !CNETWORKID_HPP_ */
