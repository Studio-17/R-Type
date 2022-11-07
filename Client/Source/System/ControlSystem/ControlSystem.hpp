/*
** EPITECH PROJECT, 2020
** ControlSystem.h
** File description:
** header for ControlSystem.c
*/

#ifndef R_TYPE_CONTROLSYSTEM_H
	#define R_TYPE_CONTROLSYSTEM_H


	#include "Registry.hpp"

	/* Component */
	#include "Component/CKeyboard.hpp"
	#include "Component/CNetworkQueue.hpp"
	#include "Component/CIdOfShip.hpp"
	#include "Component/CSceneId.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
	/**
	 * @brief ControlSystem class that handles the control of all the entities
	 */
	class ControlSystem {
		public:
			/**
			 * @brief Construct a new Control System object
			 */
			ControlSystem();
			~ControlSystem() = default;

			/**
			 * @brief Function that will be automaticaly called while the client is working (on loop)
			 *
			 * @param registry The registry of the server
			 * @param keyboards The sparse array of keyboard entities
			 * @param network The sparse array of network entities
			 * @param idOfShip The sparse array of idOfShip entities
			 * @param scenesId The sparse array of scenesId entities
			 */
			void operator()(Registry &registry, Sparse_array<component::ckeyboard_t> &keyboards, Sparse_array<component::cnetwork_queue_t> &network, Sparse_array<component::cid_of_ship_t> &idOfShip, Sparse_array<component::csceneid_t> &scenesId);

			/**
			 * @brief A method to add a task for the server through the network queue
			 *
			 * @param x The x position of the task
			 * @param y The y position of the task
			 * @param network The sparse array of network entitiies
			 * @param idOfShip The sparse array of id of the ship entities
			 */
			void addToNetworkQueue(float x, float y, Sparse_array<component::cnetwork_queue_t> &network, uint16_t idOfShip);

		protected:
		private:
	};
}

#endif //R_TYPE_CONTROLSYSTEM_H
