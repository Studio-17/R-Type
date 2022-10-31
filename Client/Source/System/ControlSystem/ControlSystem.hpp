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
	#include "CSceneId.hpp"

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
		 * @param registry the registry of the server
		 * @param keyboards the sparse array of keyboard entities
		 * @param network the sparse array of network entities
		 * @param idOfShip the sparse array of idOfShip entities
		 * @param scenesId the sparse array of scenesId entities
		 */
		void operator()(Registry &registry, Sparse_array<component::ckeyboard_t> &keyboards, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cid_of_ship_t> &idOfShip, Sparse_array<component::csceneid_t> &scenesId);

		/**
		 * @brief A method to add a task for the server through the network queue
		 * 
		 * @param x The x position of the task
		 * @param y The y position of the task
		 * @param network network queue
		 * @param idOfShip id of the ship
		 */
		void addToNetworkQueue(float x, float y, Sparse_array<component::cnetwork_queue_t> &network, uint16_t idOfShip);

	protected:
	private:
		std::unique_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
};


#endif //R_TYPE_CONTROLSYSTEM_H
