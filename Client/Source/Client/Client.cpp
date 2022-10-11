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

Client::Client(std::string const &ip, std::string const &port) :
    _registry(2), _working(true)
{
    _socket = std::make_shared<asio::ip::udp::socket>(io_service_, asio::ip::udp::endpoint(asio::ip::udp::v4(), 8081));

	asio::ip::udp::resolver resolver(io_service_);
	asio::ip::udp::resolver::query query(asio::ip::udp::v4(), ip, port);
	asio::ip::udp::resolver::iterator iter = resolver.resolve(query);
	_destination = *iter;

    _network = std::make_unique<Network>(ip, port);

   _graphicLib = std::make_shared<rtype::GraphicalLib>();
   _graphicLib->initWindow(800, 600, "R-Type", 60);

    setUpEcs();
    setUpComponents();
}

Client::~Client()
{
	_socket->close();
}

void Client::machineRun(void)
{
	Header header {.id = 8, .data = 4, .pr = {.pt = 3, .second = 9}};
	auto buffer_to_send = serializable_trait<Header>::serialize(header);
	_socket->send_to(asio::buffer(buffer_to_send.data(), buffer_to_send.size()), _destination);
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
}

void Client::setUpComponents()
{
    // _registry.add_component<component::mouseState_t>(_registry.entity_from_index(FORBIDDEN_IDS::GRAPHIC), {0, 0, false});
    // _registry.add_component<component::ckeyboard_t>(_registry.entity_from_index(FORBIDDEN_IDS::GRAPHIC), {false, false, false, false, false, false});
}
