/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** GraphicalLib
*/

#include "GraphicalLib.hpp"

rtype::GraphicalLib::GraphicalLib()
{
    _spriteMap = {};
    _textMap = {};
    _soundMap = {};
    _musicMap = {};
}

rtype::GraphicalLib::~GraphicalLib()
{
}

void rtype::GraphicalLib::initWindow(const int screenWidth, const int screenHeight, std::string title, const int framerate)
{
    InitWindow(screenWidth, screenHeight, title.c_str());
    SetTargetFPS(framerate);
}

void rtype::GraphicalLib::closeWindow()
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
std::shared_ptr<Sprite> rtype::GraphicalLib::createSprite(std::string const &imagePath, float const &size, Rectangle const &rect)
{
    return std::make_shared<Sprite>(imagePath, size, rect);
}

void rtype::GraphicalLib::drawSprite(MyTexture const &texture, Position const &position, float rotation, float scale)
{
    DrawTextureEx(texture.getTexture(), position.getVector2(), rotation, scale, WHITE);
}

void rtype::GraphicalLib::drawRectangle(MyTexture const &texture, Position const &position, Rectangle const &rect)
{
    DrawTextureRec(texture.getTexture(), rect, position.getVector2(), WHITE);
}

void rtype::GraphicalLib::destroySprite(std::shared_ptr<Sprite> sprite)
{
    UnloadTexture(sprite->getTexture());
}

void rtype::GraphicalLib::setSpritePosition(Sprite &sprite, Position const &position)
{
    sprite.setPosition(position);
}

void rtype::GraphicalLib::setSpriteScale(Sprite &sprite, float scale)
{
    sprite.setScale(scale);
}

Position rtype::GraphicalLib::getSpritePosition(Sprite const &sprite)
{
    return sprite.getPosition();
}

void rtype::GraphicalLib::setSpriteRotation(Sprite &sprite, float rotation)
{
    sprite.setRotation(rotation);
}

float rtype::GraphicalLib::getSpriteRotation(Sprite const &sprite)
{
    return sprite.getRotation();
}

bool rtype::GraphicalLib::checkCollisions(Sprite const &sprite1, Sprite const &sprite2)
{
    return CheckCollisionRecs(sprite1.getRect(), sprite2.getRect());
}

bool rtype::GraphicalLib::checkMouseCollision(Position const &position, float const &x, float const &y, float const &height, float const &width)
{
    return CheckCollisionPointRec((Vector2){position.getX(), position.getY()}, (Rectangle){x, y, height, width});
}

bool rtype::GraphicalLib::IsLeftMouseButtonPressed()
{
    return IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

Position rtype::GraphicalLib::getMousePosition()
{
    Vector2 mousePosition = GetMousePosition();
    return (Position){mousePosition.x, mousePosition.y};
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
void rtype::GraphicalLib::createSound(std::size_t id, [[ maybe_unused ]] std::string const &filename)
{
    _soundMap[id].reset(new MySound);
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

//Input
bool rtype::GraphicalLib::hasBeenPressed(int key)
{
    return IsKeyPressed(key);
}

bool rtype::GraphicalLib::isBeingPressed(int key)
{
    return IsKeyDown(key);
}

bool rtype::GraphicalLib::hasBeenReleased(int key)
{
    return IsKeyReleased(key);
}

bool rtype::GraphicalLib::isNotBeingPressed(int key)
{
    return IsKeyUp(key);
}

void rtype::GraphicalLib::setExitKey(int key)
{
    return SetExitKey(key);
}

int rtype::GraphicalLib::getPressedKeycode()
{
    return GetKeyPressed();
}

int rtype::GraphicalLib::getPressedCharcode()
{
    return GetCharPressed();
}

