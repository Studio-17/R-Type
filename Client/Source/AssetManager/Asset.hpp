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
    #include "CRect.hpp"

class Asset {
    public:
        Asset(nlohmann::json const &jsonData);
        ~Asset();

    protected:
    private:
        MyTexture _texture;
        float _scale;
        component::crect_t _rectangle;
        int _nbFrame;
};

#endif /* !ASSET_HPP_ */
