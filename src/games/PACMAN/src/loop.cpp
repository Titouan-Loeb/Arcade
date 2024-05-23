/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** loop
*/

#include "pacman.hpp"
#include <string>

int PACMAN::Pacman::moveAlone()
{
    if (_direction == KeyArrowUp)
        return moveUp();
    if (_direction == KeyArrowDown)
        return moveDown();
    if (_direction == KeyArrowLeft)
        return moveLeft();
    if (_direction == KeyArrowRight)
        return moveRight();
    return 0;
}

int PACMAN::Pacman::moveUp()
{
    _pos = calcPosPacMan();

    if (_map[_pos.x - 1][_pos.y] == '*' || _map[_pos.x - 1][_pos.y] == 'Q') {
        if (_map[_pos.x - 1][_pos.y] == 'Q')
            eatBigDot();
        _score += 100;
    }
    if (_map[_pos.x - 1][_pos.y] == '1' ||
        _map[_pos.x - 1][_pos.y] == '2' ||
        _map[_pos.x - 1][_pos.y] == '3' ||
        _map[_pos.x - 1][_pos.y] == '4')
        return (eatEnemy(std::stoi(&_map[_pos.x - 1][_pos.y]) - 1,
            _pos, {_pos.x - 1, _pos.y}, UP));
    if (_map[_pos.x - 1][_pos.y] == '*' ||
        _map[_pos.x - 1][_pos.y] == ' ' ||
        _map[_pos.x - 1][_pos.y] == 'Q') {
        _map[_pos.x - 1][_pos.y] = 'X';
        _map[_pos.x][_pos.y] = ' ';
        _direction = KeyArrowUp;
        _rectDirection = UP;
        _infinLoop = false;
    }
    else if ((_map[_pos.x - 1][_pos.y] != '*' ||
        _map[_pos.x - 1][_pos.y] != ' ' ||
        _map[_pos.x - 1][_pos.y] != 'Q') && _infinLoop == false) {
            _infinLoop = true;
            _rectDirection = UP;
            moveAlone();
    }
    return 0;
}

int PACMAN::Pacman::moveDown()
{
    _pos = calcPosPacMan();

    if (_map[_pos.x + 1][_pos.y] == '*' || _map[_pos.x + 1][_pos.y] == 'Q') {
        if (_map[_pos.x + 1][_pos.y] == 'Q')
            eatBigDot();
        _score += 100;
    }
    if (_map[_pos.x + 1][_pos.y] == '1' ||
        _map[_pos.x + 1][_pos.y] == '2' ||
        _map[_pos.x + 1][_pos.y] == '3' ||
        _map[_pos.x + 1][_pos.y] == '4')
        return (eatEnemy(std::stoi(&_map[_pos.x + 1][_pos.y]) - 1,
            _pos, {_pos.x + 1, _pos.y}, DOWN));
    if (_map[_pos.x + 1][_pos.y] == '*' ||
        _map[_pos.x + 1][_pos.y] == ' ' ||
        _map[_pos.x + 1][_pos.y] == 'Q') {
        _map[_pos.x + 1][_pos.y] = 'X';
        _map[_pos.x][_pos.y] = ' ';
        _direction = KeyArrowDown;
        _infinLoop = false;
        _rectDirection = DOWN;
    }
    else if ((_map[_pos.x + 1][_pos.y] != '*' ||
        _map[_pos.x + 1][_pos.y] != ' ' ||
        _map[_pos.x + 1][_pos.y] != 'Q') && _infinLoop == false) {
            _infinLoop = true;
            _rectDirection = DOWN;
            moveAlone();
    }
    return 0;
}

int PACMAN::Pacman::moveLeft()
{
    _pos = calcPosPacMan();

    if (_map[_pos.x][_pos.y - 1] == '*' || _map[_pos.x][_pos.y - 1] == 'Q') {
        if (_map[_pos.x][_pos.y - 1] == 'Q')
            eatBigDot();
        _score += 100;
    }
    if (_map[_pos.x][_pos.y - 1] == '1' ||
        _map[_pos.x][_pos.y - 1] == '2' ||
        _map[_pos.x][_pos.y - 1] == '3' ||
        _map[_pos.x][_pos.y - 1] == '4')
        return (eatEnemy(std::stoi(&_map[_pos.x][_pos.y - 1]) - 1,
            _pos, {_pos.x, _pos.y - 1}, LEFT));
    if (_map[_pos.x][_pos.y - 1] == '*' ||
        _map[_pos.x][_pos.y - 1] == ' ' ||
        _map[_pos.x][_pos.y - 1] == 'Q' ||
        _map[_pos.x][_pos.y - 1] == 'S') {
        _map[_pos.x][_pos.y - 1] = 'X';
        _map[_pos.x][_pos.y] = ' ';
        _direction = KeyArrowLeft;
        _infinLoop = false;
        _rectDirection = LEFT;
    }
    else if (_pos.y == 0) {
        _map[_pos.x][_map[_pos.x].length() - 1] = 'X';
        _map[_pos.x][_pos.y] = ' ';
        _direction = KeyArrowLeft;
        _infinLoop = false;
        _rectDirection = LEFT;
    }
    else if ((_map[_pos.x][_pos.y - 1] != '*' ||
        _map[_pos.x][_pos.y - 1] != ' ' ||
        _map[_pos.x][_pos.y - 1] != 'Q') && _infinLoop == false) {
            _infinLoop = true;
            _rectDirection = LEFT;
            moveAlone();
    }
    return 0;
}

