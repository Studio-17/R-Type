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
    #include <utility>
    #include <raylib.h>

    #include "MySound.hpp"
    #include "MyMusic.hpp"
    #include "MyTexture.hpp"
    #include "Keyboard.hpp"
    #include "Position.hpp"

/**
 * @brief rtype namespace
 */
namespace rtype {
    /**
     * @brief IGraphicalLib class
     */
    class IGraphicalLib {
        public:
            /**
             * @brief Destroy the IGraphicalLib object
             */
            virtual ~IGraphicalLib() = default;

            /**
             * @brief A method to initialize a window object
             *
             * @param screenWidth width of the window
             * @param screenHeight height of the window
             * @param title title of the window
             * @param framerate framerate of the window
             */
            virtual auto initWindow(const int screenWidth, const int screenHeight, std::string title, const int framerate) -> void = 0;

            /**
             * @brief A method to close the window
             */
            virtual auto closeWindow() -> void = 0;

            /**
             * @brief A method to clear the window
             */

            virtual auto clearScreen() -> void = 0;

            /**
             * @brief Start drawing in the window
             */
            virtual auto startDrawingWindow() -> void = 0;

            /**
             * @brief Stop drawing in the window
             */
            virtual auto endDrawingWindow() -> void = 0;

            /**
             * @brief Check if window should close
             *
             * @return true If window should close
             * @return false If window shouldn't close
             */
            virtual auto windowShouldClose() -> bool = 0;

            /**
             * @brief Draw a sprite
             *
             * @param texture Texture to draw
             * @param rectSource Array containing Rect source data with height, width, x and y
             * @param rectDest Array containing Rect destination data with height, width, x and y
             * @param origin Position of origin
             * @param rotation Rotation of the sprite
             * @param scale Scale of the sprite
             */
            virtual auto drawSprite(MyTexture const &texture, std::array<float, 4> const &rectSource, std::array<float, 4> const &rectDest, std::pair<float, float> const &origin, float const &rotation, float const &scale) -> void = 0;

            /**
             * @brief Check the mouse collision
             *
             * @param position Position of the mouse
             * @param x X position of the rectangle
             * @param y Y position of the rectangle
             * @param height Height of the rectangle
             * @param width Width of the rectangle
             * @return true If there is a collision
             * @return false If there is no collision
             */
            virtual auto checkMouseCollision(Position const &position, float const &x, float const &y, float const &height, float const &width) -> bool = 0;

            /**
             * @brief Check if the left mouse button is pressed
             *
             * @return true If the left mouse button is pressed
             * @return false If the left mouse button is not pressed
             */
            virtual auto IsLeftMouseButtonPressed() -> bool = 0;
            /**
             * @brief Check if the left mouse button is released
             *
             * @return true If the left mouse button is released
             * @return false If the left mouse button is not released
             */
            virtual auto IsLeftMouseButtonReleased() -> bool = 0;

            /**
             * @brief Get the Mouse Position object
             *
             * @return Position The mouse position
             */
            virtual auto getMousePosition() -> Position = 0;
            /**
             * @brief Draw a text
             *
             * @param text Text to draw
             * @param pos Position of the text
             * @param fontSize Font size of the text
             * @param color Color of the text
             */
            virtual auto drawText(std::string const &text, Position const &pos, std::size_t const &fontSize, std::array<float, 4> const &color) -> void = 0;
            /**
             * @brief Create a Color object
             *
             * @param array Array containing RGBA values
             * @return Color The color
             */
            virtual auto createColor(std::array<float, 4> const &array) -> Color = 0;
            /**
             * @brief Init the audio device
             *
             */
            virtual auto initAudio() -> void = 0;
            /**
             * @brief Close the audio device
             *
             */
            virtual auto closeAudio() -> void = 0;
            /**
             * @brief Play a sound
             *
             * @param sound Sound to play
             */
            virtual auto playASound(MySound &sound) -> void = 0;
            /**
             * @brief Play a sound with a multichannel buffer pool
             * 
             * @param sound Sound to play
             */
            virtual auto playASoundMulti(MySound &sound) -> void = 0;
            /**
             * @brief Play a music
             *
             * @param music Music to play
             */
            virtual auto playAMusic(MyMusic &music) -> void = 0;
            /**
             * @brief Update the music
             *
             * @param music Music to update
             */
            virtual auto updateAMusic(MyMusic &music) -> void = 0;

            virtual auto getMusicVolume(MyMusic &music) -> float = 0;
            virtual auto setMusicVolume(MyMusic &music, float volume) -> void = 0;

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
