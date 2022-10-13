/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewEntitySystem
*/

#ifndef NEWENTITYSYSTEM_HPP_
    #define NEWENTITYSYSTEM_HPP_

    #include <string>
    #include <map>
    #include <utility>

    #include "Registry.hpp"
    #include "GraphicalLib.hpp"
    #include "CNetworkQueue.hpp"
    #include "CServerId.hpp"
    #include "Constant.hpp"

class NewEntitySystem {
    public:
        NewEntitySystem();
        ~NewEntitySystem();

        void operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cserverid_t> &serverIds);

    protected:
    private:
        std::unique_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
        std::map<ENTITY_TYPE, std::pair<std::string, component::crect_t>> _entityType; ///< Map of the entity type
};

#endif /* !NEWENTITYSYSTEM_HPP_ */
