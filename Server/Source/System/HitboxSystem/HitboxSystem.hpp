/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** HitboxSystem
*/

#ifndef HITBOXSYSTEM_HPP_
    #define HITBOXSYSTEM_HPP_

    #include "Registry.hpp"
    #include "CType.hpp"
    #include "CPosition.hpp"
    #include "CRect.hpp"
    #include "CNetworkQueue.hpp"

/**
 * @brief Namespace for systems
 * 
 */
namespace systemNamespace {
    /**
     * @brief System in charge of all the hitboxes
     * 
     */
    class HitboxSystem {
        public:
            /**
             * @brief Construct a new Hitbox System object
             * 
             */
            HitboxSystem();
            /**
             * @brief Destroy the Event System object
             * 
             */
            ~HitboxSystem() = default;

            /**
             * @brief 
             * 
             * @param rec1 
             * @param rec2 
             * @param pos1 
             * @param pos2 
             * @return true 
             * @return false 
             */
            bool CheckCollision(std::optional<component::crect_t> &rec1, std::optional<component::crect_t> &rec2, std::optional<component::cposition_t> &pos1, std::optional<component::cposition_t> &pos2);

            /**
             * @brief 
             * 
             * @param registry The registry that contains all the ECS
             * @param types Sparse array of all type component of all entities
             * @param positions Sparse array of all position component of all entities
             * @param rects Sparse array of all rect component of all entities
             * @param network_queues Sparse array of all network queue component of all entities
             * @param server_ids Sparse array of all server id component of all entities
             */
            void operator()(Registry &registry, Sparse_array<component::ctype_t> &types,
                                                Sparse_array<component::cposition_t> &positions,
                                                Sparse_array<component::crect_t> &rects,
                                                Sparse_array<component::cnetwork_queue_t> &network_queues);


        protected:
        private:
    };
};

#endif /* !HITBOXSYSTEM_HPP_ */
