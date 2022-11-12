/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Keyboard
*/

#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

    #include <raylib.h>

    #include <utility>
    #include <map>

/**
 * @brief Keyboard class that handles inputs from computer keyboards
 *
 */
class Keyboard {
    public:
        /**
         * @brief Construct a new Keyboard object
         *
         */
        Keyboard();

        /**
         * @brief Destroy the Keyboard object
         *
         */
        ~Keyboard();

        /**
         * @brief Get the Key value
         *
         * @return int key value
         */
        int getKey() const;
        /**
         * @brief Check if a key has been pressed
         *
         * @param key key to check
         * @return true
         * @return false
         */
        bool hasBeenPressed(int key) const;
        /**
         * @brief Check if a key is being pressed
         *
         * @param key key to check
         * @return true
         * @return false
         */
        bool isBeingPressed(int key) const;
        /**
         * @brief Check if a key has been released
         *
         * @param key key to check
         * @return true
         * @return false
         */
        bool hasBeenReleased(int key) const;
        /**
         * @brief Check if a key is not being pressed
         *
         * @param key key to check
         * @return true
         * @return false
         */
        bool isNotBeingPressed(int key) const;
        /**
         * @brief Set the Exit Key object
         *
         * @param key key to set
         */
        void setExitKey(int key);
        /**
         * @brief Get the Pressed Keycode object
         *
         * @return int keycode
         */
        int getPressedKeycode() const;
        /**
         * @brief Get the Pressed Charcode object
         *
         * @return int charcode
         */
        int getPressedCharcode() const;
        /**
         * @brief Get the Key Up Char Code object
         *
         * @return int charcode
         */
        int getKeyUpCharCode() const;
        /**
         * @brief Get the Key Down Key Code object
         *
         * @return int charcode
         */
        int getKeyDownCharCode() const;
        /**
         * @brief Get the Key Down Char Code object
         *
         * @return int charcode
         */
        int getKeyRightCharCode() const;
        /**
         * @brief Get the Key Left Key Code object
         *
         * @return int charcode
         */
        int getKeyLeftCharCode() const;
        /**
         * @brief Get the Key Space Char Code object
         *
         * @return int charcode
         */
        int getKeySpaceCharCode() const;

        /**
         * @brief Get the Key Enter Char Code object
         *
         * @return int charcode
         */
        int getKeyEnterCharCode() const;
        /**
         * @brief Get the Key S Char Code object
         *
         * @return int charcode
         */
        int getKeySCharCode() const;
        /**
         * @brief Get the Key D Char Code object
         *
         * @return int charcode
         */
        int getKeyDCharCode() const;


        /**
         * @brief Get the Keys Pressed object
         *
         * @tparam ENUM
         * @param map
         * @return std::map<ENUM, bool>
         */
        template<typename ENUM>
        std::map<ENUM, bool> getKeysPressed(std::map<ENUM, int> map) const
        {
            std::map<ENUM, bool> actionPressed;
            for (auto &[action, key] : map)
                actionPressed.emplace(action, isBeingPressed(key));
            return actionPressed;
        };

        /**
         * @brief Get the Keys Has Been Pressed object
         * 
         * @tparam ENUM key
         * @param map map of the keys
         * @return std::map<ENUM, bool> map of the keys that have been pressed
         */
        template<typename ENUM>
        std::map<ENUM, bool> getKeysHasBeenPressed(std::map<ENUM, int> map) const
        {
            std::map<ENUM, bool> actionPressed;
            for (auto &[action, key] : map)
                actionPressed.emplace(action, hasbeenReleased(key));
            return actionPressed;
        };

    protected:
    private:
        int _key; ///< key pressed
};



#endif /* !KEYBOARD_HPP_ */
