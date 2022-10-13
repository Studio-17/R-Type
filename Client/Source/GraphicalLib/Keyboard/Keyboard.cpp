/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-martin.vanaud
** File description:
** Keyboard
*/

#include "Keyboard.hpp"

Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
}

int Keyboard::getKey() const
{
    return _key;
}

bool Keyboard::hasBeenPressed(int key) const
{
    return IsKeyPressed(key);
}

bool Keyboard::isBeingPressed(int key) const
{
    return IsKeyDown(key);
}

bool Keyboard::hasBeenReleased(int key) const
{
    return IsKeyReleased(key);
}

bool Keyboard::isNotBeingPressed(int key) const
{
    return IsKeyUp(key);
}

void Keyboard::setExitKey(int key)
{
    SetExitKey(key);
}

int Keyboard::getPressedKeycode() const
{
    return GetKeyPressed();
}

int Keyboard::getPressedCharcode() const
{
    return GetCharPressed();
}

int Keyboard::getKeyUpCharCode() const
{
    return KEY_UP;
}

int Keyboard::getKeyDownCharCode() const
{
    return KEY_DOWN;
}

int Keyboard::getKeyRightCharCode() const
{
    return KEY_RIGHT;
}

int Keyboard::getKeyLeftCharCode() const
{
    return KEY_LEFT;
}

int Keyboard::getKeySpaceCharCode() const
{
    return KEY_SPACE;
}
