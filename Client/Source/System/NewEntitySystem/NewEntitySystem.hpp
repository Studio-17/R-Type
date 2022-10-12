/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewEntitySystem
*/

#ifndef NEWENTITYSYSTEM_HPP_
    #define NEWENTITYSYSTEM_HPP_

    #include "Registry.hpp"
    #include "CNetworkQueue.hpp"

class NewEntitySystem {
    public:
        NewEntitySystem();
        ~NewEntitySystem();

        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network);

    protected:
    private:
};

#endif /* !NEWENTITYSYSTEM_HPP_ */
