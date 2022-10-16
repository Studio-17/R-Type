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
    uint16_t x = 0;
    uint16_t y = 0;

    if (key->keyboard->isBeingPressed(key->keyboard->getKeyUpCharCode()))
        y = packet_move::DIRECTION::MOIN;
    if (key->keyboard->isBeingPressed(key->keyboard->getKeyDownCharCode()))
        y = packet_move::DIRECTION::PLUS;
    if (key->keyboard->isBeingPressed(key->keyboard->getKeyLeftCharCode()))
        x = packet_move::DIRECTION::MOIN;
    if (key->keyboard->isBeingPressed(key->keyboard->getKeyRightCharCode()))
        x = packet_move::DIRECTION::PLUS;
    if (key->keyboard->hasBeenPressed(key->keyboard->getKeySpaceCharCode()))
        x = 3;
    if (x || y)
        addToNetworkQueue(x, y, network, serverId[1]->id);
}

void ControlSystem::addToNetworkQueue(uint16_t x, uint16_t y, Sparse_array<component::cnetwork_queue_t> &network, std::size_t serverId) {
    std::vector<byte> tmp;
    if (x == 3)
        tmp = serialize_header::serializeHeader<packet_shoot>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::SHOOT, {1});
    else
        tmp = serialize_header::serializeHeader<packet_move>(1, {1, x, y});
    network[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(tmp);
}
