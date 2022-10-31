/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** ControlSystem
*/

#include "ControlSystem.hpp"
#include "CRect.hpp"
#include "CPosition.hpp"
#include "Serialization.hpp"
#include "Constant/Constant.hpp"
#include "Move.hpp"

ControlSystem::ControlSystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
}

void ControlSystem::operator()([[ maybe_unused ]] Registry &registry, Sparse_array<component::ckeyboard_t> &keyboards, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cid_of_ship_t> &idOfShip, [[ maybe_unused ]] Sparse_array<component::ccurrscene_t> &currScene)
{
    if (keyboards[0]) {
        auto &key = keyboards[0];
        uint16_t x = 0;
        uint16_t y = 0;

        if (key.value().keyboard->isBeingPressed(key.value().keyboard->getKeyUpCharCode()))
            y = packet_move::DIRECTION::MINUS;
        if (key.value().keyboard->isBeingPressed(key.value().keyboard->getKeyDownCharCode()))
            y = packet_move::DIRECTION::PLUS;
        if (key.value().keyboard->isBeingPressed(key.value().keyboard->getKeyLeftCharCode()))
            x = packet_move::DIRECTION::MINUS;
        if (key.value().keyboard->isBeingPressed(key.value().keyboard->getKeyRightCharCode()))
            x = packet_move::DIRECTION::PLUS;
        if (key.value().keyboard->hasBeenPressed(key.value().keyboard->getKeySpaceCharCode()))
            x = 3;
        if (x || y)
            addToNetworkQueue(x, y, network, idOfShip[0].value().id);
    }
}

void ControlSystem::addToNetworkQueue(float x, float y, Sparse_array<component::cnetwork_queue_t> &network, uint16_t idOfShip)
{
    std::vector<byte> tmp;

    if (x == 3)
        tmp = serialize_header::serializeHeader<packet_shoot>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::SHOOT, {idOfShip});
    else
        tmp = serialize_header::serializeHeader<packet_move>(1, {idOfShip, x, y});
    network[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(tmp);
}
