/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** GraphicalLib
*/

#ifndef GRAPHICALLIB_HPP_
#define GRAPHICALLIB_HPP_


#include <map>
#include <cstring>
#include <memory>
#include "IGraphicalLib.hpp"

namespace rtype {

    class GraphicalLib : public IGraphicalLib {
        public:
            GraphicalLib(const int screenWidth, const int screenHeight, std::string title, const int framerate);
            ~GraphicalLib();

            //Useful functions
            void clearScreen() override; // Clear the screen
            void startDrawingWindow() override; // Start drawing on the window
            void endDrawingWindow() override; // End drawing on the window

            // Sprites
            void createSprite(std::size_t id, std::string const &imagePath, Position const &position, float const &size) override;
            void drawSprite(std::size_t id) override;

            void setSpritePosition(std::size_t id, Position const &position) override;
            Position getSpritePosition(std::size_t id) override;
            void setSpriteScale(std::size_t id, float scale) override;
            void setSpriteRotation(std::size_t id, float rotation) override;
            float getSpriteRotation(std::size_t id) override;

            // Texts
            void createText(std::size_t id, std::string const &filename, std::string const &text, int fontSize, Color const &color, Position const &position) override;
            void drawText(std::size_t id) override;

            void setTextPosition(std::size_t id, Position const &position) override;
            Position getTextPosition(std::size_t id) override;

            std::string getText(std::size_t id) override;
            void setText(std::size_t id, std::string const &text) override;

            void setTextColor(std::size_t id, Color const &color) override;
            void setTextFontSize(std::size_t id, int fontSize) override;

            //Musics
            void createMusic(std::size_t id, std::string const &filename) override;
            void playMusic(std::size_t id) override;
            void stopMusic(std::size_t id) override;
            void pauseMusic(std::size_t id) override;
            void resumeMusic(std::size_t id) override;

            bool isMusicPlaying(std::size_t id) override;
            void setMusicVolume(std::size_t id, float volume) override;
            void updateMusicStream(std::size_t id) override;

            //Sounds
            void createSound(std::size_t id, std::string const &filename) override;
            void playSound(std::size_t id) override;
            void stopSound(std::size_t id) override;
            void pauseSound(std::size_t id) override;
            void resumeSound(std::size_t id) override;
            bool isSoundPlaying(std::size_t id) override;
            void setSoundVolume(std::size_t id, float volume) override;

        protected:
        private:

        std::map<std::size_t, std::shared_ptr<Sprite>> _spriteMap;
        std::map<std::size_t, std::shared_ptr<Text>> _textMap;
        std::map<std::size_t, std::shared_ptr<MyMusic>> _musicMap;
        std::map<std::size_t, std::shared_ptr<MySound>> _soundMap;
    };

}

#endif /* !GRAPHICALLIB_HPP_ */
