/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** IGraphicalLib
*/

#ifndef IGRAPHICALLIB_HPP_
#define IGRAPHICALLIB_HPP_

#include "Sprite.hpp"
#include "Text.hpp"
#include "Sound.hpp"
#include "Music.hpp"
#include <iostream>

namespace rtype {
    class IGraphicalLib {
        public:
            IGraphicalLib();
            ~IGraphicalLib();

            // Sprites
            virtual auto createSprite(std::size_t id, std::string const &imagePath, Position const &position, float const &size) -> void = 0;
            virtual auto drawSprite(std::size_t id) -> void = 0;

            virtual auto setSpritePosition(std::size_t id, Position const &position) -> void = 0;
            virtual auto setSpriteScale(std::size_t id, float scale) -> void = 0;
            virtual auto getSpritePosition(std::size_t id) -> Position = 0;
            virtual auto setSpriteRotation(std::size_t id, float rotation) -> void = 0;
            virtual auto getSpriteRotation(std::size_t id) -> float = 0;

            // Texts
            virtual auto createText(std::size_t id, std::string const &filename, std::string const &text, int fontSize, Color const &color, Position const &position) -> void = 0;
            virtual auto drawText(std::size_t id) -> void = 0;

            virtual auto setTextPosition(Position const &position) -> void = 0;
            virtual auto getTextPosition() -> Position = 0;

            virtual auto drawTextFramePerSeconds(Position const &position) -> void = 0;

            virtual auto getText() -> std::string = 0;
            virtual auto setText(std::string const &text) -> void = 0;

            virtual auto setTextColor(Color const &color) -> void = 0;
            virtual auto setTextFontSize(int fontSize) -> void = 0;

            //Musics
            virtual auto createMusic(std::size_t id, std::string const &filename) -> void = 0;
            virtual auto playMusic(std::size_t id) -> void = 0;
            virtual auto stopMusic(std::size_t id) -> void = 0;
            virtual auto pauseMusic(std::size_t id) -> void = 0;
            virtual auto resumeMusic(std::size_t id) -> void = 0;

            virtual auto isMusicPlaying() -> void = 0;
            virtual auto setMusicVolume(float volume) -> void = 0;
            virtual auto updateMusicStream() -> void = 0;

            //Sounds
            virtual auto createSound(std::size_t id, std::string const &filename) -> void = 0;
            virtual auto playSound(std::size_t id) -> void = 0;
            virtual auto stopSound(std::size_t id) -> void = 0;
            virtual auto pauseSound(std::size_t id) -> void = 0;
            virtual auto resumeSound(std::size_t id) -> void = 0;
            virtual auto isSoundPlaying() -> void = 0;
            virtual auto setSoundVolume(float volume) -> void = 0;

        protected:
        private:

    };
}

#endif /* !IGRAPHICALLIB_HPP_ */
