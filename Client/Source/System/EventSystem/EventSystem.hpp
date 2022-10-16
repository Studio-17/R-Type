/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** EventSystem
*/

#ifndef EVENTSYSTEM_HPP_
    #define EVENTSYSTEM_HPP_

    #include "Registry.hpp"
    #include "Mouse.hpp"
    #include "CKeyboard.hpp"

/**
 * @brief Namespace for systems
 * 
 */
namespace systemNamespace {
    /**
     * @brief System in charge of all the event implying keyboard and mouse state of the client
     * 
     */
    class EventSystem {
        public:
            /**
             * @brief Construct a new Event System object
             * 
             */
            EventSystem();
            /**
             * @brief Destroy the Event System object
             * 
             */
            ~EventSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             * 
             * @param registry The registry that contains all the ECS
             * @param mouses Sparse array of all mouse component of all entities
             * @param keyboards Sparse array of all keyboard component of all entities
             */
            void operator()(Registry &registry, Sparse_array<component::mouseState_t> &mouses, Sparse_array<component::ckeyboard_t> &keyboards);


        protected:
        private:
            int _graphicLib; // Need to replace the type
    };
};

#endif /* !EVENTSYSTEM_HPP_ */
