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

class NewPlayerSystem {
    public:
        NewPlayerSystem();
        ~NewPlayerSystem() = default;

        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cposition_t> &position, Sparse_array<component::ctype_t> &type,  Sparse_array<component::ckilled_t> &killed);
    protected:
    private:
        Entity createSpaceShip(Registry &registry);

};

#endif /* !NEWPLAYERSYSTEM_HPP_ */
