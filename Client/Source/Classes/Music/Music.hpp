/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

    #include <string>
    #include <raylib.h>

class Music {
    public:

        /**
         * @brief Construct a new My Music object
         *
         * @param filename
         */
        Music(std::string const &filename);

        /**
         * @brief Construct a new My Music object
         */
        Music() {};
        /**
         * @brief Destroy the My Music object
         */
        ~Music();

/**
         * @brief Start music playing
         */
        void play();
        /**
         * @brief Stop music playing
         */
        void stop();
        /**
         * @brief Pause music playing
         */
        void pause();
        /**
         * @brief Resume playing paused music
         */
        void resume();

        /**
         * @brief Check if music is playing
         *
         * @return true
         * @return false
         */
        bool isPlaying() const;
        /**
         * @brief Set the Volume object
         *
         * @param volume
         */
        void setVolume(float volume);
        /**
         * @brief Upadte Music stream
         */
        void updateMusicStream();

    protected:
    private:
        Music _music; ///< Music object

};

#endif /* !MUSIC_HPP_ */
