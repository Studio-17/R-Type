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
	#include "CPosition.hpp"
	// #include "CNetworkQueue.hpp"
	#include "CSceneId.hpp"
    #include "CRect.hpp"
    #include "CType.hpp"
    #include "Constant.hpp"

class MouseSystem {
    public:
        MouseSystem();
        ~MouseSystem() = default;

		void operator()(Registry &registry,
                        Sparse_array<component::cposition_t> &positions,
                        Sparse_array<component::crect_t> &rects,
                        Sparse_array<component::csceneid_t> &scenesId,
                        Sparse_array<component::ctype_t> &types);

    protected:
    private:
        std::unique_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
};

#endif /* !MOUSESYSTEM_HPP_ */
