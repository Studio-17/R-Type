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
    setUpComponents();
}

Client::~Client()
{
    _context.stop();
}

void Client::machineRun(void)
{
	Header header {.id = 8, .data = 4, .pr = {.pt = 3, .second = 9}};
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
    std::cout <<"going to receive" << std::endl;
    ServerResponse response = serializable_trait<ServerResponse>::unserialize(_bufferToGet);
    std::cout << "response: " << response.code << std::endl;
}

void Client::setUpEcs()
{
    _registry.register_component<component::ckeyboard_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::mouseState_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::csprite_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::cposition_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::crect_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});

    _registry.add_system(_drawSystem, _registry.get_components<component::csprite_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::crect_t>());
    _registry.add_system(_rectSystem, _registry.get_components<component::csprite_t>(), _registry.get_components<component::crect_t>());
}

void Client::setUpComponents()
{
    Entity e = _registry.spawn_entity();
    component::cposition_t position = {10, 50};
    component::crect_t rect = {0, 0, 33.3125, 36, 1, 8};
    component::csprite_t sprite = {.sprite = _graphicLib->createSprite("Assets/sprites/r-typesheet5.gif", 1, (Rectangle){.x = rect.x, .y = rect.y, .width = rect.width, .height = rect.height})};
    _registry.add_component<component::csprite_t>(_registry.entity_from_index(e), std::move(sprite));
    _registry.add_component<component::cposition_t>(_registry.entity_from_index(e), std::move(position));
    _registry.add_component<component::crect_t>(_registry.entity_from_index(e), std::move(rect));
}
