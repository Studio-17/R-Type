/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-martin.vanaud
** File description:
** Position
*/

#ifndef POSITION_HPP_
    #define POSITION_HPP_

    #include <raylib.h>

    #include <array>
    #include <ostream>

/**
 * @brief 3 dimension Position class (x, y, z)
 */
class Position {
    public:
        /**
         * @brief Construct a new Position object from positions sent as parameter
         *
         * @param x position x value
         * @param y position y value
         * @param z position z value
         */
        Position(float x, float y, float z = 0);
        /**
         * @brief Construct a new object from other Position object sent as parameter
         *
         * @param position other Position object where we get x, y, z value
         */
        Position(Position const &position);
        /**
         * @brief Construct a new Position object from default values
         */
        Position();

        /**
         * @brief Destroy the Position object
         */
        ~Position();

        /**
         * @brief Check if all positions are the same (x, y z)
         *
         * @param position position to compare with the element
         * @return true if all positions have the same value (x, y z)
         * @return false if some position have not the same value (x, y, z)
         */
        bool operator ==(Position const &position);

        /**
         * @brief Set x, y, z from other float array
         *
         * @param position array from where we copy x, y, z value
         */
        Position &setFromArray(std::array<float, 3> const &position);
        /**
         * @brief Set x, y, z from other Postition object
         *
         * @param position Position object from where we copy x, y, z value
         * @return Position& himself
         */
        Position &operator =(Position const &position);
        /**
         * @brief Set x, y, z from a value
         *
         * @param pos value to set to x, y, z
         * @return Position& himself
         */
        Position &operator =(float pos);

        Position operator +(float value);
        Position operator +(Position const &position);

        Position operator -(float value);
        Position operator -(Position const &position);

        Position operator *(float value);
        Position operator *(Position const &position);

        /**
         * @brief Add to x, y, z respectively the x, y, z of the Position object sent as parameter
         *
         * @param position Position object containing x, y, z to add
         * @return Position& himself
         */
        Position &operator +=(Position const &position);
        /**
         * @brief Add to x, y, z a value
         *
         * @param number The value to add
         * @return Position& himself
         */
        Position &operator +=(float number);

        /**
         * @brief Substract to x, y, z respectively the x, y, z of the Position object sent as parameter
         *
         * @param position Position object containing x, y, z to substract
         * @return Position& himself
         */
        Position &operator -=(Position const &position);
        /**
         * @brief Substract to x, y, z a value
         *
         * @param number The value to substract
         * @return Position& himself
         */
        Position &operator -=(float number);

        /**
         * @brief multiply to x, y, z respectively the x, y, z of the Position object sent as parameter
         *
         * @param position Position object containing x, y, z to multiply
         * @return Position& himself
         */
        Position &operator *=(Position const &position);
        /**
         * @brief multiply to x, y, z a value
         *
         * @param number The value to multiply
         * @return Position& himself
         */
        Position &operator *=(float number);

        /**
         * @brief divide to x, y, z respectively the x, y, z of the Position object sent as parameter
         *
         * @throw Error::PositionError if x, y or z of position is equal 0 (can't divide by 0)
         * @param position Position object containing x, y, z to divide
         * @return Position& himself
         */
        Position &operator /=(Position const &position);
        /**
         * @brief divide to x, y, z a value
         *
         * @throw Error::PositionError if number is equal 0 (can't divide by 0)
         * @param number The value to divide
         * @return Position& himself
         */
        Position &operator /=(float number);

        /**
         * @brief Set the position
         *
         * @param x new x value
         * @param y new y value
         */
        void setPosition(float x, float y);
        /**
         * @brief Set the position
         *
         * @param x new x value
         * @param y new y value
         * @param z new z value
         */
        void setPosition(float x, float y, float z);
        /**
         * @brief Set the position
         *
         * @param position Position object from where we get new x, y, z value
         */
        void setPosition(Position const &position);
        /**
         * @brief set x value
         *
         * @param x new x value
         */
        void setX(float x);
        /**
         * @brief set y value
         *
         * @param y new y value
         */
        void setY(float y);
        /**
         * @brief set z value
         *
         * @param z new z value
         */
        void setZ(float z);

        /**
         * @brief reset x, y, z to 0
         *
         */
        void reset();

        /**
         * @brief Get x, y, z position in an array
         *
         * @return std::array<float, 3> array of x, y, z
         */
        std::array<float, 3> getPosition() const;
        /**
         * @brief get x value
         *
         * @return float x value
         */
        float getX() const;
        /**
         * @brief get y value
         *
         * @return float y value
         */
        float getY() const;
        /**
         * @brief get z value
         *
         * @return float z value
         */
        float getZ() const;

        /**
         * @brief Get the Vector3 object from Position values
         *
         * @return Vector3 object with x, y, z corresponding of x, y, z of Position object
         */
        Vector3 getVector3() const;
        /**
         * @brief Get the Vector2 object from Position values
         *
         * @return Vector2 object with x, y corresponding of x, y of Position object
         */
        Vector2 getVector2() const;
    private:
        float _x; ///< position x
        float _y; ///< position y
        float _z; ///< position z
};

/**
 * @brief overload of << function to print x, y, z values
 *
 * @return std::ostream& output redirect
 */
std::ostream &operator<<(std::ostream &, const Position &);

bool operator <(Position const &position, float value);
bool operator <(Position const &position, Position const &position2);

bool operator >(Position const &position, float value);
bool operator >(Position const &position, Position const &position2);

#endif /* !POSITION_HPP_ */
