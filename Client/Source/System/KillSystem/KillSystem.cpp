/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** KillSystem
*/

#include "KillSystem.hpp"
#include "Constant.hpp"

/* Packet */
#include "KillEntity.hpp"

System::KillSystem::KillSystem()
{
}

void System::KillSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cserverid_t> &serverId)
{
    while (!network[FORBIDDEN_IDS::NETWORK].value().killEntityQueue.empty()) {
        packet_kill_entity &packet = network[FORBIDDEN_IDS::NETWORK].value().killEntityQueue.front();
        std::cout << "kill system" << std::endl;
        killEntity(registry, packet.id, serverId);
        network[FORBIDDEN_IDS::NETWORK].value().killEntityQueue.pop();
    }
}

void System::KillSystem::killEntity(Registry &registry, std::size_t id, Sparse_array<component::cserverid_t> &serverId)
{
    for (std::size_t x = 0; x < serverId.size(); x++) {
        if (serverId[x]) {
            if (serverId[x].value().id == id) {
                registry.kill_entity(registry.entity_from_index(x));
            }
        }
    }
}
