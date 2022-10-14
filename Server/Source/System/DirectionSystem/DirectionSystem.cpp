/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** DirectionSystem
*/


#include "Registry.hpp"

#include "Component/CDirection.hpp"
#include "Component/CPosition.hpp"
#include "Component/CVelocity.hpp"

#include "DirectionSystem.hpp"

DirectionSystem::DirectionSystem()
{
}

void DirectionSystem::operator()(Registry &registry, Sparse_array<component::cdirection_t> &direction,Sparse_array<component::cposition_t> &position,Sparse_array<component::cvelocity_t> &velocity)
{
    // revoit la nouvelle direction d'un client

    // open queue direction et update composant direction 
}
