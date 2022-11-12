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
             * @param screenWidth 
             * @param screenHeight 
             * @param title 
             * @param framerate 
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
             * @param screenWidth 
             * @param screenHeight 
             * @param title 
             * @param framerate 
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

            void drawSprite(MyTexture const &texture, std::array<float, 4> const &rectSource, std::array<float, 4> const &rectDest, std::pair<float, float> const &origin, float const &rotation, float const &scale) override;

            bool checkMouseCollision(Position const &position, float const &x, float const &y, float const &height, float const &width) override;

            bool IsLeftMouseButtonPressed() override;

            bool IsLeftMouseButtonReleased() override;

            Position getMousePosition() override;

            Color createColor(std::array<float, 4> const &array) override;

            void drawText(std::string const &text, Position const &pos, std::size_t const &fontSize, std::array<float, 4> const &color) override;

            void initAudio() override;

            void closeAudio() override;

            void playASound(MySound &sound) override;

            void playAMusic(MyMusic &music) override;

            void updateAMusic(MyMusic &music) override;

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

        std::shared_ptr<Keyboard> _keyboard; ///< Keyboard object
    };

}

#endif /* !GRAPHICALLIB_HPP_ */
