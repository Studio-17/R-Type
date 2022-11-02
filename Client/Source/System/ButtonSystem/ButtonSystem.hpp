/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** ButtonSystem
*/

#ifndef BUTTONSYSTEM_HPP_
    #define BUTTONSYSTEM_HPP_

    #include "Registry.hpp"
    #include "GraphicalLib.hpp"
    #include "CNetworkQueue.hpp"
    #include "CServerId.hpp"
    #include "CAsset.hpp"

/**
 * @brief System that handle the button load from json
 */
class ButtonSystem {
    public:
        ButtonSystem();
        ~ButtonSystem() = default;

        nlohmann::json getJsonData(std::string const &filepath);
        void loadButton(std::string const &filepath, [[ maybe_unused ]]Registry &registry, [[ maybe_unused ]]Sparse_array<component::casset_t> &assets);

        void operator()(Registry &registry,
                        Sparse_array<component::cnetwork_queue_t> &network,
                        Sparse_array<component::cserverid_t> &serverIds,
                        Sparse_array<component::casset_t> &assets);

    protected:
    private:
        std::unique_ptr<rtype::GraphicalLib> _graphicLib; ///< Graphical library
        std::vector<Position> _positions; ///< Position of the buttons
        std::vector<int> _textureId; ///< Texture id of the buttons
};

#endif /* !BUTTONSYSTEM_HPP_ */
