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
         * @param creatorFunction 
         * @param killerFunction 
         * @return Sparse_array<Component>& 
         */
        template <class Component>
        Sparse_array<Component> &register_component(std::function<void (Registry &, Entity const &)> creatorFunction, std::function<void (Registry &, Entity const &)> killerFunction)
        {
            _componentsArrays.try_emplace(std::type_index(typeid(Component)), std::make_any<Sparse_array<Component>>(_nbEntities));

            _creatorArrays.insert(std::make_pair(std::type_index(typeid(Component)), creatorFunction));
            _killerArrays.insert(std::make_pair(std::type_index(typeid(Component)), killerFunction));
            return std::any_cast<Sparse_array<Component> &>(_componentsArrays.at(std::type_index(typeid(Component))));
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
            return std::any_cast<Sparse_array<Component> const &>(_componentsArrays.at(std::type_index(typeid(Component))));
        };

        /**
         * @brief A method to spawn an entity, it adds it to the creators array
         * 
         * @return Entity 
         */
        Entity spawn_entity()
        {
            _nbEntities += 1;
            for (auto &it : _componentsArrays) {
                _creatorArrays.at(it.first)(*this, Entity(_nbEntities - 1));
            }
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
            _killedEntities.push_back(e);
            for (auto &it : _componentsArrays) {
                _killerArrays.at(it.first)(*this, e);
            }
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

            sparseArray.erase(from);
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

//        template <class ...Component, typename Function>
//        void add_system(Function &&f) {
//            _listOfSystems.push_back([&f](Registry &registry) -> void {
//                f(registry.get_components<Component>()...);
//            });
//        }
//
//        template <class ...Component, typename Function>
//        void add_system(Function const &f) {
//            _listOfSystems.push_back([&f](Registry &registry) -> void {
//                f(registry.get_components<Component>()...);
//            });
//        }

        /**
         * @brief A method that is used to run all the systems of the registry
         * 
         */
        void run_systems() {
            for (auto &function : _listOfSystems)
                function(*this);
        }

    private:
        /**
         * @brief A map of all the killers bound by their types
         * 
         */
        std::map<std::type_index, std::function<void (Registry &, Entity const &)>> _killerArrays;

        /**
         * @brief A map of all the creators bound by their types
         * 
         */
        std::map<std::type_index, std::function<void (Registry &, Entity const &)>> _creatorArrays;

        /**
         * @brief A map of all the components bound by their types
         * 
         */
        std::map<std::type_index, std::any> _componentsArrays;

        /**
         * @brief The number of entity, by default 0
         * 
         */
        std::size_t _nbEntities = 0;

        /**
         * @brief  A vector containning the entities killed
         * 
         */
        std::vector<Entity> _killedEntities;

        /**
         * @brief A list containning all the systems
         * 
         */
        std::vector<std::function<void(Registry &)>> _listOfSystems;
};

#endif /* !REGISTRY_HPP_ */
