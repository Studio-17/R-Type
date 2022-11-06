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

/**
 * @brief Class to store all Assets
 */
class AssetManager {
    public:
        /**
         * @brief Construct a new Asset Manager object
         *
         * @param assetsFile File of all assets
         */
        AssetManager(std::string const &assetsFile);

        /**
         * @brief Construct a new Asset Manager object
         */
        AssetManager();

        /**
         * @brief Destroy the Asset Manager object
         */
        ~AssetManager();

        /**
         * @brief Get the Asset at index sent as param
         *
         * @param index Index of the Asset in map
         * @return Asset Asset from the map
         */
        Asset at(std::string const &index) const;

        /**
         * @brief Load all assets from a config file
         *
         * @param filepath Configuration file path containing data of all assets
         */
        void loadAssets(std::string const &filepath);

        /**
         * @brief Enum of assets in map
         */
        enum ASSET_ID {
            spaceship_blue,
            spaceship_red,
            spaceship
        };
    protected:
    private:
        /**
         * @brief Function to save assets in configuration file all assets
         *
         * @param filepath Path of the file to save assets
         */
        void saveAssets(std::string const &filepath);

        std::unordered_map<std::string, Asset> _assets; ///< map of all assets
};

#endif /* !ASSETMANAGER_HPP_ */
