/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** RectSystem
*/

#ifndef RECTSYSTEM_HPP_
    #define RECTSYSTEM_HPP_

    #include "Registry.hpp"
    #include "GraphicalLib.hpp"
    #include "CRect.hpp"
    #include "CTimer.hpp"
    #include "CType.hpp"
    #include "CAsset.hpp"
    #include "CAssetId.hpp"

/**
 * @brief System that draws a part of all entities
 */
class RectSystem {
    public:
        /**
        * @brief Construct a new Rect System object
         *
         */
        RectSystem();
        /**
         * @brief Destroy the Rect System object
         *
         */
        ~RectSystem() = default;

        /**
         * @brief Function that will be automaticaly called while the client is working (on loop)
         * 
         * @param registry registry of the client
         * @param sprites sparse array of sprite entities
         * @param rectangles sparse array of rectangle entities
         * @param timer sparse array of timer entities
         * @param types sparse array of type entities
         */
        void operator()(Registry &registry, Sparse_array<component::crect_t> &rectangles,
                                            Sparse_array<component::ctimer_t> &timer,
                                            Sparse_array<component::ctype_t> &types,
                                            Sparse_array<component::casset_t> &assets,
                                            Sparse_array<component::cassetid_t> &assetid);

    protected:
    private:
        std::shared_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
};

#endif /* !RECTSYSTEM_HPP_ */
