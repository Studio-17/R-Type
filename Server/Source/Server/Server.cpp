/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Server
*/

#include "Server.hpp"

#include "CType.hpp"
#include "CTimer.hpp"
#include "CSceneId.hpp"

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

void Server::HandleReceive([[ maybe_unused ]] asio::error_code const &e, [[ maybe_unused ]] std::size_t nbBytes)
{
    std::pair<asio::ip::address, unsigned short> endpointData = _com->getEnpointInfo();
    _endpoints.try_emplace(endpointData.first, std::unordered_map<unsigned short, bool>());
    _endpoints.at(endpointData.first).try_emplace(endpointData.second, true);

    _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.push(_buffer_to_get);
    ReceivePackets();
}

void Server::HandleSendPacket() {
    while (!_registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK]->toSendNetworkQueue.empty()) {
        std::vector<byte> &tmp = _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK]->toSendNetworkQueue.front();
        for (auto const &[address, portList] : _endpoints) {
            for (auto const &[port, isPresent] : portList) {
                _com->send(tmp, address, port);
            }
        }
        _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK]->toSendNetworkQueue.pop();
    }
}

void Server::threadLoop()
{
    setUpEcs();
    setUpComponents();
    while (_isRunning) {
        _registry.run_systems();
        HandleSendPacket();
    }
}

void Server::setUpEcs()
{
    _registry.register_component<component::cdamage_t>();
    _registry.register_component<component::cdirection_t>();
    _registry.register_component<component::chealth_t>();
    _registry.register_component<component::chitbox_t>();
    _registry.register_component<component::cposition_t>();
    _registry.register_component<component::cvelocity_t>();
    _registry.register_component<component::cnetwork_queue_t>();
    _registry.register_component<component::ctype_t>();
    _registry.register_component<component::crect_t>();
    _registry.register_component<component::ctimer_t>();
    _registry.register_component<component::csceneid_t>();

   _registry.add_system(_moveSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cdirection_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::cvelocity_t>(), _registry.get_components<component::ctimer_t>());
   _registry.add_system(_directionSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cdirection_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::cvelocity_t>());
   _registry.add_system(_receiveSystem, _registry.get_components<component::cnetwork_queue_t>());
   _registry.add_system(_shootSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cposition_t>());
   _registry.add_system(_spawnEnemySystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::ctype_t>(), _registry.get_components<component::ctimer_t>());
   _registry.add_system(_newPlayerSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::ctype_t>());
   _registry.add_system(_hitboxSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::ctype_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::crect_t>());
}

void Server::setUpComponents()
{
    Entity networkEntity = _registry.spawn_entity_with(
        component::cnetwork_queue_t{},
        component::ctimer_t{ .deltaTime = std::chrono::steady_clock::now(), .spawnEnemyDeltaTime = std::chrono::steady_clock::now()}
    );
}
