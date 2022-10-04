/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#include <iostream>

#include "Component/CurrScene.hpp"
#include "LoadScene.hpp"
#include "Client.hpp"

Client::Client(std::string const &ip, std::string const &port) :
    _working(true)
{
    _network = std::make_unique<Network>(ip, port);
    _registry = std::make_unique<Registry>(2);
    setUpEcs();
    machineRun();
}

// Client::~Client()
// {
// }

void Client::machineRun(void)
{
    while (_working) {
        _registry.get()->run_systems();
    }
}

void Client::setUpEcs(void)
{
    _registry->register_component<component::currScene_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry->register_component<component::keyboard_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry->register_component<component::mouseState_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});

    _registry->add_component<component::currScene_t>(_registry->entity_from_index(FORBIDDEN_IDS::GRAPHIC), {SCENE::MENU, false});
    _registry->add_system<component::currScene_t, component::keyboard_t, component::mouseState_t>(_loadScene);
}
