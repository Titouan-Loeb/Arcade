/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** moveEnemy
*/

#include "pacman.hpp"

int PACMAN::Pacman::moveEnemy(char character, int id, int direction, Vect2i enemyPos)
{
    switch (direction) {
        case UP:
            return (enemyMoveUp(character, id, enemyPos));
            break;
        case DOWN:
            return (enemyMoveDown(character, id, enemyPos));
            break;
        case LEFT:
            return (enemyMoveLeft(character, id, enemyPos));
            break;
        case RIGHT:
            return (enemyMoveRight(character, id, enemyPos));
            break;
    }
    return (0);
}

int PACMAN::Pacman::enemyMoveUp(char character, int id, Vect2i enemyPos)
{
    char tmpChar = _oldCharTab[id];

    if (_map[enemyPos.y - 1][enemyPos.x] == 'X')
        return (eatEnemy(id, enemyPos, tmpChar));
    if (_map[enemyPos.y - 1][enemyPos.x] == '*' ||
        _map[enemyPos.y - 1][enemyPos.x] == ' ' ||
        _map[enemyPos.y - 1][enemyPos.x] == 'Q' ||
        _map[enemyPos.y - 1][enemyPos.x] == 'U') {
        _oldCharTab[id] = _map[enemyPos.y - 1][enemyPos.x];
        _map[enemyPos.y - 1][enemyPos.x] = character;
        _map[enemyPos.y][enemyPos.x] = tmpChar;
        _enemyDirection[id] = UP;
        return 0;
    }
    return 2;
}

int PACMAN::Pacman::enemyMoveDown(char character, int id, Vect2i enemyPos)
{
    char tmpChar = _oldCharTab[id];

    if (_map[enemyPos.y + 1][enemyPos.x] == 'X')
        return (eatEnemy(id, enemyPos, tmpChar));
    if (_map[enemyPos.y + 1][enemyPos.x] == '*' ||
        _map[enemyPos.y + 1][enemyPos.x] == ' ' ||
        _map[enemyPos.y + 1][enemyPos.x] == 'Q') {
        _oldCharTab[id] = _map[enemyPos.y + 1][enemyPos.x];
        _map[enemyPos.y + 1][enemyPos.x] = character;
        _map[enemyPos.y][enemyPos.x] = tmpChar;
        _enemyDirection[id] = DOWN;
        return 0;
    }
    return 2;
}

int PACMAN::Pacman::enemyMoveLeft(char character, int id, Vect2i enemyPos)
{
    char tmpChar = _oldCharTab[id];

    if (_map[enemyPos.y][enemyPos.x - 1] == 'X')
        return (eatEnemy(id, enemyPos, tmpChar));
    if (_map[enemyPos.y][enemyPos.x - 1] == '*' ||
        _map[enemyPos.y][enemyPos.x - 1] == ' ' ||
        _map[enemyPos.y][enemyPos.x - 1] == 'Q') {
        _oldCharTab[id] = _map[enemyPos.y][enemyPos.x - 1];
        _map[enemyPos.y][enemyPos.x - 1] = character;
        _map[enemyPos.y][enemyPos.x] = tmpChar;
        _enemyDirection[id] = LEFT;
        return 0;
    }
    return 2;
}

int PACMAN::Pacman::enemyMoveRight(char character, int id, Vect2i enemyPos)
{
    char tmpChar = _oldCharTab[id];

    if (_map[enemyPos.y][enemyPos.x + 1] == 'X')
        return (eatEnemy(id, enemyPos, tmpChar));
    if (_map[enemyPos.y][enemyPos.x + 1] == '*' ||
        _map[enemyPos.y][enemyPos.x + 1] == ' ' ||
        _map[enemyPos.y][enemyPos.x + 1] == 'Q') {
        _oldCharTab[id] = _map[enemyPos.y][enemyPos.x + 1];
        _map[enemyPos.y][enemyPos.x + 1] = character;
        _map[enemyPos.y][enemyPos.x] = tmpChar;
        _enemyDirection[id] = RIGHT;
        return 0;
    }
    return 2;
}