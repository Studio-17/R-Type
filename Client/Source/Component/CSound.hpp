/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** CSound
*/

#ifndef CSOUND_HPP_
    #define CSOUND_HPP_

    #include "SoundManager.hpp"

/**
 * @brief Namespace for all components
 */
namespace component {
    /**
     * @brief A structure representing all sounds
     */
    struct csound_t {
        SoundManager sounds; ///< SoundManager containing all sounds
    };
}

#endif /* !CSOUND_HPP_ */
