/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CClientNetworkId
*/

#ifndef CCLIENTNETWORKID_HPP_
    #define CCLIENTNETWORKID_HPP_

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A strucure representing the newtork id of the client
     */
    struct cclient_network_id {
        int id; ///< Id of the client in server network
        int controllableNetworkEntityId; ///< Id of the entity controlable by the client
    };
}

#endif /* !CCLIENTNETWORKID_HPP_ */
