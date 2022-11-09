/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** RectSystem
*/

#ifndef RECTSYSTEM_HPP_
    #define RECTSYSTEM_HPP_

    /* Ecs */
    #include "Registry.hpp"

    /* Component */
    #include "Component/CRect.hpp"
    #include "Component/CTimer.hpp"
    #include "Component/CAsset.hpp"
    #include "Component/CAssetId.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief System that draws a part of all entities
    */
    class RectSystem {
        public:
            /**
            * @brief Construct a new Rect System object
            */
            RectSystem();
            ~RectSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
            *
            * @param registry registry of the client
            * @param rectangles The sparse array of rectangle entities
            * @param timer The sparse array of timer entities
            * @param assets The sparse array of assets entities
            * @param assetid The sparse array of assetid entities
            */
            void operator()(
                Registry &registry,
                Sparse_array<component::crect_t> &rectangles,
                Sparse_array<component::ctimer_t> &timer,
                Sparse_array<component::casset_t> &assets,
                Sparse_array<component::cassetid_t> &assetid
            );

        protected:
        private:
    };
}

#endif /* !RECTSYSTEM_HPP_ */
