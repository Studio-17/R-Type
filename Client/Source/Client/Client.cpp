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

Client::Client(std::string const &ip, std::string const &port, int hostPort) :
    _com(std::make_unique<UdpCommunication>(_context, hostPort, port, ip)),
    _registry(2), _working(true)
{
    _context.run();

    _graphicLib = std::make_shared<rtype::GraphicalLib>();
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
        _com->receive(_bufferToGet);//, std::bind(&Client::handleReceive, this));
        handleReceive();
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

void Client::setUpEcs()
{
    _registry.register_component<component::ckeyboard_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::mouseState_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::csprite_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::cposition_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::csprite_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
}

void Client::setUpComponents()
{
    // _registry.add_component<component::mouseState_t>(_registry.entity_from_index(FORBIDDEN_IDS::GRAPHIC), {0, 0, false});
    // _registry.add_component<component::ckeyboard_t>(_registry.entity_from_index(FORBIDDEN_IDS::GRAPHIC), {false, false, false, false, false, false});
}
