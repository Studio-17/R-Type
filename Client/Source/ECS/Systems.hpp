/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Systems
*/

#ifndef SYSTEMS_HPP_
#define SYSTEMS_HPP_

#include "Registry.hpp"
#include "SparseArray.hpp"
#include "Component.hpp"

class Systems {
    public:
        Systems();
        ~Systems();
        void loggingSystem(Registry &r, Sparse_array<component::position_t> &pos) {
            (void)r;
            for (size_t i = 0; i < pos.size(); i++) {
            }
        }

    protected:
    private:
};

#endif /* !SYSTEMS_HPP_ */
