/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Registry.hpp"
#include "Entity.hpp"
#include "SparseArray.hpp"

#include "CDamage.hpp"
#include "CDirection.hpp"
#include "CHealth.hpp"
#include "CHitBox.hpp"
#include "CNetworkQueue.hpp"
#include "CPosition.hpp"
#include "CType.hpp"
#include "CVelocity.hpp"

Test(RegistryRegisterTest, RegistryTests)
{
    Registry registry;

    registry.register_component<component::cdamage_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cdirection_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::chealth_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::chitbox_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cposition_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cvelocity_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cnetwork_queue_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
}

Test(RegistryAddTest, RegistryTests)
{
    Registry registry;

    registry.register_component<component::cdamage_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cdirection_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::chealth_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::chitbox_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cposition_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cvelocity_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cnetwork_queue_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});

    Entity networkEntity = registry.spawn_entity();

    component::cdamage_t damage = { 0 };
    registry.add_component<component::cdamage_t>(registry.entity_from_index(networkEntity), std::move(damage));
    if (registry.get_components<component::cdamage_t>()[0].value().damage != 0)
        cr_assert(true);

    component::cdirection_t direction = { 0, 0 };
    registry.add_component<component::cdirection_t>(registry.entity_from_index(networkEntity), std::move(direction));
    if (registry.get_components<component::cdirection_t>()[0].value().x != 0)
        cr_assert(true);

    component::chealth_t health = {10 };
    registry.add_component<component::chealth_t>(registry.entity_from_index(networkEntity), std::move(health));
    if (registry.get_components<component::chealth_t>()[0].value().health != 0)
        cr_assert(true);

    component::chitbox_t hitbox = {10, 10};
    registry.add_component<component::chitbox_t>(registry.entity_from_index(networkEntity), std::move(hitbox));
    if (registry.get_components<component::chitbox_t>()[0].value().height != 0)
        cr_assert(true);

    component::cposition_t position = {10, 10};
    registry.add_component<component::cposition_t>(registry.entity_from_index(networkEntity), std::move(position));
    if (registry.get_components<component::cposition_t>()[0].value().x != 0)
        cr_assert(true);

    component::cvelocity_t velocity = {10 };
    registry.add_component<component::cvelocity_t>(registry.entity_from_index(networkEntity), std::move(velocity));
    if (registry.get_components<component::cvelocity_t>()[0].value().velocity != 0)
        cr_assert(true);

    component::cnetwork_queue_t network = {};
    registry.add_component<component::cnetwork_queue_t>(registry.entity_from_index(networkEntity), std::move(network));
    if (!registry.get_components<component::cnetwork_queue_t>()[0].value().receivedNetworkQueue.empty())
        cr_assert(true);
}
