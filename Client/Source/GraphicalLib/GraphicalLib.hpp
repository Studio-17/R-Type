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

/**
 * @brief rtype namespace
 * 
 */
namespace rtype {
    /**
     * @brief GraphicalLib class
     * 
     */
    class GraphicalLib : public IGraphicalLib {
        public:
            /**
             * @brief Construct a new Graphical Lib object
             * 
             * @param screenWidth 
             * @param screenHeight 
             * @param title 
             * @param framerate 
             */
            GraphicalLib(const int screenWidth, const int screenHeight, std::string title, const int framerate);
            /**
             * @brief Destroy the Graphical Lib object
             * 
             */
            ~GraphicalLib();

            /**
             * @brief Clear the window
             * 
             */
            void clearScreen() override;
            /**
             * @brief Start drawing in the window
             * 
             */
            void startDrawingWindow() override;
            /**
             * @brief Stop drawing in the window
             * 
             */
            void endDrawingWindow() override;

            /**
             * @brief Create a Sprite object
             * 
             * @param id id of the sprite
             * @param imagePath path of the image
             * @param position position of the sprite
             * @param size size of the sprite
             */
            void createSprite(std::size_t id, std::string const &imagePath, Position const &position, float const &size) override;
            /**
             * @brief Draw the sprite
             * 
             * @param id id of the sprite
             */
            void drawSprite(std::size_t id) override;

            /**
             * @brief Set the Sprite Position object
             * 
             * @param id id of the sprite
             * @param position the new position of the sprite
             */
            void setSpritePosition(std::size_t id, Position const &position) override;
            /**
             * @brief Get the Sprite Position object
             * 
             * @param id id of the sprite
             * @return Position of the sprite
             */
            Position getSpritePosition(std::size_t id) override;
            /**
             * @brief Set the Sprite Scale object
             * 
             * @param id id of the sprite
             * @param scale the new scale of the sprite
             */
            void setSpriteScale(std::size_t id, float scale) override;
            /**
             * @brief Set the Sprite Rotation object
             * 
             * @param id id of the sprite
             * @param rotation the new rotation of the sprite
             */
            void setSpriteRotation(std::size_t id, float rotation) override;
            /**
             * @brief Get the Sprite Rotation object
             * 
             * @param id id of the sprite
             * @return a float that corespond to the rotation of the sprite
             */
            float getSpriteRotation(std::size_t id) override;

            /**
             * @brief Create a Text object
             * 
             * @param id id of the text
             * @param filename path of the font
             * @param text the text to display
             * @param fontSize the size of the text
             * @param color the color of the text
             * @param position the position of the text
             */
            void createText(std::size_t id, std::string const &filename, std::string const &text, int fontSize, Color const &color, Position const &position) override;
            /**
             * @brief Draw the text
             * 
             * @param id id of the text
             */
            void drawText(std::size_t id) override;

            /**
             * @brief Set the Text Position object
             * 
             * @param id id of the text
             * @param position the new position of the text
             */
            void setTextPosition(std::size_t id, Position const &position) override;
            /**
             * @brief Get the Text Position object
             * 
             * @param id id of the text
             * @return Position of the text
             */
            Position getTextPosition(std::size_t id) override;

            /**
             * @brief Create a Sound object
             * 
             * @param id id of the sound
             * @param filename path of the sound
             */
            std::string getText(std::size_t id) override;
            /**
             * @brief Set the Text object
             * 
             * @param id id of the text
             * @param text the new text
             */
            void setText(std::size_t id, std::string const &text) override;

            /**
             * @brief Set the Text Color object
             * 
             * @param id id of the text
             * @param color the new color of the text
             */
            void setTextColor(std::size_t id, Color const &color) override;
            /**
             * @brief Set the Text Font Size object
             * 
             * @param id id of the text
             * @param fontSize the new size of the text
             */
            void setTextFontSize(std::size_t id, int fontSize) override;

            /**
             * @brief Create a Music object
             * 
             * @param id id of the music
             * @param filename path of the music
             */
            void createMusic(std::size_t id, std::string const &filename) override;
            /**
             * @brief Play the music
             * 
             * @param id id of the music
             */
            void playMusic(std::size_t id) override;
            /**
             * @brief Stop the music
             * 
             * @param id id of the music
             */
            void stopMusic(std::size_t id) override;
            /**
             * @brief Pause the music
             * 
             * @param id id of the music
             */
            void pauseMusic(std::size_t id) override;
            /**
             * @brief Resume the music
             * 
             * @param id id of the music
             */
            void resumeMusic(std::size_t id) override;

            /**
             * @brief Check if the music is playing
             * 
             * @param id id of the music
             * @return true if the music is playing
             * @return false if the music is not playing
             */
            bool isMusicPlaying(std::size_t id) override;
            /**
             * @brief Set the Music Volume object
             * 
             * @param id id of the music
             * @param volume the new volume of the music
             */
            void setMusicVolume(std::size_t id, float volume) override;
            /**
             * @brief Update the music stream
             * 
             * @param id id of the music
             */
            void updateMusicStream(std::size_t id) override;

            /**
             * @brief Create a Sound object
             * 
             * @param id id of the sound
             * @param filename path of the sound
             */
            void createSound(std::size_t id, std::string const &filename) override;
            /**
             * @brief Play the sound
             * 
             * @param id id of the sound
             */
            void playSound(std::size_t id) override;
            /**
             * @brief Stop the sound
             * 
             * @param id id of the sound
             */
            void stopSound(std::size_t id) override;
            /**
             * @brief Pause the sound
             * 
             * @param id id of the sound
             */
            void pauseSound(std::size_t id) override;
            /**
             * @brief Resume the sound
             * 
             * @param id id of the sound
             */
            void resumeSound(std::size_t id) override;

            /**
             * @brief Check if the sound is playing
             * 
             * @param id id of the sound
             * @return true if the sound is playing
             * @return false if the sound is not playing
             */
            bool isSoundPlaying(std::size_t id) override;
            /**
             * @brief Set the Sound Volume object
             * 
             * @param id id of the sound
             * @param volume the new volume of the sound
             */
            void setSoundVolume(std::size_t id, float volume) override;

        protected:
        private:

        std::map<std::size_t, std::shared_ptr<Sprite>> _spriteMap; ///< Map of all the sprites
        std::map<std::size_t, std::shared_ptr<Text>> _textMap; ///< Map of all the texts
        std::map<std::size_t, std::shared_ptr<MyMusic>> _musicMap; ///< Map of all the musics
        std::map<std::size_t, std::shared_ptr<MySound>> _soundMap; ///< Map of all the sounds
    };

}

#endif /* !GRAPHICALLIB_HPP_ */
