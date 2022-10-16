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

Test(ComponentDamageTest, ComponentTest)
{
    component::cdamage_t damage = { 0 };
    cr_assert_eq(damage.damage, 0);

}

Test(ComponentDirectionTest, ComponentTest)
{
    component::cdirection_t direction = { 0, 0 };
    cr_assert_eq(direction.x, 0);
    cr_assert_eq(direction.y, 0);
}

Test(ComponentHealthTest, ComponentTest)
{
    component::chealth_t health = { 10 };
    cr_assert_eq(health.health, 10);
}

Test(ComponentHitboxTest, ComponentTest)
{
    component::chitbox_t hitbox = { 10, 10 };
    cr_assert_eq(hitbox.height, 10);
    cr_assert_eq(hitbox.width, 10);
}

Test(ComponentPositionTest, ComponentTest)
{
    component::cposition_t position = { 10, 10 };
    cr_assert_eq(position.x, 10);
    cr_assert_eq(position.y, 10);
}

Test(ComponentVelocityTest, ComponentTest)
{
    component::cvelocity_t velocity = { 10 };
    cr_assert_eq(velocity.velocity, 10);
}
