/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** UpdateEntityInfos
*/

#ifndef UPDATEENTITYINFOS_HPP_
#define UPDATEENTITYINFOS_HPP_

/**
 * @brief A packet to update the life of an entity
 * 
 */
struct packet_update_entity_health {
    int entityId; ///< Id of the entity to update
    int health; ///< Health of the entity
};

/**
 * @brief A packet to update the score of an entity
 * 
 */
struct packet_update_entity_score {
    int entityId; ///< Id of the entity to update
    int score; ///< Score of the entity
};

#endif /* !UPDATEENTITYINFOS_HPP_ */
