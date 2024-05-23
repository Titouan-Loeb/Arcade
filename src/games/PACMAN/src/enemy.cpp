/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** enemy
*/

#include "pacman.hpp"
#include <iostream>
#include <vector>

Vect2i PACMAN::Pacman::getEnemyPosition(char id)
{
    for (int i = 0; i < _map.size(); i++)
        for (int j = 0; j < _map[i].length(); j++)
            if (_map[i][j] == id)
                return Vect2i{j, i};
    return Vect2i{1, 1};
}

enum PACMAN::Direction PACMAN::Pacman::oppositeDirection(enum Direction direction)
{
    switch (direction)
    {
    case UP:
        return (DOWN);
        break;
    case DOWN:
        return (UP);
        break;
    case LEFT:
        return (RIGHT);
        break;
    case RIGHT:
        return (LEFT);
        break;
    default:
        break;
    }
    return (UP);
}

int PACMAN::Pacman::chooseDirection(char character, int id, bool allowStepBack, int numWay)
{
    Vect2i enemyPos = getEnemyPosition(character);
    int choosenWay = 0;
    int (*isFreeWay[])(Vect2i, std::vector<std::string>) =
        {isUpFree, isDownFree, isLeftFree, isRightFree};

    for (int i = 0; i < 4 && numWay != -1; i++) {
        if ((allowStepBack || i != oppositeDirection(_enemyDirection[id])) &&
            isFreeWay[i](enemyPos, _map))
            numWay -= 1;
        if (numWay == -1)
            choosenWay = i;
    }
    return (moveEnemy(character, id, choosenWay, enemyPos));
}

int PACMAN::Pacman::enemyMovement(char character, int id, bool allowStepBack)
{
    Vect2i enemyPos = getEnemyPosition(character);
    int nbFreeWay = 0;
    int choosenWay = 0;
    int numWay = 0;
    int (*isFreeWay[])(Vect2i, std::vector<std::string>) =
        {isUpFree, isDownFree, isLeftFree, isRightFree};

    for (int i = 0; i < 4; i++) {
        if (allowStepBack || i != oppositeDirection(_enemyDirection[id])) {
            _freeWay[i] = isFreeWay[i](enemyPos, _map);
            nbFreeWay += _freeWay[i];
        }
    }
    if (!nbFreeWay) {
        if (!allowStepBack)
            return (enemyMovement(character, id, true));
        return (0);
    }
    numWay = rand() % nbFreeWay;
    return (chooseDirection(character, id, allowStepBack, numWay));
}

int PACMAN::Pacman::enemyMoveHandling()
{
    if (enemyMovement('1', 0, false) == 1)
        return 1;
    if (enemyMovement('2', 1, false) == 1)
        return 1;
    if (enemyMovement('3', 2, false) == 1)
        return 1;
    if (enemyMovement('4', 3, false) == 1)
        return 1;
    return 0;
}