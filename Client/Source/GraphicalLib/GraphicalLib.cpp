/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** GraphicalLib
*/

#include "GraphicalLib.hpp"

rtype::GraphicalLib::GraphicalLib(const int screenWidth, const int screenHeight, std::string title, const int framerate)
{
    InitWindow(screenWidth, screenHeight, title.c_str());
    _spriteMap = {};
    _textMap = {};
    _soundMap = {};
    _musicMap = {};

    SetTargetFPS(framerate);
}

rtype::GraphicalLib::~GraphicalLib()
{
    CloseWindow();
}

//Useful functions
void rtype::GraphicalLib::clearScreen()
{
    ClearBackground(RAYWHITE);
}

void rtype::GraphicalLib::startDrawingWindow()
{
    BeginDrawing();
}
void rtype::GraphicalLib::endDrawingWindow()
{
    EndDrawing();
}

bool rtype::GraphicalLib::windowShouldClose()
{
    return WindowShouldClose();
}

//Sprite
void rtype::GraphicalLib::createSprite(std::size_t id, std::string const &imagePath, Position const &position, float const &size)
{
    _spriteMap[id].reset(new Sprite(imagePath, position, size));
}

void rtype::GraphicalLib::drawSprite(std::size_t id)
{
    _spriteMap[id]->draw();
}

void rtype::GraphicalLib::destroySprite(std::size_t id)
{
    _spriteMap.erase(id);
}

void rtype::GraphicalLib::setSpritePosition(std::size_t id, Position const &position)
{
    _spriteMap[id]->setPosition(position);
}

void rtype::GraphicalLib::setSpriteScale(std::size_t id, float scale)
{
    _spriteMap[id]->setScale(scale);
}

Position rtype::GraphicalLib::getSpritePosition(std::size_t id)
{
    return _spriteMap[id]->getPosition();
}

void rtype::GraphicalLib::setSpriteRotation(std::size_t id, float rotation)
{
    _spriteMap[id]->setRotation(rotation);
}

float rtype::GraphicalLib::getSpriteRotation(std::size_t id)
{
    return _spriteMap[id]->getRotation();
}

// Text
void rtype::GraphicalLib::createText(std::size_t id, std::string const &filename, std::string const &text, int fontSize, Color const &color, Position const &position)
{
    _textMap[id].reset(new Text(filename, text, fontSize, color, position));
}

void rtype::GraphicalLib::drawText(std::size_t id)
{
    _textMap[id]->draw();
}

void rtype::GraphicalLib::setTextPosition(std::size_t id, Position const &position)
{
    _textMap[id]->setPosition(position);
}

Position rtype::GraphicalLib::getTextPosition(std::size_t id)
{
    return _textMap[id]->getPosition();
}

std::string rtype::GraphicalLib::getText(std::size_t id)
{
    return _textMap[id]->getText();
}

void rtype::GraphicalLib::setText(std::size_t id, std::string const &text)
{
    _textMap[id]->setText(text);
}

void rtype::GraphicalLib::setTextColor(std::size_t id, Color const &color)
{
    _textMap[id]->setColor(color);
}

void rtype::GraphicalLib::setTextFontSize(std::size_t id, int fontSize)
{
    _textMap[id]->setFontSize(fontSize);
}

//Musics
void rtype::GraphicalLib::createMusic(std::size_t id, std::string const &filename)
{
    _musicMap[id].reset(new MyMusic(filename));
}

void rtype::GraphicalLib::playMusic(std::size_t id)
{
    _musicMap[id]->play();
}

void rtype::GraphicalLib::stopMusic(std::size_t id)
{
    _musicMap[id]->stop();
}

void rtype::GraphicalLib::pauseMusic(std::size_t id)
{
    _musicMap[id]->pause();
}

void rtype::GraphicalLib::resumeMusic(std::size_t id)
{
    _musicMap[id]->resume();
}

bool rtype::GraphicalLib::isMusicPlaying(std::size_t id)
{
    return _musicMap[id]->isPlaying();
}

void rtype::GraphicalLib::setMusicVolume(std::size_t id, float volume)
{
    _musicMap[id]->setVolume(volume);
}

void rtype::GraphicalLib::updateMusicStream(std::size_t id)
{
    _musicMap[id]->updateStream();
}

//Sounds
void rtype::GraphicalLib::createSound(std::size_t id, std::string const &filename)
{
    _soundMap[id].reset(new MySound(filename));
}

void rtype::GraphicalLib::playSound(std::size_t id)
{
    _soundMap[id]->play();
}

void rtype::GraphicalLib::stopSound(std::size_t id)
{
    _soundMap[id]->stop();
}

void rtype::GraphicalLib::pauseSound(std::size_t id)
{
    _soundMap[id]->pause();
}

void rtype::GraphicalLib::resumeSound(std::size_t id)
{
    _soundMap[id]->resume();
}

bool rtype::GraphicalLib::isSoundPlaying(std::size_t id)
{
    return _soundMap[id]->isPlaying();
}

void rtype::GraphicalLib::setSoundVolume(std::size_t id, float volume)
{
    _soundMap[id]->setVolume(volume);
}


bool rtype::GraphicalLib::hasBeenPressed(int key)
{
    return _keyboard->hasBeenPressed(key);
}

bool rtype::GraphicalLib::isBeingPressed(int key)
{
    return _keyboard->isBeingPressed(key);
}

bool rtype::GraphicalLib::hasBeenReleased(int key)
{
    return _keyboard->hasBeenReleased(key);
}

bool rtype::GraphicalLib::isNotBeingPressed(int key)
{
    return _keyboard->isNotBeingPressed(key);
}

void rtype::GraphicalLib::setExitKey(int key)
{
    _keyboard->setExitKey(key);
}

int rtype::GraphicalLib::getPressedKeycode()
{
    return _keyboard->getPressedKeycode();
}

int rtype::GraphicalLib::getPressedCharcode()
{
    return _keyboard->getPressedCharcode();
}

