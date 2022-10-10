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
#include "Component/Keyboard.hpp"
#include "Component/CPosition.hpp"
#include "LoadScene.hpp"

Client::Client(std::string const &ip, std::string const &port) :
    _registry(2), _working(true)
{
    _network = std::make_unique<Network>(ip, port);
    setUpEcs();
    // setUpComponents();
    machineRun();
}

void Client::machineRun()
{
    while (!_loadScene.getGraphicalLib()->windowShouldClose()) {
        _registry.run_systems();
    }
}

void Client::setUpEcs()
{
    _registry.register_component<component::currScene_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::keyboard_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::mouseState_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::csprite_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::cposition_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::csprite_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});

    _registry.add_component<component::currScene_t>(_registry.entity_from_index(FORBIDDEN_IDS::GRAPHIC), {SCENE::MENU, false});

    _registry.add_system(_loadScene, _registry.get_components<component::currScene_t>(), _registry.get_components<component::keyboard_t>(), _registry.get_components<component::mouseState_t>());
}

void Client::setUpComponents()
{
    _registry.add_component<component::currScene_t>(_registry.entity_from_index(FORBIDDEN_IDS::GRAPHIC), {SCENE::MENU, false});
    _registry.add_component<component::mouseState_t>(_registry.entity_from_index(FORBIDDEN_IDS::GRAPHIC), {0, 0, false});
    _registry.add_component<component::keyboard_t>(_registry.entity_from_index(FORBIDDEN_IDS::GRAPHIC), {false, false, false, false, false, false});
}
