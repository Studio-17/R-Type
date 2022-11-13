/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** EndGameSystem
*/

#ifndef ENDGAMESYSTEM_HPP_
    #define ENDGAMESYSTEM_HPP_

    #include "Registry.hpp"

    /* Component */
    #include "Component/CNetworkQueue.hpp"
    #include "Component/CSceneId.hpp"
    #include "Component/CRef.hpp"
    #include "Component/CText.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief The End Game System class, it handles the end of the game of lobbies
     */
    class EndGameSystem {
        public:
            /**
             * @brief Construct a new End Game System object
             */
            EndGameSystem();
            ~EndGameSystem() = default;

            /**
             * @brief The main handler for the End Game System
             *
             * @param registry The registry that contains all the ECS
             * @param network_queues The sparse array of network entities
             * @param type The Sparse array of type of entities
             * @param lobbyIds The Sparse array of lobby id of entities
             */
            void operator()(Registry &registry,
                            Sparse_array<component::cnetwork_queue_t> &network_queues,
                            Sparse_array<component::csceneid_t> &sceneId,
                            Sparse_array<component::cref_t> &refs,
                            Sparse_array<component::ctext_t> &texts);

        protected:
        private:
    };
}

#endif /* !ENDGAMESYSTEM_HPP_ */
