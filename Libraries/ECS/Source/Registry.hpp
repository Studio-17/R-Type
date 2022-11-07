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

/**
 * @brief Class that handle ECS
 */
class Registry
{
    public:
        /**
         * @brief Construct a new Registry object
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
         */
        virtual ~Registry() = default;

        /**
         * @brief A method to register a component to the registry, it inserts it inside the various arrays contained in the object
         *
         * @tparam Component Type of component to add in Sparse Array list
         * @return Sparse_array<Component>& The new Sparse Array of the component
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
         * @tparam Component Type of component to get in Sparse Array list
         * @return Sparse_array<Component>& The Sparse Array of the component
         */
        template <class Component>
        Sparse_array<Component> &get_components()
        {
            return std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));
        };

        /**
         * @brief Get the components object
         *
         * @tparam Component Type of component to get in Sparse Array list
         * @return Sparse_array<Component> const& The Sparse Array of the component
         */
        template <class Component>
        Sparse_array<Component> const &get_components() const
        {
            return std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));
        };

        /**
         * @brief A method to spawn an entity, it adds it to the creators array
         *
         * @return Entity The new entity created
         */
        Entity spawn_entity()
        {
            _nbEntities += 1;

            return Entity(_nbEntities - 1);
        };

        /**
         * @brief A method that create an entity and add all components you want to it
         *
         * @tparam Components Type of component That Entity will have
         * @param components Component That Entity will have
         * @return Entity The new entity created
         */
        template <class ...Components>
        Entity spawn_entity_with(Components && ...components) {
            Entity e = spawn_entity();

            (add_component(e, std::forward<Components>(components)), ...);
            return e;
        }

        /**
         * @brief A method to get an entity with its index
         *
         * @param idx Index of the entity
         * @return Entity Entity at index
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
         * @param e Entity to kill
         */
        void kill_entity(Entity const &e)
        {
            for (auto &&it : _erasers)
                it(*this, e);
        };

        /**
         * @brief  A method to add a component to a known sparse array
         *
         * @tparam Component Type of component That Entity will have
         * @param e Entity which component will be added
         * @param c Component to add in Entity
         * @return Sparse_array<Component>::reference_type The Sparse Array of the component that had be added
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
         * @tparam Component Type of component
         * @tparam Params Params to emplace at the Entity
         * @param to Entity which component will be added
         * @param p Params to emplace at the Entity
         * @return Sparse_array<Component>::reference_type The Sparse Array of the component that had be added
         */
        template <typename Component, typename ...Params>
        typename Sparse_array<Component>::reference_type emplace_component(Entity const &to, Params &&...p)
        {
            Sparse_array<Component> sparseArray = std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));
            return sparseArray.emplaceAt(to, p...);
        };

        /**
         * @brief A method to remove a component from an entity
         *
         * @tparam Component Type of component
         * @param from Entity where the component will be removed
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
         * @tparam Component Type of component
         * @tparam Function Type of System function to add
         * @param f System function to add
         */
        template <class ...Component, typename Function>
        void add_system(Function &&f) {
            _listOfSystems.push_back([&f](Registry &registry) -> void {
                f(registry, registry.get_components<Component>()...);
            });
        }

        /**
         * @brief A method to add a system to the registry, adds the element to the list of systems of the registry
         *
         * @tparam Component Type of component
         * @tparam Function Type of System function to add
         * @param f System function to add
         */
        template <class ...Component, typename Function>
        void add_system(Function const &f) {
            _listOfSystems.push_back([&f](Registry &registry) -> void {
                f(registry, registry.get_components<Component>()...);
            });
        }

        /**
         * @brief A method that is used to run all the systems of the registry
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
