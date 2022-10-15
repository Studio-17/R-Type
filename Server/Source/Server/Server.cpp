/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Server
*/

#include "Server.hpp"

Server::Server(short const port) : _com(std::make_shared<UdpCommunication>(_context, port)),
    _thread(&Server::threadLoop, this), _isRunning(true)
{
    ReceivePackets();

    _context.run();
}

Server::~Server()
{
    _isRunning = false;
    _thread.join();

    _context.stop();
}

void Server::ReceivePackets()
{
    _buffer_to_get.clear();
    _buffer_to_get.resize(1500);
    _com->async_receive(_buffer_to_get, std::bind(&Server::HandleReceive, this, std::placeholders::_1, std::placeholders::_2));
}

void Server::HandleReceive(asio::error_code const &e, std::size_t nbBytes)
{
    std::cout << "Reading packet ..." << std::endl;

    std::pair<asio::ip::address, unsigned short> endpointData = _com->getEnpointInfo();
    _endpoints.try_emplace(endpointData.first, std::unordered_map<unsigned short, bool>());
    _endpoints.at(endpointData.first).try_emplace(endpointData.second, true);

    _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.push(_buffer_to_get);
    HandleSendPacket();
}

void Server::HandleSendPacket() {

    std::cout << "Sending packet ..." << std::endl;

    if (!_registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.empty()) {
        std::vector<byte> &tmp = _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.front();
        _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.pop();

        _com->async_send(tmp, std::bind(&Server::CompleteExchange, this, std::placeholders::_1, std::placeholders::_2));
    }
    ReceivePackets();
}

/*
//    for (auto const &[address, portList] : _endpoints) {
//        for (auto const &port : portList) {
//            _com->async_send(buffer_to_send, std::bind(&Server::CompleteExchange, this, std::placeholders::_1, std::placeholders::_2), address, port.first);
//            std::cout << "send " << address<<" "<< port.first << std::endl;
//        }
//    }
*/

void Server::CompleteExchange(std::error_code const &e, std::size_t nbBytes)
{
    std::cout << "Exchange completed !" << std::endl;

    ReceivePackets();
}

void Server::threadLoop()
{
    setUpEcs();
    setUpComponents();

    while (_isRunning)
        _registry.run_systems();
}

void Server::setUpEcs()
{
    _registry.register_component<component::cdamage_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::cdirection_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::chealth_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::chitbox_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::cposition_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::cvelocity_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    _registry.register_component<component::cnetwork_queue_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});

   _registry.add_system(_moveSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cdirection_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::cvelocity_t>());
   _registry.add_system(_receiveSystem, _registry.get_components<component::cnetwork_queue_t>());
}

void Server::setUpComponents()
{
    Entity e = _registry.spawn_entity();
    std::cout << e << std::endl;

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

    component::cnetwork_queue_t network = {};
    _registry.add_component<component::cnetwork_queue_t>(_registry.entity_from_index(e), std::move(network));
}
