/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#include <iostream>
#include <functional>

#include "Client.hpp"
#include "CurrScene.hpp"
#include "Mouse.hpp"
#include "CKeyboard.hpp"
#include "CPosition.hpp"
#include "CRect.hpp"
#include "CVelocity.hpp"
#include "CServerId.hpp"
#include "CNetworkQueue.hpp"
#include "Serialization.hpp"
#include "Structure.hpp"
#include "CType.hpp"
#include "Move.hpp"
#include "NewConnection.hpp"
#include "CIdOfShip.hpp"
#include "CTimer.hpp"
#include "CAsset.hpp"
#include "CAssetId.hpp"
#include "Asset.hpp"
#include "Disconnection.hpp"

Client::Client(std::string const &ip, std::string const &port, int hostPort) :
    _com(std::make_unique<UdpCommunication>(_context, hostPort, port, ip)),
    _connected(true)
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
    _graphicLib->initWindow(800, 600, "R-Type", 60);

    setUpEcs();
    setUpSystems();
    setUpComponents();
    _thread = std::thread(&Client::threadLoop, this);
}

Client::~Client()
{
    _context.stop();
    _connected = false;
    _thread.join();
}

void Client::tryToConnect()
{
    packet_new_connection packet = {.id = 0};
    std::vector<byte> bytes = serialize_header::serializeHeader<packet_new_connection>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::NEW_CONNECTION, packet);
    _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(bytes);
}

void Client::machineRun()
{
    tryToConnect();
    while (!_graphicLib->windowShouldClose()) {
        _graphicLib->startDrawingWindow();
            _graphicLib->clearScreen();
            _registry.run_systems();
        _graphicLib->endDrawingWindow();
        SendPacket();
    }
    _graphicLib->closeWindow();
    _connected = false;
    packet_disconnection packet;
    packet.disconnection = _registry.get_components<component::cid_of_ship_t>()[FORBIDDEN_IDS::NETWORK].value().id;
    auto tmp = serialize_header::serializeHeader<packet_disconnection>(NETWORK_CLIENT_TO_SERVER::PACKET_TYPE::DISCONNECTION, packet);
    _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.push(tmp);
    SendPacket();
}

void Client::SendPacket() {
    while (!_registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.empty()) {
        std::vector<byte> tmp = _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.front();
        _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().toSendNetworkQueue.pop();
        _com->send(tmp);
    }
}


void Client::handleReceive() {
    _com->async_receive(_bufferToGet, std::bind(&Client::pushNewPacketsToQueue, this, std::placeholders::_1, std::placeholders::_2));
}

void Client::pushNewPacketsToQueue([[ maybe_unused ]] asio::error_code const &e, [[maybe_unused]] size_t nbBytes)
{
    _registry.get_components<component::cnetwork_queue_t>()[FORBIDDEN_IDS::NETWORK].value().receivedNetworkQueue.push(_bufferToGet);
    handleReceive();
}

void Client::setUpEcs()
{
    _registry.register_component<component::ckeyboard_t>();
    _registry.register_component<component::mouseState_t>();
    _registry.register_component<component::cposition_t>();
    _registry.register_component<component::crect_t>();
	_registry.register_component<component::cvelocity_t>();
	_registry.register_component<component::cserverid_t>();
	_registry.register_component<component::cnetwork_queue_t>();
	_registry.register_component<component::cdirection_t>();
	_registry.register_component<component::cid_of_ship_t>();
    _registry.register_component<component::ctype_t>();
    _registry.register_component<component::ctimer_t>();
    _registry.register_component<component::casset_t>();
    _registry.register_component<component::cassetid_t>();
}

void Client::setUpSystems()
{
	_registry.add_system(_networkSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cid_of_ship_t>());
    _registry.add_system(_killSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cserverid_t>());
    _registry.add_system(_rectSystem, _registry.get_components<component::crect_t>(), _registry.get_components<component::ctimer_t>(), _registry.get_components<component::ctype_t>(), _registry.get_components<component::casset_t>(), _registry.get_components<component::cassetid_t>());
    _registry.add_system(_controlSystem, _registry.get_components<component::ckeyboard_t>(), _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cid_of_ship_t>());
    _registry.add_system(_newEntitySystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cserverid_t>(), _registry.get_components<component::casset_t>());
    _registry.add_system(_positionSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::cserverid_t>());
    _registry.add_system(_moveSystem, _registry.get_components<component::cdirection_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::cvelocity_t>(), _registry.get_components<component::ctimer_t>());
	_registry.add_system(_drawSystem, _registry.get_components<component::cposition_t>(), _registry.get_components<component::crect_t>(), _registry.get_components<component::casset_t>(), _registry.get_components<component::cassetid_t>());
}

void Client::setUpComponents()
{
    Entity network = _registry.spawn_entity();
    Entity parallax = _registry.spawn_entity();

    // Network entity
    component::cnetwork_queue_t nnetwork = {};
    _registry.add_component<component::cnetwork_queue_t>(network, std::move(nnetwork));

    component::ctype_t ntype = {.type = NET};
    _registry.add_component<component::ctype_t>(network, std::move(ntype));

    component::cid_of_ship_t idOfShip = {.id = 0};
    _registry.add_component<component::cid_of_ship_t>(network, std::move(idOfShip));

    component::ckeyboard_t keyboard = {.keyboard = 0};
	_registry.add_component<component::ckeyboard_t>(network, std::move(keyboard));

    component::ctimer_t timer = {.deltaTime = std::chrono::steady_clock::now(), .animTimer = std::chrono::steady_clock::now()};
	_registry.add_component<component::ctimer_t>(network, std::move(timer));

    component::casset_t assets;
    assets.assets = AssetManager("Assets/asset.json");
	_registry.add_component<component::casset_t>(network, std::move(assets));

    // Parallax Entity
    component::crect_t prect = assets.assets.at(ENTITY_TYPE::WALL).getRectangle();
    _registry.add_component<component::crect_t>(parallax, std::move(prect));

    component::cposition_t pposition = {0, 0};
    _registry.add_component<component::cposition_t>(parallax, std::move(pposition));

    component::cdirection_t pdirection = {.x = 0, .y = 0};
    _registry.add_component<component::cdirection_t>(parallax, std::move(pdirection));

    component::ctype_t ptype = {.type = UI};
    _registry.add_component<component::ctype_t>(parallax, std::move(ptype));
    component::cassetid_t assetId = {.assets = ENTITY_TYPE::WALL};

    _registry.add_component<component::cassetid_t>(parallax, std::move(assetId));
}

void Client::threadLoop()
{
    handleReceive();
    _context.run();
}