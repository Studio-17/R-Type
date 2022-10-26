/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** KillSystem
*/

#include "KillSystem.hpp"
#include "Constant.hpp"
#include "KillEntity.hpp"

KillSystem::KillSystem()
{
}

void KillSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cserverid_t> &serverId, Sparse_array<component::ckilled_t> &killed)
{
    while (!network[FORBIDDEN_IDS::NETWORK].value().killEntityQueue.empty()) {
        packet_kill_entity packet = network[FORBIDDEN_IDS::NETWORK]->killEntityQueue.front();
        network[FORBIDDEN_IDS::NETWORK]->killEntityQueue.pop();
        killEntity(registry, packet.id, serverId, killed);
        // std::cout << "[CLIENT] killing entity" << std::endl;
    }
}

void KillSystem::killEntity(Registry &registry, std::size_t id, Sparse_array<component::cserverid_t> &serverId, Sparse_array<component::ckilled_t> &killed)
{
    for (std::size_t x = 0; x < serverId.size(); x += 1) {
        if (serverId[x]->id == id)
            // std::cout << "[CLIENT] killing system n°" << id << std::endl;
            killed[x]->isDead = true;
    }
}

