/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Asset
*/

#ifndef ASSET_HPP_
    #define ASSET_HPP_

    #include <nlohmann/json.hpp>

    #include "MyTexture.hpp"

    /* Component */
    #include "Component/CRect.hpp"

/**
 * @brief Class containing all elements of an Asset
 */
class Asset {
    public:
        /**
         * @brief Construct a new Asset object
         *
         * @param jsonData json data to load asset
         */
        Asset(nlohmann::json const &jsonData);

        /**
         * @brief Destroy the Asset object
         */
        ~Asset();

        /**
         * @brief Get the Texture object
         *
         * @return MyTexture& Texture of the asset
         */
        MyTexture &getTexture();

        /**
         * @brief Get the Scale object
         *
         * @return float Scale of the asset
         */
        float getScale() const;

        /**
         * @brief Get the Rectangle object
         *
         * @return component::crect_t Rectangle of the asset
         */
        component::crect_t getRectangle() const;

    protected:
    private:
        MyTexture _texture; ///< Texture of the asset
        float _scale; ///< Scale of the asset
        component::crect_t _rectangle; ///< Rectangle of the asset
};

#endif /* !ASSET_HPP_ */
