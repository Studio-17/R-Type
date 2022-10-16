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
	#include "CVelocity.hpp"
	#include "CKeyboard.hpp"
	#include "CNetworkQueue.hpp"
	#include "CServerId.hpp"
	#include "CIdOfShip.hpp"

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
		void operator()(Registry &registry, Sparse_array<component::cposition_t> &positions, Sparse_array<component::cvelocity_t> &velocities, Sparse_array<component::ckeyboard_t> &keyboards, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cid_of_ship_t> &idOfShip);
		
		/**
		 * @brief A method to add a task for the server through the network queue
		 * 
		 * @param x 
		 * @param y 
		 * @param network 
		 * @param idOfShip 
		 */
		void addToNetworkQueue(uint16_t x, uint16_t y, Sparse_array<component::cnetwork_queue_t> &network, uint16_t idOfShip);


	protected:
	private:
		std::unique_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
};


#endif //R_TYPE_CONTROLSYSTEM_H
