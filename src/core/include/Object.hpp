/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "ObjectInfo.hpp"

typedef struct Object_t
{
    int objectID;
    std::string texturePath;
    Vect2f fPos;
    Vect2i iPos;
    Rectangle rect;
    const char *character;
    int colorID;
    Vect2f fOffSet;
    char mapChar;
} Object;

typedef enum KeyState_t {
    StateNone,
    KeyPressed,
    KeyReleased
} KeyState;

typedef enum KeyCode_t {
    KeyNone,
    KeyArrowUp,
    KeyArrowDown,
    KeyArrowLeft,
    KeyArrowRight,
    KeyEscape,
    KeySpace,
    KeyF1,
    KeyF2,
    KeyF3,
    KeyF4,
    KeyF5,
    KeyF6,
    KeyF7,
    KeyF8,
    KeyF9,
    KeyF10,
    KeyF11,
    KeyF12,
    KeyA,
    KeyB,
    KeyC,
    KeyD,
    KeyE,
    KeyF,
    KeyG,
    KeyH,
    KeyI,
    KeyJ,
    KeyK,
    KeyL,
    KeyM,
    KeyN,
    KeyO,
    KeyP,
    KeyQ,
    KeyR,
    KeyS,
    KeyT,
    KeyU,
    KeyV,
    KeyW,
    KeyX,
    KeyY,
    KeyZ,
    KeyBackspace,
    KeyEnter
} KeyCode;

typedef struct Key_t {
    KeyState state;
    KeyCode code;
} Key;

#endif /* !OBJECT_HPP_ */
