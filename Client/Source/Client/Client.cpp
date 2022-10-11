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
#include "LoadScene.hpp"
#include "Serialization.hpp"
#include "Structure.hpp"

Client::Client(std::string const &ip, std::string const &port, int hostPort) :
    _com(std::make_unique<UdpCommunication>(_context, hostPort, port, ip)),
    _registry(2), _working(true)
{
    _context.run();
    setUpEcs();
    // setUpComponents();
    machineRun();
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
    while (!_loadScene.getGraphicalLib()->windowShouldClose()) {
        _com->receive(_bufferToGet);//, std::bind(&Client::handleReceive, this));
        handleReceive();
        _registry.run_systems();
    }
}

void Client::handleReceive()
{
    std::cout <<"going to receive" << std::endl;
    ServerResponse response = serializable_trait<ServerResponse>::unserialize(_bufferToGet);
    std::cout << "response: " << response.code << std::endl;
}

void Client::setUpEcs()
{
    _registry.register_component<component::currScene_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::ckeyboard_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::mouseState_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::csprite_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::cposition_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::csprite_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});

    _registry.add_component<component::currScene_t>(_registry.entity_from_index(FORBIDDEN_IDS::GRAPHIC), {SCENE::MENU, false});

    _registry.add_system(_loadScene, _registry.get_components<component::currScene_t>(), _registry.get_components<component::ckeyboard_t>(), _registry.get_components<component::mouseState_t>());
}

void Client::setUpComponents()
{
    _registry.add_component<component::currScene_t>(_registry.entity_from_index(FORBIDDEN_IDS::GRAPHIC), {SCENE::MENU, false});
    _registry.add_component<component::mouseState_t>(_registry.entity_from_index(FORBIDDEN_IDS::GRAPHIC), {0, 0, false});
    _registry.add_component<component::ckeyboard_t>(_registry.entity_from_index(FORBIDDEN_IDS::GRAPHIC), {false, false, false, false, false, false});
}
