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
#include "Velocity.hpp"
#include "CServerId.hpp"
#include "CNetworkQueue.hpp"
#include "Serialization.hpp"
#include "Structure.hpp"

Client::Client(std::string const &ip, std::string const &port, int hostPort) :
    _com(std::make_unique<UdpCommunication>(_context, hostPort, port, ip)),
    _working(true)
{
    _context.run();

    _graphicLib = std::make_unique<rtype::GraphicalLib>();
    _graphicLib->initWindow(800, 600, "R-Type", 60);

    setUpEcs();
    setUpSystems();
    setUpComponents();
}

Client::~Client()
{
    _context.stop();
}

void Client::machineRun(void)
{
    while (!_graphicLib->windowShouldClose()) {
        _graphicLib->startDrawingWindow();
            _graphicLib->clearScreen();
            _registry.run_systems();
        _graphicLib->endDrawingWindow();
        handleSendPacket();
    }
    _graphicLib->closeWindow();
}

void Client::handleSendPacket() {
    if (!_registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.empty()) {
        std::vector<byte> tmp = _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.front();
        _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.pop();
        _com->async_send(tmp, std::function<void(std::error_code, std::size_t)>());
    }
}

void Client::handleReceive() {
    _com->async_receive(_bufferToGet, std::bind(&Client::pushNewPacketsToQueue, this, std::placeholders::_1, std::placeholders::_2));
}

void Client::pushNewPacketsToQueue(asio::error_code const &e, size_t nbBytes)
{
    _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.push(_bufferToGet);

}

void Client::setUpEcs()
{
    _registry.register_component<component::ckeyboard_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::mouseState_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::csprite_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::cposition_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::crect_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
	_registry.register_component<component::velocity_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
	_registry.register_component<component::cserverid_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
	_registry.register_component<component::cnetwork_queue_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
}

void Client::setUpSystems()
{
	_registry.add_system(_drawSystem, _registry.get_components<component::csprite_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::crect_t>());
    _registry.add_system(_rectSystem, _registry.get_components<component::csprite_t>(), _registry.get_components<component::crect_t>());
    _registry.add_system(_controlSystem, _registry.get_components<component::cposition_t>(), _registry.get_components<component::velocity_t>(), _registry.get_components<component::ckeyboard_t>(), _registry.get_components<component::cnetwork_queue_t>());
    _registry.add_system(_newEntitySystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cserverid_t>());
    // _registry.add_system(_positionSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::cserverid_t>());
}

void Client::setUpComponents()
{
    Entity parallax = _registry.spawn_entity();
    Entity ship = _registry.spawn_entity();

    // Parallax Entity
    component::crect_t prect = {0, 0, 600, 800, 1, 600};
    component::csprite_t psprite = {.sprite = _graphicLib->createSprite("Assets/parallax/parallax.png", 1, (Rectangle){.x = prect.x, .y = prect.y, .width = prect.width, .height = prect.height})};
    component::cposition_t pposition = {0, 0};
    component::velocity_t pvel = {.velocity = 10};
	_registry.add_component<component::velocity_t>(_registry.entity_from_index(parallax), std::move(pvel));
    component::ckeyboard_t pkeyboard = {.keyboard = 0};
	_registry.add_component<component::ckeyboard_t>(_registry.entity_from_index(parallax), std::move(pkeyboard));
    component::cnetwork_queue_t pnetwork = {};
    _registry.add_component<component::cnetwork_queue_t>(_registry.entity_from_index(parallax), std::move(pnetwork));
    _registry.add_component<component::crect_t>(_registry.entity_from_index(parallax), std::move(prect));
     _registry.add_component<component::csprite_t>(_registry.entity_from_index(parallax), std::move(psprite));
     _registry.add_component<component::cposition_t>(_registry.entity_from_index(parallax), std::move(pposition));

    // Ship Entity
    component::crect_t rect = {0, 0, 33.3125, 36, 1, 8};
    _registry.add_component<component::crect_t>(_registry.entity_from_index(ship), std::move(rect));

    component::csprite_t sprite = {.sprite = _graphicLib->createSprite("Assets/sprites/r-typesheet5.gif", 1, (Rectangle){.x = rect.x, .y = rect.y, .width = rect.width, .height = rect.height})};
    _registry.add_component<component::csprite_t>(_registry.entity_from_index(ship), std::move(sprite));

    component::cposition_t position = {10, 50};
    _registry.add_component<component::cposition_t>(_registry.entity_from_index(ship), std::move(position));

    component::velocity_t vel = {.velocity = 10};
	_registry.add_component<component::velocity_t>(_registry.entity_from_index(ship), std::move(vel));

    component::ckeyboard_t keyboard = {.keyboard = 0};
	_registry.add_component<component::ckeyboard_t>(_registry.entity_from_index(ship), std::move(keyboard));

    component::cnetwork_queue_t network = {};
    _registry.add_component<component::cnetwork_queue_t>(_registry.entity_from_index(ship), std::move(network));
}
