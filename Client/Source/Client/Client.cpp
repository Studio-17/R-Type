/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#include <iostream>
#include <functional>

#include "Client.hpp"
#include "CurrScene.hpp"
#include "Mouse.hpp"
#include "CSprite.hpp"
#include "CKeyboard.hpp"
#include "CPosition.hpp"
#include "CRect.hpp"
#include "CVelocity.hpp"
#include "CServerId.hpp"
#include "CNetworkQueue.hpp"
#include "Serialization.hpp"
#include "Structure.hpp"
#include "CType.hpp"
#include "CKilled.hpp"
#include "Move.hpp"
#include "NewConnexion.hpp"
#include "CIdOfShip.hpp"

Client::Client(std::string const &ip, std::string const &port, int hostPort) :
    _com(std::make_unique<UdpCommunication>(_context, hostPort, port, ip)),
    _connected(true)
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
    _graphicLib->initWindow(800, 600, "R-Type", 60);

    setUpEcs();
    setUpSystems();
    setUpComponents();
    _thread = std::thread(&Client::threadLoop, this);
}

Client::~Client()
{
    _context.stop();
    _connected = false;
    _thread.join();
}

void Client::tryToConnect()
{
    packet_new_connexion packet = {.id = 0};
    std::vector<byte> bytes = serialize_header::serializeHeader<packet_new_connexion>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::NEW_CONNEXION, packet);
    _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(bytes);
}

void Client::machineRun()
{
    tryToConnect();
    while (!_graphicLib->windowShouldClose()) {
        _graphicLib->startDrawingWindow();
            _graphicLib->clearScreen();
            _registry.run_systems();
        _graphicLib->endDrawingWindow();
        SendPacket();
    }
    _graphicLib->closeWindow();
    _connected = false;
}

void Client::SendPacket() {
    if (!_registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.empty()) {
        std::vector<byte> tmp = _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK]->toSendNetworkQueue.front();
        _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK]->toSendNetworkQueue.pop();
        _com->send(tmp);
    }
}


void Client::handleReceive() {
    _com->async_receive(_bufferToGet, std::bind(&Client::pushNewPacketsToQueue, this, std::placeholders::_1, std::placeholders::_2));
}

void Client::pushNewPacketsToQueue(asio::error_code const &e, size_t nbBytes)
{
    _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK]->receivedNetworkQueue.push(_bufferToGet);
    handleReceive();
}

void Client::setUpEcs()
{
    _registry.register_component<component::ckeyboard_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::mouseState_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::csprite_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::cposition_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::crect_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
	_registry.register_component<component::cvelocity_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
	_registry.register_component<component::cserverid_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
	_registry.register_component<component::cnetwork_queue_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
	_registry.register_component<component::cdirection_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
	_registry.register_component<component::cid_of_ship_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::ctype_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::ckilled_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
}

void Client::setUpSystems()
{
	_registry.add_system(_networkSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cid_of_ship_t>());
	_registry.add_system(_drawSystem, _registry.get_components<component::csprite_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::crect_t>(), _registry.get_components<component::ckilled_t>());
    _registry.add_system(_rectSystem, _registry.get_components<component::csprite_t>(), _registry.get_components<component::crect_t>());
    _registry.add_system(_controlSystem, _registry.get_components<component::cposition_t>(), _registry.get_components<component::cvelocity_t>(), _registry.get_components<component::ckeyboard_t>(), _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cid_of_ship_t>());
    _registry.add_system(_newEntitySystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cserverid_t>());
    _registry.add_system(_positionSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::cserverid_t>());
    _registry.add_system(_moveSystem, _registry.get_components<component::cdirection_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::cvelocity_t>(), _registry.get_components<component::ckilled_t>());
    _registry.add_system(_killSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cserverid_t>(), _registry.get_components<component::ckilled_t>());
}

void Client::setUpComponents()
{
    Entity network = _registry.spawn_entity();
    Entity parallax = _registry.spawn_entity();

    // Network entity
    component::cnetwork_queue_t nnetwork = {};
    _registry.add_component<component::cnetwork_queue_t>(_registry.entity_from_index(network), std::move(nnetwork));

    component::ctype_t ntype = {.type = NET};
    _registry.add_component<component::ctype_t>(_registry.entity_from_index(network), std::move(ntype));

    component::cid_of_ship_t idOfShip = {.id = 0};
    _registry.add_component<component::cid_of_ship_t>(_registry.entity_from_index(network), std::move(idOfShip));

    component::ckeyboard_t keyboard = {.keyboard = 0};
	_registry.add_component<component::ckeyboard_t>(_registry.entity_from_index(network), std::move(keyboard));

    // Parallax Entity
    component::crect_t prect = {0, 0, 600, 800, 1, 6000};
    _registry.add_component<component::crect_t>(_registry.entity_from_index(parallax), std::move(prect));

    component::csprite_t psprite = {.sprite = _graphicLib->createSprite("Assets/parallax/parallax.png", 1, (Rectangle){.x = prect.x, .y = prect.y, .width = prect.width, .height = prect.height})};
    _registry.add_component<component::csprite_t>(_registry.entity_from_index(parallax), std::move(psprite));

    component::cposition_t pposition = {0, 0};
    _registry.add_component<component::cposition_t>(_registry.entity_from_index(parallax), std::move(pposition));

    component::cdirection_t pdirection = {.x = 0, .y = 0};
    _registry.add_component<component::cdirection_t>(_registry.entity_from_index(parallax), std::move(pdirection));

    component::ctype_t ptype = {.type = UI};
    _registry.add_component<component::ctype_t>(_registry.entity_from_index(parallax), std::move(ptype));
    _registry.add_component<component::ckilled_t>(_registry.entity_from_index(parallax), {false});

}

void Client::threadLoop()
{
    handleReceive();
    _context.run();
}