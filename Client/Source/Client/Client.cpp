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
#include "CText.hpp"
#include "CScale.hpp"
#include "CCallback.hpp"
#include "Asset.hpp"
#include "CColor.hpp"
#include "Disconnection.hpp"
#include "Constant.hpp"
#include "fileConfig.hpp"

Client::Client(std::string const &ip, std::string const &port, int hostPort, std::map<std::string, std::string> &configurationFiles) :
    _com(std::make_unique<UdpCommunication>(_context, hostPort, port, ip)),
    _connected(true)
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
    _graphicLib->initWindow(1920, 1080, "R-Type", 120);

    _configurationFiles = configurationFiles;

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
    // disconnect();
}

void Client::disconnect()
{
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

void Client::startGameScene()
{
    Sparse_array<component::csceneid_t> &sceneId= _registry.get_components<component::csceneid_t>();

    sceneId[FORBIDDEN_IDS::NETWORK].value().sceneId = SCENE::GAME;
}

void Client::threadLoop()
{
    handleReceive();
    _context.run();
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
    _registry.register_component<component::cclient_network_id>();
    _registry.register_component<component::csceneid_t>();
    _registry.register_component<component::cscale_t>();
    _registry.register_component<component::ccallback_t>();
    _registry.register_component<component::ctext_t>();
    _registry.register_component<component::ccolor_t>();
}

void Client::setUpSystems()
{
    _registry.add_system<component::cnetwork_queue_t, component::cid_of_ship_t>(_networkSystem);
    // _registry.add_system<component::cnetwork_queue_t, component::cserverid_t>(_killSystem);
    _registry.add_system<component::crect_t, component::ctimer_t, component::ctype_t, component::casset_t, component::cassetid_t>(_rectSystem);
    _registry.add_system<component::ckeyboard_t, component::cnetwork_queue_t, component::cid_of_ship_t, component::csceneid_t>(_controlSystem);
	_registry.add_system<component::cposition_t, component::crect_t, component::csceneid_t, component::ctype_t, component::ccallback_t>(_mouseSystem);
    _registry.add_system<component::cnetwork_queue_t, component::cserverid_t, component::casset_t, component::cclient_network_id>(_newEntitySystem);
    _registry.add_system<component::cnetwork_queue_t>(_getLobbiesSystem);
    _registry.add_system<component::cnetwork_queue_t>(_setNbPlayerInLobbySystem);
    _registry.add_system<component::cnetwork_queue_t, component::cclient_network_id>(_newClientResponseSystem);
    // _registry.add_system<component::cnetwork_queue_t, component::cposition_t, component::cserverid_t>(_positionSystem);
    _registry.add_system<component::cdirection_t, component::cposition_t, component::cvelocity_t, component::ctimer_t>(_moveSystem);
	_registry.add_system<component::cposition_t, component::crect_t, component::casset_t, component::cassetid_t, component::csceneid_t, component::cscale_t>(_drawSpriteSystem);
    _registry.add_system<component::cposition_t, component::csceneid_t, component::cscale_t, component::ccolor_t, component::ctext_t>(_drawTextSystem);
}

void Client::setUpComponents()
{
    component::casset_t assetMan;
    assetMan.assets = AssetManager(_configurationFiles.at("ASSET"));

    Entity network = _registry.spawn_entity_with(
            component::cnetwork_queue_t{},
            component::ctype_t{ .type = NET },
            component::cid_of_ship_t{ .id = 0 },
            component::ckeyboard_t{ .keyboard = 0 },
            component::ctimer_t{ .deltaTime = std::chrono::steady_clock::now(), .animTimer = std::chrono::steady_clock::now() },
            component::casset_t{ .assets = assetMan.assets },
            component::csceneid_t{ .sceneId = SCENE::MAIN_MENU },
            component::cclient_network_id {}
    );

    loadParallax(_registry.get_components<component::casset_t>());
    loadButtons(_configurationFiles.at("BUTTONS"), _registry.get_components<component::casset_t>());
    loadTexts(_configurationFiles.at("TEXTS"));

    mainMenuScene(_registry.get_components<component::casset_t>());
}

void Client::mainMenuScene(Sparse_array<component::casset_t> &assets)
{
    Entity planet = _registry.spawn_entity_with(
        component::crect_t{ assets[FORBIDDEN_IDS::NETWORK].value().assets.at("planet").getRectangle() },
        component::cposition_t{ .x = 300, .y = 300 },
        component::ctype_t{ .type = UI },
        component::cassetid_t{ .assets = "planet" },
        component::csceneid_t{ .sceneId = SCENE::MAIN_MENU },
        component::cscale_t{ .scale = assets[FORBIDDEN_IDS::NETWORK].value().assets.at("planet").getScale() }
    );
}

void Client::loadParallax(Sparse_array<component::casset_t> &assets)
{
    std::pair<float, float> pos = {0, 0};
    std::vector<std::pair<std::string, int>> parallax = {
        {"parallax_background", 1},
        {"parallax_mountain", 3},
        {"parallax_ground", 4}
    };

    for (std::size_t i = 0; i <= 1; i++) {
        for (auto &[texture, velocity]: parallax) {
            Entity parallax_background = _registry.spawn_entity_with(
                component::crect_t{ assets[FORBIDDEN_IDS::NETWORK].value().assets.at(texture).getRectangle() },
                component::cposition_t{ .x = pos.first, .y = pos.second },
                component::cdirection_t{ .x = -1, .y = 0 },
                component::ctype_t{ .type = PARALLAX },
                component::cvelocity_t{ .velocity = velocity },
                component::cassetid_t{ .assets = texture },
                component::csceneid_t{ .sceneId = SCENE::ALL },
                component::cscale_t{ .scale = assets[FORBIDDEN_IDS::NETWORK].value().assets.at(texture).getScale() }
            );
        }
        pos.first += 1930;
    }
}

void Client::loadTexts(std::string const &filepath)
{
    nlohmann::json jsonData;

    try {
        jsonData = getJsonData(filepath);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    for (auto &oneData: jsonData) {
        int scene = oneData.value("scene", -1);
        createText(oneData, std::array<float, 2>({0, 0}), scene);
    }
}

void Client::createText(nlohmann::json const &oneData, std::array<float, 2> pos, int scene)
{
    std::array<float, 2> textPos = oneData.value("position", std::array<float, 2>({0, 0}));
    std::string content = oneData.value("text", "error");
    std::string font = oneData.value("font", "Assets/Fonts/Square.ttf");
    float spacing = oneData.value("spacing", 0);
    float fontSize = oneData.value("fontSize", 30);
    std::array<float, 4> color = oneData.value("color", std::array<float, 4>({255, 255, 255, 255}));

    Entity text = _registry.spawn_entity_with(
        component::ctext_t{ .text = content, .font = font, .spacing = spacing },
        component::cposition_t{ .x = pos[0] + textPos[0], .y = pos[1] + textPos[1] },
        component::ctype_t{ .type = TEXT },
        component::csceneid_t{ .sceneId = static_cast<SCENE>(scene) },
        component::cscale_t{ .scale = fontSize },
        component::ccolor_t{ .color = color }
    );
}

void Client::loadButtons(std::string const &filepath, Sparse_array<component::casset_t> &assets)
{
    nlohmann::json jsonData;

    try {
        jsonData = getJsonData(filepath);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    _callbackMap = {
        {"start-game", std::bind(&Client::startGameScene, this)},
    };

    for (auto &oneData: jsonData) {
        std::string assetId = oneData.value("textureId", "button");
        std::array<float, 2> pos = oneData.value("position", std::array<float, 2>({0, 0}));
        std::string callbackType = oneData.value("callback-type", "undifined");
        int scene = oneData.value("scene", -1);
        component::crect_t rectangle = assets[FORBIDDEN_IDS::NETWORK].value().assets.at(assetId).getRectangle();
        int nb_frames = oneData.value("nbFrame", 1);

        Entity button = _registry.spawn_entity_with(
                component::crect_t{ .x = rectangle.x, .y = rectangle.y, .width = rectangle.width, .height = rectangle.height / nb_frames, .current_frame = rectangle.current_frame, .nb_frames = rectangle.nb_frames },
                component::cposition_t{ .x = pos[0], .y = pos[1] },
                component::ctype_t{ .type = BUTTON },
                component::cassetid_t{ .assets = assetId },
                component::csceneid_t{ .sceneId = static_cast<SCENE>(scene) },
                component::ccallback_t{ .callback = _callbackMap.at(callbackType) },
                component::cscale_t{ .scale = assets[FORBIDDEN_IDS::NETWORK].value().assets.at(assetId).getScale() }
        );
        if (oneData.contains("Text"))
            createText(oneData.at("Text"), pos, scene);
    }
}