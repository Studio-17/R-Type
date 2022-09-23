/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Main
*/

#include <iostream>
#include "ECS/Entity.hpp"
#include "ECS/Registry.hpp"
#include "ECS/SparseArray.hpp"
#include "ECS/Systems.hpp"
#include "ECS/Component.hpp"

int main()
{
    std::function constructor {[](Registry &r, Entity const &c) -> void {}};
    std::function destructor {[](Registry &r, Entity const &c) -> void {}};

    Registry r;
    r.spawn_entity();

    component::position_t pos {50, 50};
    r.register_component<component::position_t>(constructor, destructor);
    r.add_component<component::position_t>(r.entity_from_index(0), std::move(pos));
    std::cout << "Hello World!" << std::endl;

    return (0);
}
