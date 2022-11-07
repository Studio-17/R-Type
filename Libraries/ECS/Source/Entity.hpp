/*
** EPITECH PROJECT, 2022
** r-type
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_

    #include <iostream>

/**
 * @brief Class that handle entity in a sparse array like an index
 */
class Entity {
    public:
        /**
         * @brief Construct a new Entity object
         *
         * @param id Index of the entity
         */
        explicit Entity(std::size_t id) : _id(id) {
        };

        /**
         * @brief Destroy the Entity object
         */
        ~Entity() = default;

        /**
         * @brief  Operator () to return _id of the entity
         *
         * @return std::size_t Index of the entity
         */
        operator std::size_t() const {
            return _id;
        };

    protected:
        friend class Registry; ///< Friend object so that the Entoty can access the Registry object

    private:
        std::size_t _id; ///< The Entity _id as a std::size_t
};

#endif /* !ENTITY_HPP_ */
