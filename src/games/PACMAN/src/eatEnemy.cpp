/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** eatEnemy
*/

#include "pacman.hpp"

void PACMAN::Pacman::eatBigDot()
{
    _scaredEnemy[0] = 30;
    _scaredEnemy[1] = 30;
    _scaredEnemy[2] = 30;
    _scaredEnemy[3] = 30;
}

void PACMAN::Pacman::enemyLessScared()
{
    for (int i = 0; i < 4; i++)
        if (_scaredEnemy[i] > 0)
            _scaredEnemy[i]--;
}

void PACMAN::Pacman::scareEnemy(int id, int k)
{
    if (_scaredEnemy[id] > 0) {
        _objectList[k].rect.top = _objectList[k].rect.height * 7;
        _objectList[k].rect.left = _objectList[k].rect.width * _animPacman;
    } else {
        _objectList[k].rect.top = _objectList[k].rect.height * (3 + id);
        _objectList[k].rect.left = _objectList[k].rect.width * _enemyDirection[3] * 2 + _objectList[k].rect.width * _animPacman;
    }
}

int PACMAN::Pacman::eatEnemy(int id, Vect2i posPacman, Vect2i posEnemy, int dir)
{
    if (_scaredEnemy[id] > 0) {
        _score += 400;
        _scaredEnemy[id] = 0;
        if (_oldCharTab[id] == '*')
            _score += 100;
        _map[posEnemy.x][posEnemy.y] = 'X';
        _map[posPacman.x][posPacman.y] = ' ';
        _direction = dir + 1;
        _infinLoop = false;
        _rectDirection = (Direction)dir;
        switch (id)
        {
        case 0:
            _map[10][9] = '1';
            _oldCharTab[0] = ' ';
            break;
        case 1:
            _map[10][11] = '2';
            _oldCharTab[1] = ' ';
            break;
        case 2:
            _map[11][9] = '3';
            _oldCharTab[2] = ' ';
            break;
        case 3:
            _map[11][11] = '4';
            _oldCharTab[3] = ' ';
            break;
        default:
            break;
        }
        return (0);
    }
    return (1);
}

int PACMAN::Pacman::eatEnemy(int id, Vect2i posEnemy, char tmpChar)
{
    if (_scaredEnemy[id] > 0) {
        _score += 400;
        _scaredEnemy[id] = 0;
        _map[posEnemy.y][posEnemy.x] = tmpChar;
        switch (id)
        {
        case 0:
            _map[10][9] = '1';
            _oldCharTab[0] = ' ';
            break;
        case 1:
            _map[10][11] = '2';
            _oldCharTab[1] = ' ';
            break;
        case 2:
            _map[11][9] = '3';
            _oldCharTab[2] = ' ';
            break;
        case 3:
            _map[11][11] = '4';
            _oldCharTab[3] = ' ';
            break;
        default:
            break;
        }
        return (0);
    }
    return (1);
}
