/*
** EPITECH PROJECT, 2022
** R-Type
** File description:
** Created by casimir,
*/

#include <asio.hpp>

#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Registry.hpp"
#include "Entity.hpp"
#include "SparseArray.hpp"

#include "UdpCommunication.hpp" 

Test(NetworkModuleTest, NetworkTest)
{
    asio::io_context context;
    UdpCommunication communicationModule(context, 8484);

    communicationModule.setEnpointInfo(asio::ip::address::from_string("127.0.0.1"), 8484);

    cr_assert_str_eq(communicationModule.getEnpointInfo().first.to_string().c_str(), "127.0.0.1");
    cr_assert_eq(communicationModule.getEnpointInfo().second, 8484);
}
