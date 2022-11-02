/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** ButtonSystem
*/

#include <string>
#include <fstream>
#include "CRect.hpp"
#include "CPosition.hpp"
#include "CType.hpp"
#include "CSceneId.hpp"
#include "CAssetId.hpp"
#include "Constant.hpp"
#include "ButtonSystem.hpp"

ButtonSystem::ButtonSystem()
{
    _graphicLib = std::make_unique<rtype::GraphicalLib>();
}

nlohmann::json ButtonSystem::getJsonData(std::string const &filepath)
{
    nlohmann::json jsonData;
    std::ifstream confStream(filepath);

    if (!confStream.is_open())
        throw ("file " + filepath + " failed to open");
    confStream >> jsonData;
    confStream.close();
    return jsonData;
}

void ButtonSystem::loadButton(std::string const &filepath, [[ maybe_unused ]]Registry &registry, [[ maybe_unused ]]Sparse_array<component::casset_t> &assets)
{
    nlohmann::json jsonData;

    try {
        jsonData = getJsonData(filepath);
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    for (auto &oneData: jsonData) {
        std::size_t assetId = oneData.value("textureId", 0);
        std::array<float, 2> pos = oneData.value("position", std::array<float, 2>({0, 0}));

        Entity button = registry.spawn_entity_with(
            component::crect_t{ assets[FORBIDDEN_IDS::NETWORK].value().assets.at(assetId).getRectangle() },
            component::cposition_t{ pos[0], pos[1] },
            component::ctype_t{ .type = BUTTON },
            component::cassetid_t{ .assets = assetId },
            component::csceneid_t{ .sceneId = SCENE::MAIN_MENU }
        );
    }
}

void ButtonSystem::operator()([[ maybe_unused ]]Registry &registry, [[ maybe_unused ]]Sparse_array<component::cnetwork_queue_t> &network, [[ maybe_unused ]]Sparse_array<component::cserverid_t> &serverIds, [[ maybe_unused ]]Sparse_array<component::casset_t> &assets)
{

    loadButton("Assets/buttons.json", registry, assets);

}
