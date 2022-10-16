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
        /**
         * @brief Construct a new Entity object
         * 
         * @param id 
         */
        explicit Entity(std::size_t id) : _id(id) {
        };

        /**
         * @brief Destroy the Entity object
         * 
         */
        ~Entity() = default;

        /**
         * @brief  Operator () to return _id of the entity
         * 
         * @return std::size_t 
         */
        operator std::size_t() const {
            return _id;
        };

    protected:
        /**
         * @brief  Friend object so that the Entoty can access the Registry object
         * 
         */
        friend class Registry; 
    private:
        /**
         * @brief  The Entity _id as a std::size_t
         * 
         */
        std::size_t _id;
};

#endif /* !ENTITY_HPP_ */
