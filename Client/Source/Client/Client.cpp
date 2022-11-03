/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Client
*/

#include <iostream>
#include <fstream>
#include <array>

#include "Client.hpp"
#include "CSceneId.hpp"
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
#include "CCallback.hpp"
#include "Asset.hpp"
#include "Disconnection.hpp"
#include "Constant.hpp"

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
    _registry.register_component<component::csceneid_t>();
    _registry.register_component<component::ccallback_t>();
}

void Client::setUpSystems()
{
	_registry.add_system(_networkSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cid_of_ship_t>());
    _registry.add_system(_killSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cserverid_t>());
    _registry.add_system(_rectSystem, _registry.get_components<component::crect_t>(), _registry.get_components<component::ctimer_t>(), _registry.get_components<component::ctype_t>(), _registry.get_components<component::casset_t>(), _registry.get_components<component::cassetid_t>());
    _registry.add_system(_controlSystem, _registry.get_components<component::ckeyboard_t>(), _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cid_of_ship_t>(), _registry.get_components<component::csceneid_t>());
	_registry.add_system(_mouseSystem, _registry.get_components<component::cposition_t>(), _registry.get_components<component::crect_t>(), _registry.get_components<component::csceneid_t>(), _registry.get_components<component::ctype_t>(), _registry.get_components<component::ccallback_t>());
    _registry.add_system(_newEntitySystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cserverid_t>(), _registry.get_components<component::casset_t>());
    _registry.add_system(_positionSystem, _registry.get_components<component::cnetwork_queue_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::cserverid_t>());
    _registry.add_system(_moveSystem, _registry.get_components<component::cdirection_t>(), _registry.get_components<component::cposition_t>(), _registry.get_components<component::cvelocity_t>(), _registry.get_components<component::ctimer_t>());
	_registry.add_system(_drawSystem, _registry.get_components<component::cposition_t>(), _registry.get_components<component::crect_t>(), _registry.get_components<component::casset_t>(), _registry.get_components<component::cassetid_t>(), _registry.get_components<component::csceneid_t>());
}

void Client::setUpComponents()
{
    component::casset_t assetMan;
    assetMan.assets = AssetManager("Assets/asset.json");

    Entity network = _registry.spawn_entity_with(
        component::cnetwork_queue_t{},
        component::ctype_t{ .type = NET },
        component::cid_of_ship_t{ .id = 0 },
        component::ckeyboard_t{ .keyboard = 0 },
        component::ctimer_t{ .deltaTime = std::chrono::steady_clock::now(), .animTimer = std::chrono::steady_clock::now() },
        component::casset_t{ .assets = assetMan.assets },
        component::csceneid_t{ .sceneId = SCENE::MAIN_MENU }
    );

    Entity parallax = _registry.spawn_entity_with(
        component::crect_t{ assetMan.assets.at(0).getRectangle() },
        component::cposition_t{ .x = 0, .y = 0 },
        component::cdirection_t{ .x = -1, .y = 0 },
        component::ctype_t{ .type = UI },
        component::cvelocity_t{ .velocity = 1 },
        component::cassetid_t{ .assets = 0 },
        component::csceneid_t{ .sceneId = SCENE::ALL }
    );

    loadButton("Assets/buttons.json", _registry.get_components<component::casset_t>());
}

static nlohmann::json getJsonData(std::string const &filepath)
{
    nlohmann::json jsonData;
    std::ifstream confStream(filepath);

    if (!confStream.is_open())
        throw ("file " + filepath + " failed to open");
    confStream >> jsonData;
    confStream.close();
    return jsonData;
}

void Client::startBtn()
{
    _registry.get_components<component::csceneid_t>()[FORBIDDEN_IDS::NETWORK].value().sceneId = SCENE::GAME;
}

void Client::loadButton(std::string const &filepath, Sparse_array<component::casset_t> &assets)
{
    nlohmann::json jsonData;

    try {
        jsonData = getJsonData(filepath);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    _callbackMap = {
        std::bind(&Client::startBtn, this),
    };

    for (auto &oneData: jsonData) {
        std::size_t assetId = oneData.value("textureId", 0);
        std::array<float, 2> pos = oneData.value("position", std::array<float, 2>({0, 0}));
        std::size_t callbackType = oneData.value("callback-type", -1);

        Entity button = _registry.spawn_entity_with(
            component::crect_t{ assets[FORBIDDEN_IDS::NETWORK].value().assets.at(assetId).getRectangle() },
            component::cposition_t{ pos[0], pos[1] },
            component::ctype_t{ .type = BUTTON },
            component::cassetid_t{ .assets = assetId },
            component::csceneid_t{ .sceneId = SCENE::MAIN_MENU },
            component::ccallback_t{ .callback = _callbackMap.at(callbackType) }
        );
    }
}

void Client::threadLoop()
{
    handleReceive();
    _context.run();
}