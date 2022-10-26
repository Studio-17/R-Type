/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** IGraphicalLib
*/

#ifndef IGRAPHICALLIB_HPP_
#define IGRAPHICALLIB_HPP_

#include <iostream>
#include <memory>

#include "raylib.h"
#include "Sprite.hpp"
#include "Text.hpp"
#include "MySound.hpp"
#include "MyMusic.hpp"
#include "Keyboard.hpp"
#include "Datas/Position/Position.hpp"

/**
 * @brief rtype namespace
 * 
 */
namespace rtype {
    /**
     * @brief IGraphicalLib class
     * 
     */
    class IGraphicalLib {
        public:
            // /**
            //  * @brief Construct a new IGraphicalLib object
            //  * 
            //  */
            // IGraphicalLib();
            /**
             * @brief Destroy the IGraphicalLib object
             * 
             */
            virtual ~IGraphicalLib() = default;

            /**
             * @brief Clear the window
             * 
             */

            virtual auto initWindow(const int screenWidth, const int screenHeight, std::string title, const int framerate) -> void = 0;

            /**
             * @brief A method to close the window
             * 
             */
            virtual auto closeWindow() -> void = 0;

            /**
             * @brief A method to clear the window
             * 
             */
            virtual auto clearScreen() -> void = 0;
            /**
             * @brief Start drawing in the window
             * 
             */
            virtual auto startDrawingWindow() -> void = 0;
            /**
             * @brief Stop drawing in the window
             * 
             */
            virtual auto endDrawingWindow() -> void = 0;

            /**
             * @brief Check if window should close
             * 
             * @return true
             * @return false
             */
            virtual auto windowShouldClose() -> bool = 0;

            /**
             * @brief Create a Sprite object
             * 
             * @param id id of the sprite
             * @param imagePath path to the image
             * @param position position of the sprite
             * @param size size of the sprite
             */
            virtual auto createSprite(std::string const &imagePath, float const &size, Rectangle const &rect) -> std::shared_ptr<Sprite> = 0;
            /**
             * @brief Draw a sprite
             * 
             * @param id id of the sprite
             */

            virtual auto drawSprite(std::shared_ptr<Sprite> const &sprite, Position const &position, Rectangle const &rect) -> void = 0;
            virtual auto destroySprite(std::shared_ptr<Sprite> sprite) -> void = 0;

            /**
             * @brief Set the Sprite Position object
             * 
             * @param id id of the sprite
             * @param position position of the sprite
             */
            virtual auto setSpritePosition(Sprite &sprite, Position const &position) -> void = 0;
            /**
             * @brief Set the Sprite Scale object
             * 
             * @param id id of the sprite
             * @param scale scale of the sprite
             */
            virtual auto setSpriteScale(Sprite &sprite, float scale) -> void = 0;
            /**
             * @brief Get the Sprite Position object
             * 
             * @param id id of the sprite
             * @return the Position of the sprite
             */
            virtual auto getSpritePosition(Sprite const &sprite) -> Position = 0;
            /**
             * @brief Set the Sprite Rotation object
             * 
             * @param id id of the sprite
             * @param rotation rotation of the sprite
             */
            virtual auto setSpriteRotation(Sprite &sprite, float rotation) -> void = 0;
            /**
             * @brief Get the Sprite Rotation object
             * 
             * @param id id of the sprite
             * @return float rotation of the sprite
             */
            virtual auto getSpriteRotation(Sprite const &sprite) -> float = 0;

            /**
             * @brief 
             * 
             * @param sprite1 rect of the first sprite
             * @param sprite2 rect of the second sprite
             * @return true if the two sprites are colliding
             * @return false if the two sprites are not colliding
             */
            virtual auto checkCollisions(Sprite const &sprite1, Sprite const &sprite2) -> bool = 0;

            /**
             * @brief Create a Text object
             * 
             * @param id id of the text
             * @param filename path to the font
             * @param text text to display
             * @param fontSize size of the text
             * @param color color of the text
             * @param position position of the text
             */
            virtual auto createText(std::size_t id, std::string const &filename, std::string const &text, int fontSize, Color const &color, Position const &position) -> void = 0;
            /**
             * @brief Draw a text
             * 
             * @param id id of the text
             */
            virtual auto drawText(std::size_t id) -> void = 0;

            /**
             * @brief Set the Text Position object
             * 
             * @param id id of the text
             * @param position position of the text
             */
            virtual auto setTextPosition(std::size_t id, Position const &position) -> void = 0;
            /**
             * @brief Get the Text Position object
             * 
             * @param id id of the text
             * @return Position of the text
             */
            virtual auto getTextPosition(std::size_t id) -> Position = 0;

