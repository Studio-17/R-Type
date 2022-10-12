/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** PositionSystem
*/

#ifndef POSITIONSYSTEM_HPP_
    #define POSITIONSYSTEM_HPP_

    #include "Registry.hpp"
    #include "CNetworkQueue.hpp"
    #include "CPosition.hpp"

class PositionSystem {
    public:
        PositionSystem();
        ~PositionSystem();

        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cposition_t> &position);

    protected:
    private:
};

#endif /* !POSITIONSYSTEM_HPP_ */
