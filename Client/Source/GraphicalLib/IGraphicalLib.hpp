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

    // #include "MyText.hpp"
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
             * @brief Clear the window
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
             * @param position 
             * @param x 
             * @param y 
             * @param height 
             * @param width 
             * @return true 
             * @return false 
             */
            virtual auto checkMouseCollision(Position const &position, float const &x, float const &y, float const &height, float const &width) -> bool = 0;

            /**
             * @brief 
             * 
             * @return true 
             * @return false 
             */
            virtual auto IsLeftMouseButtonPressed() -> bool = 0;

            virtual auto IsLeftMouseButtonReleased() -> bool = 0;

            /**
             * @brief Get the Mouse Position object
             * 
             * @return Position 
             */
            virtual auto getMousePosition() -> Position = 0;

            virtual auto drawText(std::string const &text, Position const &pos, std::size_t const &fontSize, std::array<float, 4> const &color) -> void = 0;

            virtual auto createColor(std::array<float, 4> const &array) -> Color = 0;

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
