/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** ParallaxSystem
*/

#ifndef PARALLAXSYSTEM_HPP_
    #define PARALLAXSYSTEM_HPP_

    #include <vector>

    /* Ecs */
    #include "Registry.hpp"

    /* Component */
    #include "Component/CPosition.hpp"
    #include "Component/CRef.hpp"

/**
 * @brief Namespace for systems
 */
namespace System {
    /**
     * @brief ParallaxSystem class that handles the parallax effect
     */
    class ParallaxSystem {
        public:
            ParallaxSystem();
            ~ParallaxSystem() = default;

            void operator()(
                Registry &registry,
                Sparse_array<component::cref_t> &refs,
                Sparse_array<component::cposition_t> &positions
            );

        protected:
        private:
            std::vector<std::string> _parallax;
    };
}
#endif /* !PARALLAXSYSTEM_HPP_ */
