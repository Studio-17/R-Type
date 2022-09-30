/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** AUDIOERROR
*/

#ifndef AUDIOERROR_HPP_
    #define AUDIOERROR_HPP_

    #include "Errors.hpp"

namespace Error {
    /**
     * @brief AudioError class to handle throw, inherited from Errors
     *
     */
    class AudioError : public Errors {
        public:
            /**
             * @brief Construct a new Audio Error object
             *
             * @param message
             */
            AudioError(std::string const &message) throw();

            /**
             * @brief Destroy the Audio Error object
             *
             */
            virtual ~AudioError() throw();

        protected:
        private:
    };
}

#endif /* !AUDIOERROR_HPP_ */
