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
    int key = GetKeyPressed();

    return key;
}

int Keyboard::getPressedCharcode() const
{
    int key = GetCharPressed();

    return key;
}
