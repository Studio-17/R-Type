/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** spec
*/

#ifndef SPEC_HPP_
    #define SPEC_HPP_

    #include <utility>
    #include <nlohmann/json.hpp>

    #include "Serialization.hpp"

/**
 * @brief A structure representing the specs of an entity from configuration file
    */
struct spec_t {
    spec_t(nlohmann::json const &jsonData) {
        std::array<int, 2> directionData = jsonData.value("direction", std::array<int, 2>({0, 0}));
        std::array<std::size_t, 2> hitboxData = jsonData.value("hitbox", std::array<std::size_t, 2>({0, 0}));
        std::array<float, 2> rectData = jsonData.value("rect", std::array<float, 2>({0, 0}));
        direction = {directionData.at(0), directionData.at(1)};
        hitbox = {hitboxData.at(0), hitboxData.at(1)};
        rect = {rectData.at(0), rectData.at(1)};
        velocity = jsonData.value("velocity", 1);
        type = static_cast<ENTITY_TYPE>(jsonData.value("type", 1));
        health = jsonData.value("health", 1);
    };
    std::pair<int, int> direction;
    std::pair<std::size_t, std::size_t> hitbox;
    int velocity;
    ENTITY_TYPE type;
    std::pair<float, float> rect;
    int health;
};

#endif /* !SPEC_HPP_ */
