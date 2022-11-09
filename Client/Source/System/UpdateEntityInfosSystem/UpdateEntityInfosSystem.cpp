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

void System::UpdateEntityInfosSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::chealth_t> &health, Sparse_array<component::cscore_t> &score, Sparse_array<component::cnetwork_queue_t> &netQueue, Sparse_array<component::cserverid_t> &serverId)
{
    while (!netQueue[FORBIDDEN_IDS::NETWORK].value().updateEntityHealthQueue.empty()) {
        packet_update_entity_health &packet = netQueue[FORBIDDEN_IDS::NETWORK].value().updateEntityHealthQueue.front();
        for (std::size_t index = 0; index != serverId.size(); index++) {
            if (serverId[index]) {
                if (serverId[index].value().id == packet.entityId) {
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
                    score[index].value().score = packetScore.score;
                }
            }
        }
        netQueue[FORBIDDEN_IDS::NETWORK].value().updateEntityScoreQueue.pop();
    }

}