int PACMAN::Pacman::moveRight()
{
    _pos = calcPosPacMan();

    if (_map[_pos.x][_pos.y + 1] == '*' || _map[_pos.x][_pos.y + 1] == 'Q') {
        if (_map[_pos.x][_pos.y + 1] == 'Q')
            eatBigDot();
        _score += 100;
    }
    if (_map[_pos.x][_pos.y + 1] == '1' ||
        _map[_pos.x][_pos.y + 1] == '2' ||
        _map[_pos.x][_pos.y + 1] == '3' ||
        _map[_pos.x][_pos.y + 1] == '4')
        return (eatEnemy(std::stoi(&_map[_pos.x][_pos.y + 1]) - 1,
            _pos, {_pos.x, _pos.y + 1}, RIGHT));
    if (_map[_pos.x][_pos.y + 1] == '*' ||
        _map[_pos.x][_pos.y + 1] == ' ' ||
        _map[_pos.x][_pos.y + 1] == 'Q' ||
        _map[_pos.x][_pos.y + 1] == 'S') {
        _map[_pos.x][_pos.y + 1] = 'X';
        _map[_pos.x][_pos.y] = ' ';
        _direction = KeyArrowRight;
        _infinLoop = false;
        _rectDirection = RIGHT;
    }
    else if (_pos.y == _map[_pos.x].length() - 1) {
        _map[_pos.x][0] = 'X';
        _map[_pos.x][_pos.y] = ' ';
        _direction = KeyArrowRight;
        _infinLoop = false;
        _rectDirection = RIGHT;
    }
    else if ((_map[_pos.x][_pos.y + 1] != '*' ||
        _map[_pos.x][_pos.y + 1] != ' ' ||
        _map[_pos.x][_pos.y + 1] != 'Q') && _infinLoop == false) {
            _infinLoop = true;
            _rectDirection = RIGHT;
            moveAlone();
        }
    return 0;
}

int PACMAN::Pacman::move(Key &key)
{
    if (_input == KeyArrowUp) {
        if (moveUp() == 1)
            return 1;
        return 0;
    }
    if (_input == KeyArrowDown) {
        if (moveDown() == 1)
            return 1;
        return 0;
    }
    if (_input == KeyArrowLeft) {
        if (moveLeft() == 1)
            return 1;
        return 0;
    }
    if (_input == KeyArrowRight) {
        if (moveRight() == 1)
            return 1;
        return 0;
    }
    if (_direction != KeyNone) {
        if (moveAlone() == 1)
            return 1;
        return 0;
    }
    return 0;
}

bool PACMAN::Pacman::victory()
{
    int nbStars = 0;

    for (int i = 0; i != _map.size(); i++)
        for (int j = 0; j != _map[i].length(); j++)
            if (_map[i][j] == '*')
                nbStars++;
    if (nbStars == 0)
        return true;
    return false;
}

bool PACMAN::Pacman::defeat()
{
    return false;
}

void PACMAN::Pacman::update(Key &key)
{
    clock_t now = clock();
    float delta = now - _clock;
    bool isEat = false;

    if (key.code != KeyNone)
        _input = key.code;
    if (delta / CLOCKS_PER_SEC > _speed) {
        _clock = clock();
        if (_input != KeyNone && _input != KeyEnter && _input != KeyF5) {
            _animPacman = !_animPacman;
            enemyLessScared();
            if (move(key) == 1) {
                if (_lives > 0) {
                    looseLife();
                    isEat = true;
                }
                else
                    isEat = false;
            }
            if (isEat == false && enemyMoveHandling() == 1)
                if (_lives > 0)
                    looseLife();
        }
    }
    if (victory()) {
        _input = KeyNone;
        _direction = KeyNone;
        _infinLoop = false;
        _objectList.clear();
        _wave++;
        _speed -= 0.01;
        _clock = clock();
        _objectList.clear();
        _oldCharTab[0] = ' ';
        _oldCharTab[1] = ' ';
        _oldCharTab[2] = ' ';
        _oldCharTab[3] = ' ';
        _enemyDirection[0] = UP;
        _enemyDirection[1] = DOWN;
        _enemyDirection[2] = LEFT;
        _enemyDirection[3] = RIGHT;
        _scaredEnemy[0] = 0;
        _scaredEnemy[1] = 0;
        _scaredEnemy[2] = 0;
        _scaredEnemy[3] = 0;
        createMap();
    }
    updateMap();
}