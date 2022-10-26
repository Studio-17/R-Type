/*
** EPITECH PROJECT, 2022
** r-type
** File description:
** SparseArray
*/

#ifndef SPARSEARRAY_HPP_
    #define SPARSEARRAY_HPP_

    #include <iostream>
    #include <optional>
    #include <vector>
    #include <memory>

template <typename Component>
class Sparse_array {
    public:
        using value_type = std::optional<Component>;
        using reference_type = value_type &;
        using const_reference_type = value_type const &;
        using container_t = std::vector<value_type>;
        using iterator = typename container_t::iterator;
        using const_iterator = typename container_t::const_iterator;
        using size_type = typename container_t::size_type;

    public:
        /**
         * @brief Construct a new Sparse_array object
         *
         */
        Sparse_array() = default;

        /**
         * @brief Construct a new Sparse_array object
         * 
         * @param sp_arr
         */
        explicit Sparse_array(Sparse_array const &sp_arr)
        {
            for (std::size_t i = 0; i < sp_arr.size(); i++) {
                _data.push_back(std::nullopt);
            }
            for (std::size_t i = 0; i < sp_arr.size(); i++) {
                _data[i] = sp_arr._data[i];
            }
        };

        /**
         * @brief Construct a new Sparse_array object
         *
         * @param sp_arr
         */
        explicit Sparse_array(Sparse_array &&sp_arr) noexcept : _data(std::move(sp_arr._data)) {};

        /**
         * @brief Construct a new Sparse_array object
         *
         * @param size
         */
        explicit Sparse_array(std::size_t size)
        {
            for (std::size_t i = 0; i < size; i++) {
                _data.push_back(std::nullopt);
            }
        };

        /**
         * @brief Destroy the Sparse_array object
         *
         */
        virtual ~Sparse_array() = default;

        /**
         * @brief Overload the operator =
         *
         * @param sp_arr
         * @return Sparse_array&
         */
        Sparse_array &operator=(Sparse_array const &sp_arr)
        {
            std::swap(_data, sp_arr._data);
            return *this;
        };

        /**
         * @brief Overload the operator =
         *
         * @param sp_arr
         * @return Sparse_array&
         */
        Sparse_array &operator=(Sparse_array &&sp_arr) noexcept
        {
            _data = std::move(sp_arr._data);
            return *this;
        };

        /**
         * @brief Overloads the operator []
         *
         * @param idx
         * @return reference_type
         */
        reference_type operator[](size_t idx)
        {
            return _data[idx];
        };

        /**
         * @brief Overloads the operator [] const
         *
         * @param idx
         * @return const_reference_type
         */
        const_reference_type operator[](size_t idx) const
        {
            return _data[idx];
        };

        /**
         * @brief Overloads the operator begin()
         *
         * @return iterator
         */
        iterator begin()
        {
            return _data.begin();
        };

        /**
         * @brief Overloads the operator begin() const
         *
         * @return const_iterator
         */
        const_iterator begin() const
        {
            return _data.begin();
        };

        /**
         * @brief Overloads the operator cbegin() const
         *
         * @return const_iterator
         */
        const_iterator cbegin() const
        {
            return _data.cbegin();
        };

        /**
         * @brief Overloads the operator ebd()
         *
         * @return iterator
         */
        iterator end()
        {
            return _data.end();
        };

        /**
         * @brief Overloads the operator end() const
         *
         * @return const_iterator
         */
        const_iterator end() const
        {
            return _data.end();
        };

        /**
         * @brief Overloads the operator cend() const
         *
         * @return const_iterator
         */
        const_iterator cend() const
        {
            return _data.cend();
        };

        /**
         * @brief Overloads the operator size()
         *
         * @return size_type
         */
        size_type size() const
        {
            return _data.size();
        };

        /**
         * @brief Overload the operator extend()
         *
         * @param sizeToExtend
         */
        void extend(size_t sizeToExtend)
        {
            for (size_t x = 0; x < sizeToExtend; x += 1)
                _data.push_back(std::nullopt);
        }

        /**
         * @brief Overloads the operator insert_at()
         *
         * @param pos
         * @param component
         * @return reference_type
         */
        reference_type insert_at(size_type pos, Component const &component)
        {
            if (pos > _data.size())
                throw std::invalid_argument("Invalid pos in insert_at (SparseArray)");
            if (pos < _data.size()) {
                auto tmp = _data.get_allocator();

                std::allocator_traits<decltype(tmp)>::destroy(tmp, std::addressof(_data[pos]));
                _data[pos] = component;
                return _data[pos];
            }

            _data.push_back(component);
            return _data.back();
        };

        /**
         * @brief Overloads the operator insert_at()
         *
         * @param pos
         * @param component
         * @return reference_type
         */
        reference_type insert_at(size_type pos, Component &&component)
        {
            if (pos > _data.size())
                throw std::invalid_argument("Invalid position in sparse array");
            if (pos < _data.size()) {
                auto tmp = _data.get_allocator();

                std::allocator_traits<decltype(tmp)>::destroy(tmp, std::addressof(_data[pos]));
                _data[pos] = std::move(component);
                return _data[pos];
            }

            _data.push_back(std::move(component));
            return _data.back();
        };

        /**
         * @brief Overloads the operator emplace_at()
         *
         * @tparam Params
         * @param pos
         * @param params
         * @return reference_type
         */
        template <class... Params>
        reference_type emplace_at(size_type pos, Params &&...params)
        {
            if (pos > _data.size())
                throw std::invalid_argument("Invalid pos in sparse array");
            auto tmp = _data.get_allocator();
            std::allocator_traits<decltype(tmp)>::destroy(tmp, std::addressof(_data[pos]));
            std::allocator_traits<decltype(tmp)>::construct(tmp, std::addressof(_data[pos]), std::forward(params)...);
            return _data[pos];
        };

        /**
         * @brief Overloads the operator erase()
         *
         * @param pos
         */
        void erase(size_type pos)
        {
            _data[pos] = std::nullopt;
        };

        /**
         * @brief Get the index object
         *
         * @param val_type
         * @return size_type
         */
        size_type get_index(value_type const &val_type) const
        {
            auto tmp = std::addressof(val_type);

            for (std::size_t i = 0; i < _data.size(); i++) {
                if (tmp == std::addressof(_data[i]))
                    return i;
            }
            throw std::invalid_argument("Component doesn't exist (SparseArray)");
        };

    private:
        container_t _data; ///< A container named data, it holds the object informations
};

#endif /* !SPARSEARRAY_HPP_ */
