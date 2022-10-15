/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** ControlSystem
*/

#include "ControlSystem.hpp"
#include "CSprite.hpp"
#include "CRect.hpp"
#include "CPosition.hpp"
#include "Serialization.hpp"
#include "Constant/Constant.hpp"
#include "Move.hpp"

ControlSystem::ControlSystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
}

void ControlSystem::operator()(Registry &registry, Sparse_array<component::cposition_t> &positions, Sparse_array<component::cvelocity_t> &velocities, Sparse_array<component::ckeyboard_t> &keyboards, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cserverid_t> &serverId)
{
    auto &key = keyboards[0];
    int x = 0;
    int y = 0;

    if (key->keyboard->isBeingPressed(key->keyboard->getKeyUpCharCode()))
        y = -1;
    if (key->keyboard->isBeingPressed(key->keyboard->getKeyDownCharCode()))
        y = 1;
    if (key->keyboard->isBeingPressed(key->keyboard->getKeyLeftCharCode()))
        x = -1;
    if (key->keyboard->isBeingPressed(key->keyboard->getKeyRightCharCode()))
        x = 1;
    if (key->keyboard->hasBeenPressed(key->keyboard->getKeySpaceCharCode()))
        x = 2;
    if (x || y)
        addToNetworkQueue(x, y, network, serverId[1]->id);
}

void ControlSystem::addToNetworkQueue(int x, int y, Sparse_array<component::cnetwork_queue_t> &network, std::size_t serverId) {
    if (x == 2) {
        packet_shoot packet = {.id = 1};
        std::vector<byte> tmp = serialize_header::serializeHeader<packet_shoot>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::SHOOT, packet);
        network[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(tmp);
    }
    else {
        packet_move packet;
        packet.x = x;
        packet.y = y;
        packet.playerId = 1;
        std::vector<byte> tmp = serialize_header::serializeHeader<packet_move>(1, packet);
        network[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(tmp);
    }
}
