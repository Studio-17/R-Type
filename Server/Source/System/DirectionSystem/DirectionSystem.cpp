/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** DirectionSystem
*/


#include "Registry.hpp"

#include "Component/CDirection.hpp"
#include "Component/CPosition.hpp"
#include "Component/CVelocity.hpp"

#include "DirectionSystem.hpp"
#include "Move.hpp"
#include "Serialization.hpp"
#include "Position.hpp"

DirectionSystem::DirectionSystem()
{
}

void DirectionSystem::operator()(Registry &registry, Sparse_array<component::cnetwork_queue_t> &netqueue, Sparse_array<component::cdirection_t> &direction,Sparse_array<component::cposition_t> &position,Sparse_array<component::cvelocity_t> &velocity)
{
    if (!netqueue[0]->moveQueue.empty()) {
        packet_move packet = netqueue[0]->moveQueue.front();
        std::cout << "id: " << packet.playerId << std::endl;
        netqueue[0]->moveQueue.pop();
        position[packet.playerId]->x += (velocity[packet.playerId]->velocity * packet.x);
        position[packet.playerId]->y += (velocity[packet.playerId]->velocity * packet.y);
        std::cout << "the new player id is " << packet.playerId << std::endl;
        netqueue[0]->toSendNetworkQueue.push(serialize_header::serializeHeader<packet_position>(NETWORK_SERVER_TO_CLIENT::PACKET_TYPE::POSITION, {packet.playerId, position[packet.playerId]->x, position[packet.playerId]->y, 1}));
    }
    // revoit la nouvelle direction d'un client

    // open queue direction et update composant direction 
}
