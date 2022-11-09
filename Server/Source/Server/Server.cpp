/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Server
*/

#include <unordered_map>

#include "Server.hpp"

#include "Serialization.hpp"
#include "NewConnection.hpp"
#include "Constant.hpp"

/* Component */
#include "Component/CDamage.hpp"
#include "Component/CDirection.hpp"
#include "Component/CHealth.hpp"
#include "Component/CHitBox.hpp"
#include "Component/CNetworkQueue.hpp"
#include "Component/CPosition.hpp"
#include "Component/CLobbiesToEntities.hpp"
// #include "Component/CVelocity.hpp"
#include "Component/CLobbyId.hpp"
#include "Component/CTimer.hpp"
#include "Component/CType.hpp"
#include "Component/CSceneId.hpp"
#include "Component/CLobbiesStatus.hpp"
#include "Component/CScore.hpp"
#include "Component/COwnerId.hpp"

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
    _endpoints.try_emplace(endpointData.first, std::unordered_map<unsigned short, int>());

    auto const &[it, is_new] = _endpoints.at(endpointData.first).try_emplace(endpointData.second, -1);
    if (is_new) {
        packet_new_connection new_connect;
        new_connect.id = client_id;
        _endpoints.at(endpointData.first).at(endpointData.second) = client_id;
        client_id++;
        std::vector<byte> new_buffer = serialize_header::serializeHeader<packet_new_connection>(NETWORK_CLIENT_TO_SERVER::NEW_CLIENT, new_connect);
        _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.push(std::pair<int, std::vector<byte>>(client_id, new_buffer));
    } else
        _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.push(std::pair<int, std::vector<byte>> (_endpoints.at(endpointData.first).at(endpointData.second), _buffer_to_get));
    ReceivePackets();
}

void Server::HandleSendPacket() {
    while (!_registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK]->toSendNetworkQueue.empty()) {
        std::pair<int, std::vector<byte>> &tmp = _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK]->toSendNetworkQueue.front();
        for (auto const &[address, portList] : _endpoints) {
            for (auto const &[port, netId]: portList) {
                if (tmp.first == _registry.get_components<component::clobby_id_t>()[_registry.get_components<component::cnet_id_to_client_id_t>()[FORBIDDEN_IDS::NETWORK].value().netIdToClientId.at(netId)].value().id) {
                    _com->send(tmp.second, address, port);
                }
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
    // Rework
    _registry.register_component<component::cnetwork_id_t>();
    _registry.register_component<component::cnet_id_to_client_id_t>();
    _registry.register_component<component::clobby_id_t>();
    _registry.register_component<component::clobbies_to_entities_t>();
    _registry.register_component<component::csceneid_t>();
    _registry.register_component<component::clobbies_status_t>();
    _registry.register_component<component::cscore_t>();
    _registry.register_component<component::cowner_id_t>();

    _registry.add_system<component::cnetwork_queue_t, component::cnet_id_to_client_id_t, component::clobbies_to_entities_t>(_newClientSystem);
    _registry.add_system<component::cnetwork_queue_t, component::cdirection_t, component::cposition_t, component::cvelocity_t, component::ctimer_t, component::clobby_id_t, component::clobbies_status_t>(_moveSystem);
    _registry.add_system<component::cnetwork_queue_t, component::cdirection_t, component::cposition_t, component::cvelocity_t, component::clobby_id_t, component::cnet_id_to_client_id_t>(_directionSystem);
    _registry.add_system<component::cnetwork_queue_t>(_receiveSystem);
    _registry.add_system<component::cnetwork_queue_t, component::cposition_t, component::clobby_id_t, component::cnet_id_to_client_id_t>(_shootSystem);
    _registry.add_system<component::cnetwork_queue_t, component::cposition_t, component::ctype_t, component::ctimer_t, component::clobbies_status_t>(_spawnEnemySystem);
    _registry.add_system<component::cnetwork_queue_t, component::ctype_t, component::cposition_t, component::crect_t, component::chealth_t, component::clobby_id_t, component::cscore_t, component::ctype_t, component::cowner_id_t>(_hitboxSystem);
    _registry.add_system<component::cnetwork_queue_t, component::clobby_id_t, component::clobbies_to_entities_t, component::cnet_id_to_client_id_t>(_disconnectionSystem);
    _registry.add_system<component::cnetwork_queue_t, component::clobby_id_t, component::clobbies_to_entities_t, component::cnet_id_to_client_id_t>(_joinLobbySystem);
    _registry.add_system<component::cnetwork_queue_t, component::clobby_id_t, component::cnet_id_to_client_id_t, component::clobbies_to_entities_t, component::cposition_t, component::ctype_t, component::clobbies_status_t>(_startGameSystem);
    _registry.add_system<component::cnetwork_queue_t, component::ctype_t, component::clobby_id_t, component::clobbies_status_t>(_endGameSystem);

}

void Server::setUpComponents()
{
    Entity networkEntity = _registry.spawn_entity_with(
        component::cnetwork_queue_t{},
        component::ctimer_t{ .deltaTime = std::chrono::steady_clock::now(), .spawnEnemyDeltaTime = std::chrono::steady_clock::now()},
        component::cnet_id_to_client_id_t{},
        component::clobbies_to_entities_t{},
        component::clobbies_status_t { .lobbiesStatus = {{1, {false, 1}}, {2, {false, 1}}, {3, {false, 1}}} }
    );

    Entity lobbiesEntity = _registry.spawn_entity_with(
        component::clobbies_to_entities_t{},
        component::clobbies_status_t { .lobbiesStatus = {{1, {false, 1}}, {2, {false, 1}}, {3, {false, 1}}} }
    );
}
