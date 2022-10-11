/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#include <iostream>

#include "Client.hpp"
#include "Component/CurrScene.hpp"
#include "Component/Mouse.hpp"
#include "Component/CSprite.hpp"
#include "Component/CKeyboard.hpp"
#include "Component/CPosition.hpp"
#include "Serialization.hpp"
#include "Structure.hpp"

Client::Client(std::string const &ip, std::string const &port) :
    _com(std::make_unique<UdpCommunication>(_context, 8081, port, ip)),
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
}

void Client::machineRun(void)
{
	Header header {.id = 8, .data = 4, .pr = {.pt = 3, .second = 9}};
	auto buffer_to_send = serializable_trait<Header>::serialize(header);
	_com->send(buffer_to_send);
    std::cout << "sended" << std::endl;
	 // receive();

    while (!_graphicLib->windowShouldClose()) {
        _graphicLib->startDrawingWindow();
            _graphicLib->clearScreen();
            _registry.run_systems();
        _graphicLib->endDrawingWindow();
    }
    _graphicLib->closeWindow();
}

void Client::setUpEcs()
{
    _registry.register_component<component::ckeyboard_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::mouseState_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::csprite_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::cposition_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::csprite_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});

    _registry.add_system(_drawSystem, _registry.get_components<component::csprite_t>(), _registry.get_components<component::cposition_t>());
}

void Client::setUpComponents()
{
    Entity e = _registry.spawn_entity();
    component::cposition_t position = {10, 50};
    component::csprite_t sprite = {.sprite = _graphicLib->createSprite("Assets/sprites/r-typesheet5.gif", 1)};
    _registry.add_component<component::csprite_t>(_registry.entity_from_index(e), std::move(sprite));
    _registry.add_component<component::cposition_t>(_registry.entity_from_index(e), std::move(position));
}
