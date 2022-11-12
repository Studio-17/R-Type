/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** GraphicalLib
*/

#include "GraphicalLib.hpp"

rtype::GraphicalLib::GraphicalLib()
{
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

void rtype::GraphicalLib::drawSprite(MyTexture const &texture, std::array<float, 4> const &rectSource, std::array<float, 4> const &rectDest, std::pair<float, float> const &origin, float const &rotation, float const &scale)
{
    DrawTextureTiled(texture.getTexture(), {rectSource[0], rectSource[1], rectSource[2], rectSource[3]}, {rectDest[0], rectDest[1], rectDest[2], rectDest[3]}, {origin.first, origin.second}, rotation, scale, WHITE);
}

bool rtype::GraphicalLib::checkMouseCollision(Position const &position, float const &x, float const &y, float const &height, float const &width)
{
    return CheckCollisionPointRec((Vector2){position.getX(), position.getY()}, (Rectangle){x, y, height, width});
}

bool rtype::GraphicalLib::IsLeftMouseButtonPressed()
{
    return IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

bool rtype::GraphicalLib::IsLeftMouseButtonReleased()
{
    return IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
}

Position rtype::GraphicalLib::getMousePosition()
{
    Vector2 mousePosition = GetMousePosition();
    return Position(mousePosition.x, mousePosition.y);
}

Color rtype::GraphicalLib::createColor(std::array<float, 4> const &array)
{
    Color color;

    color.r = array.at(0);
    color.g = array.at(1);
    color.b = array.at(2);
    color.a = array.at(3);
    return color;
}

// Text
// void rtype::GraphicalLib::drawText([[ maybe_unused ]]std::string const &font, std::string const &text, Position const &pos, std::size_t const &fontSize, [[ maybe_unused ]]float const &spacing, std::array<float, 4> const &color)
void rtype::GraphicalLib::drawText(std::string const &text, Position const &pos, std::size_t const &fontSize, std::array<float, 4> const &color)
{
    // DrawTextEx(LoadFont(font.c_str()), text.c_str(), (Vector2){pos.getX(), pos.getY()}, fontSize, spacing, createColor(color));
    DrawText(text.c_str(), pos.getX(), pos.getY(), fontSize, createColor(color));
}

void rtype::GraphicalLib::initAudio()
{
    InitAudioDevice();
}

void rtype::GraphicalLib::closeAudio()
{
    CloseAudioDevice();
}

void rtype::GraphicalLib::playASound(MySound &sound)
{
    sound.play();
}

void rtype::GraphicalLib::playAMusic(MyMusic &music)
{
    music.play();
}

void rtype::GraphicalLib::updateAMusic(MyMusic &music)
{
    music.updateStream();
}


//Musics
// void rtype::GraphicalLib::createMusic(std::size_t id, std::string const &filename)
// {
//     _musicMap[id].reset(new MyMusic(filename));
// }

// void rtype::GraphicalLib::playMusic(std::size_t id)
// {
//     _musicMap[id]->play();
// }

// void rtype::GraphicalLib::stopMusic(std::size_t id)
// {
//     _musicMap[id]->stop();
// }

// void rtype::GraphicalLib::pauseMusic(std::size_t id)
// {
//     _musicMap[id]->pause();
// }

// void rtype::GraphicalLib::resumeMusic(std::size_t id)
// {
//     _musicMap[id]->resume();
// }

// bool rtype::GraphicalLib::isMusicPlaying(std::size_t id)
// {
//     return _musicMap[id]->isPlaying();
// }

// void rtype::GraphicalLib::setMusicVolume(std::size_t id, float volume)
// {
//     _musicMap[id]->setVolume(volume);
// }

// void rtype::GraphicalLib::updateMusicStream(std::size_t id)
// {
//     _musicMap[id]->updateStream();
// }

// //Sounds
// void rtype::GraphicalLib::createSound(std::size_t id, [[ maybe_unused ]] std::string const &filename)
// {
//     _soundMap[id].reset(new MySound);
// }

// void rtype::GraphicalLib::playSound(std::size_t id)
// {
//     _soundMap[id]->play();
// }

// void rtype::GraphicalLib::stopSound(std::size_t id)
// {
//     _soundMap[id]->stop();
// }

// void rtype::GraphicalLib::pauseSound(std::size_t id)
// {
//     _soundMap[id]->pause();
// }

// void rtype::GraphicalLib::resumeSound(std::size_t id)
// {
//     _soundMap[id]->resume();
// }

// bool rtype::GraphicalLib::isSoundPlaying(std::size_t id)
// {
//     return _soundMap[id]->isPlaying();
// }

// void rtype::GraphicalLib::setSoundVolume(std::size_t id, float volume)
// {
//     _soundMap[id]->setVolume(volume);
// }

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

