/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Server
*/

#include <functional>

#include "Server.hpp"

Server::Server(short const port) : _com(std::make_shared<UdpCommunication>(_context, port))
    //_thread(&Server::threadLoop, this), _stop(false)
{
    _callbacks = {
        {1, [this] { callback_packet1(); }},
        {2, [this] { callback_packet2(); }},
        {3, [this] { callback_packet3(); }},
        {4, [this] { callback_packet4(); }},
        {5, [this] { callback_packet5(); }},
        {6, [this] { callback_packet6(); }},
        {7, [this] { callback_packet7(); }},
        {8, [this] { callback_packet8(); }},
        {9, [this] { callback_packet9(); }},
    };

    ReceivePackets();

    setUpEcs();
    setUpComponents();

    _context.run();
}

Server::~Server()
{
    // _stop = true;
    // _thread.join();

    _context.stop();
}

void Server::ReceivePackets()
{
    _com->async_receive(buffer_to_get, std::bind(&Server::HandleReceive, this, std::placeholders::_1, std::placeholders::_2));
}

void Server::HandleReceive(asio::error_code const &e, std::size_t nbBytes)
{
    std::cout << "read" << std::endl;

    std::pair<asio::ip::address, unsigned short> endpointData = _com->getEnpointInfo();
    _endpoints.try_emplace(endpointData.first, std::unordered_map<unsigned short, bool>());
    _endpoints.at(endpointData.first).try_emplace(endpointData.second, true);

    Header tt = serializable_trait<Header>::unserialize(buffer_to_get);

    std::cout << tt.id << std::endl;

    _callbacks.at(tt.id)();
}

void Server::SendPackets(asio::error_code const &e, std::size_t nbBytes)
{
//    std::cout << "header: "<< tt.id << std::endl;
//    ServerResponse ok = {
//        .code = 200,
//
//        .status = true,
//    };
//
    // std::vector<byte> buffer_to_send = serialize_header::serializeHeader<ServerResponse>(1, ok);

//
//    for (auto const &[address, portList] : _endpoints) {
//        for (auto const &port : portList) {
//            _com->async_send(buffer_to_send, std::bind(&Server::CompleteExchange, this, std::placeholders::_1, std::placeholders::_2), address, port.first);
//            std::cout << "send " << address<<" "<< port.first << std::endl;
//        }
//    }
}

void Server::CompleteExchange(std::error_code const &e, std::size_t nbBytes)
{
    ReceivePackets();
}

void Server::threadLoop()
{
    // while (!_stop) {
    //
    // }
}

void Server::setUpEcs()
{
    _registry.register_component<component::cdamage_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::cdirection_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::chealth_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::chitbox_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::cposition_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::cvelocity_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});

//    _registry.add_system(_mySystem, _registry.get_components<component::component_t>(), _registry.get_components<component::component1_t>(), _registry.get_components<component::component2_t>());
}

void Server::setUpComponents()
{
    Entity e = _registry.spawn_entity();

    component::cdamage_t damage = { 0 };
    _registry.add_component<component::cdamage_t>(_registry.entity_from_index(e), std::move(damage));

    component::cdirection_t direction = { 0, 0 };
    _registry.add_component<component::cdirection_t>(_registry.entity_from_index(e), std::move(direction));

    component::chealth_t health = {10 };
    _registry.add_component<component::chealth_t>(_registry.entity_from_index(e), std::move(health));

    component::chitbox_t hitbox = {10, 10};
    _registry.add_component<component::chitbox_t>(_registry.entity_from_index(e), std::move(hitbox));

    component::cposition_t position = {10, 10};
    _registry.add_component<component::cposition_t>(_registry.entity_from_index(e), std::move(position));

    component::cvelocity_t velocity = {10 };
    _registry.add_component<component::cvelocity_t>(_registry.entity_from_index(e), std::move(velocity));
}
