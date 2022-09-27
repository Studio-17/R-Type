/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Main
*/

#include <iostream>
#include "raylib.h"

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
    r.spawn_entity();
    std::cout << "Hello!!" << std::endl;


    component::position_t pos {50, 50};
    component::velocity_t velo {99, 99};
    component::drawable_t draw;
    component::controllable_t contro;

    InitWindow(1000, 900, "raylib [textures] example - texture loading and drawing");
    draw.texture = LoadTexture("Client/Source/canard.png");
    contro.isControllable = true;

    component::position_t posbis {50, 50};
    component::velocity_t velobis {99, 99};
    component::drawable_t drawbis;
    component::controllable_t controbis;
    drawbis.texture = LoadTexture("Client/Source/lapin.png");
    controbis.isControllable = true;

    r.register_component<component::position_t>(constructor, destructor);
    r.register_component<component::velocity_t>(constructor, destructor);
    r.register_component<component::drawable_t>(constructor, destructor);
    r.register_component<component::controllable_t>(constructor, destructor);

    r.add_component<component::position_t>(r.entity_from_index(0), std::move(pos));
    r.add_component<component::velocity_t>(r.entity_from_index(0), std::move(velo));
    r.add_component<component::drawable_t>(r.entity_from_index(0), std::move(draw));
    r.add_component<component::controllable_t>(r.entity_from_index(0), std::move(contro));

    r.add_component<component::position_t>(r.entity_from_index(1), std::move(posbis));
    r.add_component<component::velocity_t>(r.entity_from_index(1), std::move(velobis));
    r.add_component<component::drawable_t>(r.entity_from_index(1), std::move(drawbis));
    r.add_component<component::controllable_t>(r.entity_from_index(1), std::move(controbis));

    r.add_system(loggingSystem, r.get_components<component::position_t>(), r.get_components<component::velocity_t>());
    r.add_system(printSystem, r.get_components<component::position_t>(), r.get_components<component::drawable_t>());
    r.add_system(controlSystem, r.get_components<component::position_t>(), r.get_components<component::velocity_t>(), r.get_components<component::controllable_t>());

    Texture2D texture = LoadTexture("Client/Source/canard.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(BLACK);
            r.run_systems();

            DrawText("this IS a texture!", 360, 370, 10, GRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    // UnloadTexture(texture);
    CloseWindow();

    std::cout << "Hello World!" << std::endl;
}
/*
#include "Client.hpp"

int main()
{
	boost::asio::io_service io_service;
	Client client(io_service, "localhost", "8080");

	client.send("Hello, World!");
    std::cout << client.receive()<< std::endl;
	client.send("Hello, World!");
    std::cout << client.receive()<< std::endl;
	client.send("Hello, World!");
    std::cout << client.receive()<< std::endl;
	client.send("Hello, World!");
    std::cout << client.receive()<< std::endl;
    io_service.run();

}
*/