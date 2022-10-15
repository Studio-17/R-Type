/*
** EPITECH PROJECT, 2020
** ControlSystem.h
** File description:
** header for ControlSystem.c
*/

#ifndef R_TYPE_CONTROLSYSTEM_H
	#define R_TYPE_CONTROLSYSTEM_H


	#include "Registry.hpp"
    #include "GraphicalLib.hpp"
	#include "CPosition.hpp"
	#include "Velocity.hpp"
	#include "CKeyboard.hpp"
	#include "CNetworkQueue.hpp"

/**
 * @brief ControlSystem class that handles the control of all the entities
 *
 */
class ControlSystem {
	public:
		/**
		 * @brief Construct a new Control System object
		 *
		 */
		ControlSystem();
		/**
		 * @brief Destroy the Control System object
		 *
		 */
		~ControlSystem() = default;

		/**
		 * @brief Function that will be automaticaly called while the client is working (on loop)
		 *
		 * @param registry The registry that contains all the ECS
		 * @param positions Sparse array of all position component of all entities
		 * @param velocities Sparse array of all velocity component of all entities
		 */
		void operator()(Registry &registry, Sparse_array<component::cposition_t> &positions, Sparse_array<component::velocity_t> &velocities, Sparse_array<component::ckeyboard_t> &keyboards, Sparse_array<component::cnetwork_queue_t> &network);
		void addToNetworkQueue(int x, int y, Sparse_array<component::cnetwork_queue_t> &network);


	protected:
	private:
		std::unique_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
};


#endif //R_TYPE_CONTROLSYSTEM_H
