/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewLevelSystem
*/

#include "NewLevelSystem.hpp"
#include "Constant.hpp"
#include "NewLevel.hpp"

System::NewLevelSystem::NewLevelSystem()
{
}

void System::NewLevelSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::cnetwork_queue_t> &netQueue, Sparse_array<component::cserverid_t> &serverId, Sparse_array<component::ctext_t> &texts, Sparse_array<component::cref_t> &refs)
{
    (void)texts;
    (void)refs;
    (void)serverId;
    // level-game-txt
    while (!netQueue[FORBIDDEN_IDS::NETWORK].value().newLevelQueue.empty()) {
        packet_new_level &packet = netQueue[FORBIDDEN_IDS::NETWORK].value().newLevelQueue.front();
        std::cout << "New Level : " << packet.level << std::endl;
        Entity newScore = registry.entity_from_index(static_cast<std::size_t>(refs[FORBIDDEN_IDS::NETWORK].value().ref.at("level-game-txt")));
        texts[newScore].value().text = "Level: " + std::to_string(packet.level + 1) + " / " + std::to_string(packet.totalLevels);
        netQueue[FORBIDDEN_IDS::NETWORK].value().newLevelQueue.pop();
    }
}
