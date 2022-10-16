/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Entity.hpp"
#include "Registry.hpp"
#include "SparseArray.hpp"

#include "CDamage.hpp"
#include "CDirection.hpp"
#include "CHealth.hpp"
#include "CHitBox.hpp"
#include "CNetworkQueue.hpp"
#include "CPosition.hpp"
#include "CType.hpp"
#include "CVelocity.hpp"

class MoveSystem {
    public:
        MoveSystem() {};

        ~MoveSystem() = default;

        void operator()(Registry &registry,
                        Sparse_array<component::cnetwork_queue_t> &netqueue,
                        Sparse_array<component::cdirection_t> &direction,
                        Sparse_array<component::cposition_t> &position,
                        Sparse_array<component::cvelocity_t> &velocity) {
            for (unsigned short index = 0; index < position.size(); index++) {
                position[index]->x += (velocity[index]->velocity * direction[index]->x);
                if (position[index]->x > 1920)
                    position[index]->x = 0;
                position[index]->y += (velocity[index]->velocity * direction[index]->y);
            }
        };

    protected:
    private:
};

Test(SystemAddTest, SystemTests)
{
    Registry registry;
    MoveSystem _moveSystem;

    registry.register_component<component::cdamage_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cdirection_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::chealth_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::chitbox_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cposition_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cvelocity_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cnetwork_queue_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});

    registry.add_system(_moveSystem, registry.get_components<component::cnetwork_queue_t>(), registry.get_components<component::cdirection_t>(), registry.get_components<component::cposition_t>(), registry.get_components<component::cvelocity_t>());
}

Test(SystemRunTest, SystemTests)
{
    Registry registry;
    MoveSystem _moveSystem;

    registry.register_component<component::cdamage_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cdirection_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::chealth_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::chitbox_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cposition_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cvelocity_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});
    registry.register_component<component::cnetwork_queue_t>([](Registry &registry, Entity const &entity) -> void {}, [](Registry &registry, Entity const &entity) -> void {});

    registry.add_system(_moveSystem, registry.get_components<component::cnetwork_queue_t>(), registry.get_components<component::cdirection_t>(), registry.get_components<component::cposition_t>(), registry.get_components<component::cvelocity_t>());

    registry.run_systems();
}
