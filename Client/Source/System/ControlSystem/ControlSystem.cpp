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
#include "Direction.hpp"
#include "Move.hpp"

ControlSystem::ControlSystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
}

void ControlSystem::operator()(Registry &registry, Sparse_array<component::cposition_t> &positions, Sparse_array<component::velocity_t> &velocities, Sparse_array<component::ckeyboard_t> &keyboards, Sparse_array<component::cnetwork_queue_t> &network)
{
    for (std::size_t i = 0; i < positions.size() && i < velocities.size() && i < keyboards.size(); i++) {
        auto &pos = positions[i];
        auto &vel = velocities[i];
        auto &key = keyboards[i];
        int x, y = 0;

        if (pos && vel) {
            if (key->keyboard->isBeingPressed(key->keyboard->getKeyUpCharCode()))
                y = -1;
                // addToNetworkQueue(1, network);
            if (key->keyboard->isBeingPressed(key->keyboard->getKeyDownCharCode()))
                y = 1;
                // addToNetworkQueue(1, network);
            if (key->keyboard->isBeingPressed(key->keyboard->getKeyLeftCharCode()))
                x = -1;
                // addToNetworkQueue(1, network);
            if (key->keyboard->isBeingPressed(key->keyboard->getKeyRightCharCode()))
                x = 1;
                // addToNetworkQueue(1, network);
            if (key->keyboard->hasBeenPressed(key->keyboard->getKeySpaceCharCode())) {
                x = 2;
                // addToNetworkQueue(1, network);
            }
            if (x && y)
                addToNetworkQueue(x, y, network);
        }
    }
}

void ControlSystem::addToNetworkQueue(int x, int y, Sparse_array<component::cnetwork_queue_t> &network) {
    if (x == 2) {
        packet_shoot packet = {.id = 1};
        std::vector<byte> tmp = serialize_header::serializeHeader<packet_shoot>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::SHOOT, packet);
        network[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(tmp);
    }
    else {
        packet_move packet;
        packet.x = x;
        packet.x = y;
        packet.playerId = 1;
        // packet_direction packet = {.orientation = direction};
        // std::vector<byte> tmp = serialize_header::serializeHeader<packet_move>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::DIRECTION, packet);
        std::vector<byte> tmp = serialize_header::serializeHeader<packet_move>(1, packet);
        network[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(tmp);
    }
}
