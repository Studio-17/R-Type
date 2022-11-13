/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** UpdateEntityInfosSystem
*/

#include "UpdateEntityInfosSystem.hpp"
#include "Constant.hpp"
#include "UpdateEntityInfos.hpp"

System::UpdateEntityInfosSystem::UpdateEntityInfosSystem()
{
}

void System::UpdateEntityInfosSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::chealth_t> &health, Sparse_array<component::cscore_t> &score, Sparse_array<component::cnetwork_queue_t> &netQueue, Sparse_array<component::cserverid_t> &serverId, Sparse_array<component::ctext_t> &texts, Sparse_array<component::cref_t> &refs)
{
    while (!netQueue[FORBIDDEN_IDS::NETWORK].value().updateEntityHealthQueue.empty()) {
        packet_update_entity_health &packet = netQueue[FORBIDDEN_IDS::NETWORK].value().updateEntityHealthQueue.front();
        std::cout << "First print update entity health !" << std::endl;
        for (std::size_t index = 0; index != serverId.size(); index++) {
            if (serverId[index]) {
                if (serverId[index].value().id == packet.entityId) {
                    std::cout << "Update entity health: " << packet.health << std::endl;
                    Entity newHealth = registry.entity_from_index(static_cast<std::size_t>(refs[FORBIDDEN_IDS::NETWORK].value().ref.at("health-spaceship-txt")));
                    texts[newHealth].value().text = "Lives: " + std::to_string(packet.health);
                    health[index].value().health = packet.health;
                }
            }
        }
        netQueue[FORBIDDEN_IDS::NETWORK].value().updateEntityHealthQueue.pop();
    }
    while (!netQueue[FORBIDDEN_IDS::NETWORK].value().updateEntityScoreQueue.empty()) {
        packet_update_entity_score &packetScore = netQueue[FORBIDDEN_IDS::NETWORK].value().updateEntityScoreQueue.front();
        for (std::size_t index = 0; index != serverId.size(); index++) {
            if (serverId[index]) {
                if (serverId[index].value().id == packetScore.entityId) {
                    Entity newScore = registry.entity_from_index(static_cast<std::size_t>(refs[FORBIDDEN_IDS::NETWORK].value().ref.at("score-spaceship-txt")));
                    texts[newScore].value().text = "Score: " + std::to_string(packetScore.score);
                    std::cout << "First print update entity score !" << std::endl;
                    std::cout << "second print update entity score " << std::endl;
                    score[index].value().score = packetScore.score;
                }
            }
        }
        netQueue[FORBIDDEN_IDS::NETWORK].value().updateEntityScoreQueue.pop();
    }

}