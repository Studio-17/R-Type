/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-martin.vanaud
** File description:
** WindowError
*/

#ifndef WINDOWERROR_HPP_
    #define WINDOWERROR_HPP_

    #include "Errors.hpp"

namespace Error {
    /**
     * @brief WindowError class to handle throw, inherited from Errors
     *
     */
    class WindowError : public Errors {
        public:
            /**
             * @brief Construct a new Window Error object
             *
             * @param message
             */
            WindowError(std::string const &message) throw();

            /**
             * @brief Destroy the Window Error object
             *
             */
            virtual ~WindowError() throw();

        protected:
        private:
    };
}

#endif /* !WINDOWERROR_HPP_ */
