/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
    #define ERRORS_HPP_

    #include <exception>
    #include <iostream>
    #include <string>

/**
 * @brief Error namespace that will contain all Error types
 */
namespace Error {
    /**
     * @brief Erorr class to handle throw
     */
    class Errors : public std::exception
    {
        public:
            /**
             * @brief Construct a new Errors object
             *
             * @param message Message to throw
             */
            Errors(std::string const &message) throw();

            /**
             * @brief Destroy the Errors object
             */
            virtual ~Errors() throw();

            /**
             * @brief Define the message error object
             *
             * @return const char* Message that has been throwed
             */
            const char *what() const throw();

        private:
            std::string _message; ///< The error message
    };
}

#endif /* !ERRORS_HPP_ */