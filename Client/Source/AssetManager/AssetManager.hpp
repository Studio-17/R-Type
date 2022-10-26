/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** AssetManager
*/

#ifndef ASSETMANAGER_HPP_
    #define ASSETMANAGER_HPP_

    #include <string>
    #include <vector>
    #include <unordered_map>

    #include <nlohmann/json.hpp>

    #include "Asset.hpp"

class AssetManager {
    public:
        AssetManager(std::string const &assetsFile);
        ~AssetManager();


        void loadAssets(std::string const &filepath);
        enum ASSET_ID {
            spaceship_blue,
            spaceship_red,
            spaceship
        };
    protected:
    private:
        nlohmann::json getJsonData(std::string const &filepath);
        void saveAssets(std::string const &filepath);

        // std::unordered_map<ASSET_ID, Asset> _assets;
        std::unordered_map<std::size_t, Asset> _assets;
        // std::vector<Asset> _assets;
};

#endif /* !ASSETMANAGER_HPP_ */
