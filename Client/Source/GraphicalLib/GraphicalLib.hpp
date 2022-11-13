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
#include <string>
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
             */
            GraphicalLib();
            /**
             * @brief Destroy the Graphical Lib object
             *
             */
            ~GraphicalLib();

            /**
             * @brief A method to initialize a window object
             *
             * @param screenWidth width of the window
             * @param screenHeight height of the window
             * @param title title of the window
             * @param framerate framerate of the window
             */
            void initWindow(const int screenWidth, const int screenHeight, std::string title, const int framerate) override;

            /**
             * @brief A method to close a window
             *
             */
            void closeWindow() override;

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
             * @brief Check if the window should close
             *
             * @return true
             * @return false
             */
            bool windowShouldClose() override;

            /**
             * @brief A method to draw a sprite
             *
             * @param texture texture of the sprite
             * @param rectSource rectangle source of the sprite
             * @param rectDest rectangle destination of the sprite
             * @param origin origin of the sprite
             * @param rotation rotation of the sprite
             * @param scale scale of the sprite
             */
            void drawSprite(MyTexture const &texture, std::array<float, 4> const &rectSource, std::array<float, 4> const &rectDest, std::pair<float, float> const &origin, float const &rotation, float const &scale) override;
            /**
             * @brief A method to check a collison between the mouse and a rectangle
             *
             * @param position position of the mouse
             * @param x x position of the rectangle
             * @param y y position of the rectangle
             * @param height height of the rectangle
             * @param width width of the rectangle
             * @return true returns true if there is a collision
             * @return false returns false if there is no collision
             */
            bool checkMouseCollision(Position const &position, float const &x, float const &y, float const &height, float const &width) override;
            /**
             * @brief A method to check if the left mouse button is pressed
             *
             * @return true returns true if the left mouse button is pressed
             * @return false returns false if the left mouse button is not pressed
             */
            bool IsLeftMouseButtonPressed() override;
            /**
             * @brief A method to check if the left mouse button is released
             *
             * @return true returns true if the left mouse button is released
             * @return false returns false if the left mouse button is not released
             */
            bool IsLeftMouseButtonReleased() override;
            /**
             * @brief Get the Mouse Position object
             *
             * @return Position
             */
            Position getMousePosition() override;
            /**
             * @brief Create a Color object
             *
             * @param array correspond to the red, green, blue and alpha values
             * @return Color return the color created
             */
            Color createColor(std::array<float, 4> const &array) override;
            /**
             * @brief A method to draw a text
             *
             * @param text text to draw
             * @param pos position of the text
             * @param fontSize size of the text
             * @param color color of the text
             */
            void drawText(std::string const &text, Position const &pos, std::size_t const &fontSize, std::array<float, 4> const &color) override;
            /**
             * @brief A method to init the audio devide
             *
             */
            void initAudio() override;
            /**
             * @brief A method to close the audio device
             *
             */
            void closeAudio() override;
            /**
             * @brief A method to play a sound
             *
             * @param sound sound to play
             */
            void playASound(MySound &sound) override;
            /**
             * @brief Play a sound with a multichannel buffer pool
             * 
             * @param sound Sound to play
             */
            void playASoundMulti(MySound &sound) override;
            /**
             * @brief A method to load a sound
             *
             * @param music music to load
             */
            void playAMusic(MyMusic &music) override;
            /**
             * @brief A method to update the music
             *
             * @param music music to update
             */
            void updateAMusic(MyMusic &music) override;

            float getMusicVolume(MyMusic &music) override;
            void setMusicVolume(MyMusic &music, float volume) override;

            /**
             * @brief Check if a key has been pressed
             *
             * @param key
             * @return true
             * @return false
             */
            bool hasBeenPressed(int key) override;
            /**
             * @brief Check if a key is being pressed
             *
             * @param key
             * @return true
             * @return false
             */
            bool isBeingPressed(int key) override;
            /**
             * @brief Check if a key has been released
             *
             * @param key
             * @return true
             * @return false
             */
            bool hasBeenReleased(int key) override;
            /**
             * @brief Check if a key is not being pressed
             *
             * @param key
             * @return true
             * @return false
             */
            bool isNotBeingPressed(int key) override;
            /**
             * @brief Set the Exit Key object
             *
             * @param key
             */
            void setExitKey(int key) override;
            /**
             * @brief Get the Pressed Keycode object
             *
             * @return int
             */
            int getPressedKeycode() override;
            /**
             * @brief Get the Pressed Charcode object
             *
             * @return int
             */
            int getPressedCharcode() override;


        protected:
        private:

    };

}

#endif /* !GRAPHICALLIB_HPP_ */
