/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** MouseSystem
*/

#ifndef MOUSESYSTEM_HPP_
    #define MOUSESYSTEM_HPP_

    #include "Registry.hpp"
    #include "GraphicalLib.hpp"

    /* Component */
	#include "Component/CPosition.hpp"
    #include "Component/CRect.hpp"
	#include "Component/CSceneId.hpp"
    #include "Component/CType.hpp"
    #include "Component/CCallback.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief MouseSystem class that handles the mouse
     */
    class MouseSystem {
        public:
            /**
             * @brief Construct a new Mouse System object
             */
            MouseSystem();
            ~MouseSystem() = default;

            /**
             * @brief Function that will be automaticaly called while the client is working (on loop)
             *
             * @param registry The registry of the client
             * @param positions The sparse array of position entities
             * @param rects The sparse array of rect entities
             * @param scenesId The sparse array of scenesId entities
             * @param types The sparse array of type entities
             * @param callbacks The sparse array of callback entities
             */
    		void operator()(Registry &registry,
                            Sparse_array<component::cposition_t> &positions,
                            Sparse_array<component::crect_t> &rects,
                            Sparse_array<component::csceneid_t> &scenesId,
                            Sparse_array<component::ctype_t> &types,
                            Sparse_array<component::ccallback_t> &callbacks);

        protected:
        private:
            std::unique_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
    };
}

#endif /* !MOUSESYSTEM_HPP_ */
