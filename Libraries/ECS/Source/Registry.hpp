/*
** EPITECH PROJECT, 2022
** r-type
** File description:
** Registry
*/

#ifndef REGISTRY_HPP_
    #define REGISTRY_HPP_

    #include <map>
    #include <any>
    #include <typeindex>
    #include <functional>

    #include "SparseArray.hpp"
    #include "Entity.hpp"

class Registry
{
    public:
        /**
         * @brief Construct a new Registry object
         *
         */
        explicit Registry() = default;

        /**
         * @brief Construct a new Registry object
         *
         * @param nbEntities
         */
        explicit Registry(std::size_t nbEntities) : _nbEntities(nbEntities) {};

        /**
         * @brief Destroy the Registry object
         *
         */
        virtual ~Registry() = default;

        /**
         * @brief A method to register a component to the registry, it inserts it inside the various arrays contained in the object
         *
         * @tparam Component
         * @return Sparse_array<Component>&
         */
        template <class Component>
        Sparse_array<Component> &register_component()
        {

            auto [it, ok] = _componentsArrays.try_emplace(std::type_index(typeid(Component)), std::make_any<Sparse_array<Component>>(_nbEntities));

            if (ok) {
                _erasers.emplace_back([](Registry &registry, Entity const &entity) {
                    registry.remove_component<Component>(entity);
                });
            } else {
                throw std::invalid_argument("Component already registered");
            }
            return std::any_cast<Sparse_array<Component> &>(it->second);
        };

        /**
         * @brief Get the components object
         *
         * @tparam Component
         * @return Sparse_array<Component>&
         */
        template <class Component>
        Sparse_array<Component> &get_components()
        {
            return std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));
        };

        /**
         * @brief Get the components object
         *
         * @tparam Component
         * @return Sparse_array<Component> const&
         */
        template <class Component>
        Sparse_array<Component> const &get_components() const
        {
            return std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));
        };

        /**
         * @brief A method to spawn an entity, it adds it to the creators array
         *
         * @return Entity
         */
        Entity spawn_entity()
        {
            _nbEntities += 1;

            return Entity(_nbEntities - 1);
        };

        /**
         * @brief A method to get an entity with its index
         *
         * @param idx
         * @return Entity
         */
        Entity entity_from_index(std::size_t idx) const
        {
            if (idx >= _nbEntities) {
                throw std::out_of_range("At this index, entity doesn't exist !");
            }
            return Entity(idx);
        };

        /**
         * @brief A method to kill an entity
         *
         * @param e
         */
        void kill_entity(Entity const &e)
        {
            for (auto &&it : _erasers)
                it(*this, e);
        };

        /**
         * @brief  A method to add a component to a known sparse array
         *
         * @tparam Component
         * @param to
         * @param c
         * @return Sparse_array<Component>::reference_type
         */
        template <typename Component>
        typename Sparse_array<Component>::reference_type add_component(Entity const &e, Component &&c)
        {
            if (_componentsArrays.find(std::type_index(typeid(Component))) == _componentsArrays.end())
                throw std::invalid_argument("Component not registered !");
            Sparse_array<Component> &sparseArray = std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));

            if (e > sparseArray.size()) {
                sparseArray.extend((size_t) e - sparseArray.size());
            }
            return sparseArray.insert_at(e, c);
        };

        /**
         * @brief A method to add a component at a position int the sparse array, a sparse array means that some cells mey be empty
         *
         * @tparam Component
         * @tparam Params
         * @param to
         * @param p
         * @return Sparse_array<Component>::reference_type
         */
        template <typename Component, typename ...Params>
        typename Sparse_array<Component>::reference_type emplace_component(Entity const &to, Params &&...p)
        {
            Sparse_array<Component> sparseArray = std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));

            // if (to > sparseArray.size()) {
            //     sparseArray.extend(1);
            // }
            return sparseArray.emplaceAt(to, p...);
        };

        /**
         * @brief A method to remove a component from an entity
         *
         * @tparam Component
         * @param from
         */
        template <typename Component>
        void remove_component(Entity const &from)
        {
            Sparse_array<Component> &sparseArray = std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));

            if (sparseArray.size() > from) {
                sparseArray.erase(from);
            }
        };

        /**
         * @brief A method to add a system to the registry, adds the element to the list of systems of the registry
         *
         * @tparam Component
         * @tparam Function
         * @param f
         * @param components
         */
        template <class ...Component, typename Function>
        void add_system(Function &&f, Component &&...components) {
            _listOfSystems.push_back([&f, &components...](Registry &registry) -> void {
                f(registry, components...);
            });
        }

        /**
         * @brief A method to add a system to the registry, adds the element to the list of systems of the registry
         *
         * @tparam Component
         * @tparam Function
         * @param f
         * @param components
         */
        template <class ...Component, typename Function>
        void add_system(Function const &f, Component &...components) {
            _listOfSystems.push_back([&f, &components...](Registry &registry) -> void {
                f(registry, components...);
            });
        }

        /**
         * @brief A method that is used to run all the systems of the registry
         *
         */
        void run_systems() {
            for (auto &function : _listOfSystems)
                function(*this);
        }

    private:
        std::vector<std::function<void (Registry &, Entity const &)>> _erasers; ///< A vector of all functions that can erase a component from every sparse array

        std::map<std::type_index, std::any> _componentsArrays; ///< A map of all the components bound by their types

        std::size_t _nbEntities = 0; ///< The number of entities, by default 0

        std::vector<Entity> _killedEntities; ///< A vector containning the entities killed

        std::vector<std::function<void(Registry &)>> _listOfSystems; ///< A list containning all the systems
};

#endif /* !REGISTRY_HPP_ */
