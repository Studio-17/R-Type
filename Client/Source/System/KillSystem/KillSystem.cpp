/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** KillSystem
*/

#include "KillSystem.hpp"

/* Constant */
#include "Constant.hpp"

/* Packet */
#include "KillEntity.hpp"

System::KillSystem::KillSystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
}

void System::KillSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cserverid_t> &serverId, Sparse_array<component::ctype_t> &type, Sparse_array<component::csound_t> &sounds)
{
    while (!network[FORBIDDEN_IDS::NETWORK].value().killEntityQueue.empty()) {
        packet_kill_entity &packet = network[FORBIDDEN_IDS::NETWORK].value().killEntityQueue.front();
        std::cout << "kill system" << std::endl;
        killEntity(registry, packet.id, serverId, type, sounds);
        network[FORBIDDEN_IDS::NETWORK].value().killEntityQueue.pop();
    }
}

void System::KillSystem::killEntity(Registry &registry, std::size_t id, Sparse_array<component::cserverid_t> &serverId, Sparse_array<component::ctype_t> &type, Sparse_array<component::csound_t> &sounds)
{
    for (std::size_t x = 0; x < serverId.size() && x < type.size(); x++) {
        if (serverId[x] && type[x]) {
            // auto &t = type[i];
            if (serverId[x].value().id == id) {
                if (type[x].value().type == ENTITY_TYPE::ENEMY || type[x].value().type == ENTITY_TYPE::ENEMY2 || type[x].value().type == ENTITY_TYPE::ENEMY3)
                    _graphicLib->playASoundMulti(sounds[FORBIDDEN_IDS::NETWORK].value().sounds.at("explosion").getSound());
                registry.kill_entity(registry.entity_from_index(x));
            }
        }
    }
}
