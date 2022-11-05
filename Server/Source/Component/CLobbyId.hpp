/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CRoomId
*/

#ifndef CLOBBYID_HPP_
    #define CLOBBYID_HPP_

/**
 * @brief enum of Lobby id
 */
enum LOBBY {
    DEFAULT = -1
};

/**
 * @brief A namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing the lobby id where the entity is
     */
    struct clobby_id_t {
        int id; ///< id of the lobby where is the Entity
    };
}

#endif /* !CLOBBYID_HPP_ */
