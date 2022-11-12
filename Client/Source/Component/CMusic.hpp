/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CMusic
*/

#ifndef CMUSIC_HPP_
    #define CMUSIC_HPP_

    #include "MusicManager.hpp"

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing all musics
     */
    struct cmusic_t {
        MusicManager musics; ///< MusicManager containing all sounds
    };
}

#endif /* !CMUSIC_HPP_ */
