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
        explicit Registry() = default;
        explicit Registry(std::size_t nbEntities) : _nbEntities(nbEntities)
        {
        };
        virtual ~Registry() = default;

        template <class Component>
        Sparse_array<Component> &register_component(std::function<void (Registry &, Entity const &)> creatorFunction, std::function<void (Registry &, Entity const &)> killerFunction)
        {
            _componentsArrays.try_emplace(std::type_index(typeid(Component)), std::make_any<Sparse_array<Component>>(_nbEntities));

            _creatorArrays.insert(std::make_pair(std::type_index(typeid(Component)), creatorFunction));
            _killerArrays.insert(std::make_pair(std::type_index(typeid(Component)), killerFunction));
            return std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));
        };

        template <class Component>
        Sparse_array<Component> &get_components()
        {
            return std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));
        };

        template <class Component>
        Sparse_array<Component> const &get_components() const
        {
            return std::any_cast<Sparse_array<Component> const &>(_componentsArrays.at(std::type_index(typeid(Component))));
        };


        Entity spawn_entity()
        {
            _nbEntities += 1;
            for (auto &it : _componentsArrays) {
                _creatorArrays.at(it.first)(*this, Entity(_nbEntities - 1));
            }
            return Entity(_nbEntities - 1);
        };

        Entity entity_from_index(std::size_t idx)
        {
            if (idx >= _nbEntities) {
                throw std::out_of_range("At this index, entity doesn't exist !");
            }
            return Entity(idx);
        };
        void kill_entity(Entity const &e)
        {
            _killedEntities.push_back(e);
            for (auto &it : _componentsArrays) {
                _killerArrays.at(it.first)(*this, e);
            }
        };

        template <typename Component>
        typename Sparse_array<Component>::reference_type add_component(Entity const &to, Component &&c)
        {
            if (_componentsArrays.find(std::type_index(typeid(Component))) == _componentsArrays.end())
                throw std::invalid_argument("Component not registered !");
            Sparse_array<Component> &sparseArray = std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));

            // if (to > sparseArray.size()) {
            //     sparseArray.extend(1);
            // }
            return sparseArray.insert_at(to, c);
        };

        template <typename Component, typename ...Params>
        typename Sparse_array<Component>::reference_type emplace_component(Entity const &to, Params &&...p)
        {
            Sparse_array<Component> sparseArray = std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));

            // if (to > sparseArray.size()) {
            //     sparseArray.extend(1);
            // }
            return sparseArray.emplaceAt(to, p...);
        };

        template <typename Component>
        void remove_component(Entity const &from)
        {
            Sparse_array<Component> &sparseArray = std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));

            sparseArray.erase(from);
        };

        template <class ...Component, typename Function>
        void add_system(Function &&f) {
            _listOfSystems.push_back([&f](Registry &registry) -> void {
                f(registry.get_components<Component>()...);
            });
        }

        template <class ...Component, typename Function>
        void add_system(Function const &f) {
            _listOfSystems.push_back([&f](Registry &registry) -> void {
                f(registry.get_components<Component>()...);
            });
        }

        void run_systems() {
            for (auto &function : _listOfSystems)
                function(*this);
        }

    private:
        std::map<std::type_index, std::function<void (Registry &, Entity const &)>> _killerArrays;
        std::map<std::type_index, std::function<void (Registry &, Entity const &)>> _creatorArrays;
        std::map<std::type_index, std::any> _componentsArrays;
        std::size_t _nbEntities = 0;
        std::vector<Entity> _killedEntities;
        std::vector<std::function<void(Registry &)>> _listOfSystems;
};

#endif /* !REGISTRY_HPP_ */