            /**
             * @brief Get the Text content object
             * 
             * @param id id of the text
             * @return std::string content of the text
             */
            virtual auto getText(std::size_t id) -> std::string = 0;
            /**
             * @brief Set the Text content object
             * 
             * @param id id of the text
             * @param text new content of the text
             */
            virtual auto setText(std::size_t id, std::string const &text) -> void = 0;

            /**
             * @brief Set the Text Color object
             * 
             * @param id id of the text
             * @param color new color of the text
             */
            virtual auto setTextColor(std::size_t id, Color const &color) -> void = 0;
            /**
             * @brief Set the Text Font Size object
             * 
             * @param id id of the text
             * @param fontSize new size of the text
             */
            virtual auto setTextFontSize(std::size_t id, int fontSize) -> void = 0;

            /**
             * @brief Create a Music object
             * 
             * @param id id of the music
             * @param filename path to the music
             */
            virtual auto createMusic(std::size_t id, std::string const &filename) -> void = 0;
            /**
             * @brief Play a music
             * 
             * @param id id of the music
             */
            virtual auto playMusic(std::size_t id) -> void = 0;
            /**
             * @brief Stop a music
             * 
             * @param id id of the music
             */
            virtual auto stopMusic(std::size_t id) -> void = 0;
            /**
             * @brief Pause a music
             * 
             * @param id id of the music
             */
            virtual auto pauseMusic(std::size_t id) -> void = 0;
            /**
             * @brief Resume a music
             * 
             * @param id id of the music
             */
            virtual auto resumeMusic(std::size_t id) -> void = 0;

            /**
             * @brief Check if the music is playing
             * 
             * @param id id of the music
             * @return true if the music is playing
             * @return false if the music is not playing
             */
            virtual auto isMusicPlaying(std::size_t id) -> bool = 0;
            /**
             * @brief Set the Music Volume object
             * 
             * @param id id of the music
             * @param volume new volume of the music
             */
            virtual auto setMusicVolume(std::size_t id, float volume) -> void = 0;
            /**
             * @brief Update the music stream
             * 
             * @param id id of the music
             */
            virtual auto updateMusicStream(std::size_t id) -> void = 0;

            /**
             * @brief Create a Sound object
             * 
             * @param id id of the sound
             * @param filename path to the sound
             */
            virtual auto createSound(std::size_t id, std::string const &filename) -> void = 0;
            /**
             * @brief Play a sound
             * 
             * @param id id of the sound
             */
            virtual auto playSound(std::size_t id) -> void = 0;
            /**
             * @brief Stop a sound
             * 
             * @param id id of the sound
             */
            virtual auto stopSound(std::size_t id) -> void = 0;
            /**
             * @brief Pause a sound
             * 
             * @param id id of the sound
             */
            virtual auto pauseSound(std::size_t id) -> void = 0;
            /**
             * @brief Resume a sound
             * 
             * @param id id of the sound
             */
            virtual auto resumeSound(std::size_t id) -> void = 0;
            /**
             * @brief Check if the sound is playing
             * 
             * @param id id of the sound
             * @return true if the sound is playing
             * @return false if the sound is not playing
             */
            virtual auto isSoundPlaying(std::size_t id) -> bool = 0;
            /**
             * @brief Set the Sound Volume object
             * 
             * @param id id of the sound
             * @param volume new volume of the sound
             */ virtual auto setSoundVolume(std::size_t id, float volume) -> void = 0;

            /**
             * @brief Check if a key has been pressed
             *
             * @param key
             * @return true
             * @return false
             */
            virtual auto hasBeenPressed(int key) -> bool = 0;
            /**
             * @brief Check if a key is being pressed
             *
             * @param key
             * @return true
             * @return false
             */
            virtual auto isBeingPressed(int key) -> bool = 0;
            /**
             * @brief Check if a key has been released
             *
             * @param key
             * @return true
             * @return false
             */
            virtual auto hasBeenReleased(int key) -> bool = 0;
            /**
             * @brief Check if a key is not being pressed
             *
             * @param key
             * @return true
             * @return false
             */
            virtual auto isNotBeingPressed(int key) -> bool = 0;
            /**
             * @brief Set the Exit Key object
             *
             * @param key
             */
            virtual auto setExitKey(int key) -> void = 0;
            /**
             * @brief Get the Pressed Keycode object
             *
             * @return int
             */
            virtual auto getPressedKeycode() -> int = 0;
            /**
             * @brief Get the Pressed Charcode object
             *
             * @return int
             */
            virtual auto getPressedCharcode() -> int = 0;


        protected:
        private:

    };
}

#endif /* !IGRAPHICALLIB_HPP_ */
