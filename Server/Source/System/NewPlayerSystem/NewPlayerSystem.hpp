/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewPlayerSystem
*/

#ifndef NEWPLAYERSYSTEM_HPP_
    #define NEWPLAYERSYSTEM_HPP_

    #include "Registry.hpp"
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CPosition.hpp"
    #include "CType.hpp"
    #include "CKilled.hpp"

/**
 * @brief NewPlayerSystem class that handles the new player
 * 
 */
class NewPlayerSystem {
    public:
        /**
         * @brief Construct a new New Player System object
         * 
         */
        NewPlayerSystem();
        /**
         * @brief Destroy the New Player System object
         * 
         */
        ~NewPlayerSystem() = default;

        /**
         * @brief Function that will be automaticaly called while the client is working (on loop)
         * 
         * @param registry registry of the client
         * @param netqueue sparse array of network entities
         * @param position sparse array of position entities
         * @param type sparse array of type entities
         * @param killed sparse array of killed entities
         */
        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position, Sparse_array<component::ctype_t> &type,  Sparse_array<component::ckilled_t> &killed);
    protected:
    private:
        Entity createSpaceShip(Registry &registry); ///< Function that creates a spaceship

};

#endif /* !NEWPLAYERSYSTEM_HPP_ */
