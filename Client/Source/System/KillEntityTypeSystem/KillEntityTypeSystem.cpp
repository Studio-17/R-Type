/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** KillEntityTypeSystem
*/

#include "KillEntityTypeSystem.hpp"
#include "Constant.hpp"

/* Packet */
#include "KillEntity.hpp"

System::KillEntityTypeSystem::KillEntityTypeSystem()
{
}

void System::KillEntityTypeSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::ctype_t> &type)
{
    while (!network[FORBIDDEN_IDS::NETWORK].value().killEntityTypeQueue.empty()) {
        packet_kill_entity_type &packet = network[FORBIDDEN_IDS::NETWORK].value().killEntityTypeQueue.front();
        std::cout << "Kill Entity Type System type"<< packet.type  <<std::endl;
        for (std::size_t index = 0; index != type.size(); index++) {
            if (!type[index])
                continue;
            if (type[index].value().type == static_cast<ENTITY_TYPE>(packet.type)) {
                std::cout << "killing entity "  << index<< std::endl;
                registry.kill_entity(registry.entity_from_index(index));
            }
        }
        network[FORBIDDEN_IDS::NETWORK].value().killEntityTypeQueue.pop();
    }
}
