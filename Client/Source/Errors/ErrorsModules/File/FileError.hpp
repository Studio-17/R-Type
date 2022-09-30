/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** FileError
*/

#ifndef FILEERROR_HPP_
    #define FILEERROR_HPP_

    #include "Errors.hpp"
namespace Error {
    /**
     * @brief FileError class to handle throw, inherited from Errors
     *
     */
    class FileError : public Errors {
        public:
            /**
             * @brief Construct a new File Error object
             *
             * @param message
             */
            FileError(std::string const &message) throw();

            /**
             * @brief Destroy the File Error object
             *
             */
            virtual ~FileError() throw();

        protected:
        private:
    };
}

#endif /* !FILEERROR_HPP_ */
