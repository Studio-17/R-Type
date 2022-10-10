/*
** EPITECH PROJECT, 2022
** r-type
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_

    #include <iostream>


class Entity {
    public:
        explicit Entity(std::size_t id) : _id(id) {
        };
        ~Entity() = default;

        operator std::size_t() const {
            return _id;
        };

    protected:
        friend class Registry;
    private:
        std::size_t _id;
};

#endif /* !ENTITY_HPP_ */
