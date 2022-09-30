/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** PositionError
*/

#ifndef POSITIONERROR_HPP_
    #define POSITIONERROR_HPP_

    #include "Errors.hpp"

namespace Error {
    /**
     * @brief PositionError class to handle throw, inherited from Errors
     *
     */
    class PositionError : public Errors {
        public:
            /**
             * @brief Construct a new Position Error object
             *
             * @param message
             */
            PositionError(std::string const &message) throw();

            /**
             * @brief Destroy the Position Error object
             *
             */
            virtual ~PositionError() throw();

        protected:
        private:
    };
}

#endif /* !POSITIONERROR_HPP_ */
