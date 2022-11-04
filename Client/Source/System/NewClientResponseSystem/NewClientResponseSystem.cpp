/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** NewClientResponse
*/

#include "NewClientResponseSystem.hpp"
#include "Constant.hpp"

NewClientResponseSystem::NewClientResponseSystem() {
}

void NewClientResponseSystem::operator()([[ maybe_unused ]]Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cclient_network_id> &clientNetworkId) {
    while (!netqueue[FORBIDDEN_IDS::NETWORK].value().newConnectionResponseQueue.empty()) {
        packet_new_connection_response &new_connection_response = netqueue[FORBIDDEN_IDS::NETWORK].value().newConnectionResponseQueue.front();
        std::cout << "Nes client response system : recive network client id : " << new_connection_response.id << std::endl;
        clientNetworkId[FORBIDDEN_IDS::NETWORK].value().id = new_connection_response.id;
        (void)clientNetworkId;
        netqueue[FORBIDDEN_IDS::NETWORK].value().newConnectionResponseQueue.pop();

    }
}
