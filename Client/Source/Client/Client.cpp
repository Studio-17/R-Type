/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#include <iostream>

#include "Client.hpp"
#include "CurrScene.hpp"
#include "Mouse.hpp"
#include "CSprite.hpp"
#include "CKeyboard.hpp"
#include "CPosition.hpp"
#include "CRect.hpp"
#include "Velocity.hpp"
#include "Serialization.hpp"
#include "Structure.hpp"
#include "CNetworkQueue.hpp"

Client::Client(std::string const &ip, std::string const &port, int hostPort) :
    _com(std::make_unique<UdpCommunication>(_context, hostPort, port, ip)),
    _working(true)
{
    _context.run();

    _graphicLib = std::make_unique<rtype::GraphicalLib>();
    _graphicLib->initWindow(800, 600, "R-Type", 60);

    setUpEcs();
    setUpComponents();
}

Client::~Client()
{
    _context.stop();
}

void Client::machineRun(void)
{
	Header header {.id = rand() % 9, .data = 4, .pr = {.pt = 3, .second = 9}};
	auto buffer_to_send = serializable_trait<Header>::serialize(header);
	_com->send(buffer_to_send);
    std::cout << "sended" << std::endl;

    while (!_graphicLib->windowShouldClose()) {
        // _com->receive(_bufferToGet);//, std::bind(&Client::handleReceive, this));
        // handleReceive();
        _graphicLib->startDrawingWindow();
            _graphicLib->clearScreen();
            _registry.run_systems();
        _graphicLib->endDrawingWindow();
    }
    _graphicLib->closeWindow();
}

void Client::handleReceive()
{
    u_int8_t id = serialize_header::getId(_bufferToGet);
    std::vector<byte> data;
    data.insert(data.begin(), _bufferToGet.begin() + sizeof(u_int8_t), _bufferToGet.end());
    ServerResponse response = serializable_trait<ServerResponse>::unserialize(data);
    std::cout << "response: " << response.code << std::endl;
}

void Client::handleSendPacket() {
    if (!_registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.empty()) {
        std::vector<byte> &tmp = _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.front();
        _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.pop();
    }
}

void Client::parsePacket(std::vector<byte> &bytes) {
    u_int8_t id = serialize_header::getId(bytes);

    switch (id) {
        case 1:

    }

}

void Client::sendNewDirection(std::vector<byte> &byte)
{
    (void)byte;
    // async send here;
}

void Client::setUpEcs()
{
    _registry.register_component<component::ckeyboard_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::mouseState_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::csprite_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::cposition_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::crect_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
	_registry.register_component<component::velocity_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});

	_registry.add_system(_drawSystem, _registry.get_components<component::csprite_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::crect_t>());
    _registry.add_system(_rectSystem, _registry.get_components<component::csprite_t>(), _registry.get_components<component::crect_t>());
    _registry.add_system(_controlSystem, _registry.get_components<component::cposition_t>(), _registry.get_components<component::velocity_t>(), _registry.get_components<component::ckeyboard_t>());
}

void Client::setUpComponents()
{
    Entity e = _registry.spawn_entity();
    component::cposition_t position = {10, 50};
    component::crect_t rect = {0, 0, 33.3125, 36, 1, 8};
    component::csprite_t sprite = {.sprite = _graphicLib->createSprite("Assets/sprites/r-typesheet5.gif", 1, (Rectangle){.x = rect.x, .y = rect.y, .width = rect.width, .height = rect.height})};
	component::velocity_t vel = {.velocity = 10};
    component::ckeyboard_t keyboard = {.keyboard = 0};

    _registry.add_component<component::csprite_t>(_registry.entity_from_index(e), std::move(sprite));
    _registry.add_component<component::cposition_t>(_registry.entity_from_index(e), std::move(position));
    _registry.add_component<component::crect_t>(_registry.entity_from_index(e), std::move(rect));
	_registry.add_component<component::velocity_t>(_registry.entity_from_index(e), std::move(vel));
	_registry.add_component<component::ckeyboard_t>(_registry.entity_from_index(e), std::move(keyboard));
}
