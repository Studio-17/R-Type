/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CConnection
*/

#ifndef CCONNECTION_HPP_
#define CCONNECTION_HPP_

/**
 * @brief Namespace for all components
 * 
 */
namespace Component {
    /**
     * @brief Strucure representing wether the client is connected to the the server or not.
     * 
     */
    typedef struct Connection {
        bool _isConnected;
    }
}

#endif /* !CCONNECTION_HPP_ */
