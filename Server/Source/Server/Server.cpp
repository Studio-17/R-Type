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
    _com->async_receive(_buffer_to_get, std::bind(&Server::HandleReceive, this, std::placeholders::_1, std::placeholders::_2));
}

void Server::HandleReceive(asio::error_code const &e, std::size_t nbBytes)
{
    std::pair<asio::ip::address, unsigned short> endpointData = _com->getEnpointInfo();
    _endpoints.try_emplace(endpointData.first, std::unordered_map<unsigned short, bool>());
    _endpoints.at(endpointData.first).try_emplace(endpointData.second, true);

    _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.push(_buffer_to_get);
    HandleSendPacket();
}

void Server::HandleSendPacket() {
    if (!_registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK]->toSendNetworkQueue.empty()) {
        std::vector<byte> &tmp = _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK]->toSendNetworkQueue.front();
        for (auto const &[address, portList] : _endpoints) {
            for (auto const &[port, isPresent] : portList) {
                _com->send(tmp);
            }
        }
        _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK]->toSendNetworkQueue.pop();
        std::cout << "[SERVER] queue size:  " << _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK]->toSendNetworkQueue.size() << std::endl;
    }
    ReceivePackets();
}

void Server::threadLoop()
{
    setUpEcs();
    setUpComponents();
    while (_isRunning) {
        _registry.run_systems();
    }
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
   _registry.add_system(_directionSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cdirection_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::cvelocity_t>());
   _registry.add_system(_receiveSystem, _registry.get_components<component::cnetwork_queue_t>());
   _registry.add_system(_shootSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cposition_t>());
   _registry.add_system(_newPlayerSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cposition_t>());
}

void Server::setUpComponents()
{
    Entity networkEntity = _registry.spawn_entity();
    Entity spaceShip = _registry.spawn_entity();
    std::cout << networkEntity << std::endl;

    component::cdamage_t damage = { 0 };
    _registry.add_component<component::cdamage_t>(_registry.entity_from_index(networkEntity), std::move(damage));

    component::cdirection_t direction = { 0, 0 };
    _registry.add_component<component::cdirection_t>(_registry.entity_from_index(networkEntity), std::move(direction));

    component::cdirection_t dirrection = { 0, 0 };
    _registry.add_component<component::cdirection_t>(_registry.entity_from_index(spaceShip), std::move(dirrection));

    component::chealth_t health = {10 };
    _registry.add_component<component::chealth_t>(_registry.entity_from_index(networkEntity), std::move(health));

    component::chitbox_t hitbox = {10, 10};
    _registry.add_component<component::chitbox_t>(_registry.entity_from_index(networkEntity), std::move(hitbox));

    component::cposition_t position = {10, 10};
    _registry.add_component<component::cposition_t>(_registry.entity_from_index(networkEntity), std::move(position));

    component::cposition_t possition = {10, 10};
    _registry.add_component<component::cposition_t>(_registry.entity_from_index(spaceShip), std::move(possition));

    component::cvelocity_t velocity = {10 };
    _registry.add_component<component::cvelocity_t>(_registry.entity_from_index(networkEntity), std::move(velocity));

    component::cvelocity_t vellocity = {10 };
    _registry.add_component<component::cvelocity_t>(_registry.entity_from_index(spaceShip), std::move(vellocity));

    component::cnetwork_queue_t network = {};
    _registry.add_component<component::cnetwork_queue_t>(_registry.entity_from_index(networkEntity), std::move(network));
}

void Server::machineRun()
{
    while (_isRunning)
        _registry.run_systems();
}