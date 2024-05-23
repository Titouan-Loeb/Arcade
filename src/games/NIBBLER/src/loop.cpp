/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** loop
*/

#include "nibbler.hpp"

int NIBBLER::Nibbler::moveAlone()
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

int NIBBLER::Nibbler::moveUp()
{
    _pos = calcPosNibbler();

    if (_map[_pos.x - 1][_pos.y] == '*') {
        _score += 100;
        _isEating = true;
        _isNotEating = 0;
        increaseTail();
    }
    else
        _isEating = false;
    if (_map[_pos.x - 1][_pos.y] == '+' && _direction != KeyArrowDown && _direction != KeyNone)
        return 1;
    if (_map[_pos.x - 1][_pos.y] == '*' ||
        _map[_pos.x - 1][_pos.y] == ' ') {
        _map[_pos.x - 1][_pos.y] = 'X';
        _map[_pos.x][_pos.y] = ' ';
        _direction = KeyArrowUp;
        _infinLoop = false;
        _rectDirection = UP;
        tailPos();
        tailMap();
    }
    else if ((_map[_pos.x - 1][_pos.y] != '*' ||
        _map[_pos.x - 1][_pos.y] != ' ' ||
        _map[_pos.x - 1][_pos.y] != 'Q') && _infinLoop == false) {
            _infinLoop = true;
            _rectDirection = UP;
            moveAlone();
        }
    _map[0][0] = 'P';
    _oldpos = _pos;
    return 0;
}

int NIBBLER::Nibbler::moveDown()
{
    _pos = calcPosNibbler();

    if (_map[_pos.x + 1][_pos.y] == '*') {
        _score += 100;
        _isEating = true;
        _isNotEating = 0;
        increaseTail();
    }
    else
        _isEating = false;
    if (_map[_pos.x + 1][_pos.y] == '+' && _direction != KeyArrowUp && _direction != KeyNone)
        return 1;
    if (_map[_pos.x + 1][_pos.y] == '*' ||
        _map[_pos.x + 1][_pos.y] == ' ') {
        _map[_pos.x + 1][_pos.y] = 'X';
        _map[_pos.x][_pos.y] = ' ';
        _direction = KeyArrowDown;
        _infinLoop = false;
        _rectDirection = DOWN;
        tailPos();
        tailMap();
    }
    else if ((_map[_pos.x + 1][_pos.y] != '*' ||
        _map[_pos.x + 1][_pos.y] != ' ' ||
        _map[_pos.x + 1][_pos.y] != 'Q') && _infinLoop == false) {
            _infinLoop = true;
            _rectDirection = DOWN;
            moveAlone();
        }
    _map[0][0] = 'P';
    _oldpos = _pos;
    return 0;
}

int NIBBLER::Nibbler::moveLeft()
{
    _pos = calcPosNibbler();

    if (_map[_pos.x][_pos.y - 1] == '*') {
        _score += 100;
        _isEating = true;
        _isNotEating = 0;
        increaseTail();
    }
    else
        _isEating = false;
    if (_map[_pos.x][_pos.y - 1] == '+' && _direction != KeyArrowRight && _direction != KeyNone)
        return 1;
    if (_map[_pos.x][_pos.y - 1] == '*' ||
        _map[_pos.x][_pos.y - 1] == ' ' ||
        _map[_pos.x][_pos.y - 1] == 'S') {
        _map[_pos.x][_pos.y - 1] = 'X';
        _map[_pos.x][_pos.y] = ' ';
        _direction = KeyArrowLeft;
        _infinLoop = false;
        _rectDirection = LEFT;
        tailPos();
        tailMap();
    }
    else if ((_map[_pos.x][_pos.y - 1] != '*' ||
        _map[_pos.x][_pos.y - 1] != ' ' ||
        _map[_pos.x][_pos.y - 1] != 'Q') && _infinLoop == false) {
            _infinLoop = true;
            _rectDirection = LEFT;
            moveAlone();
        }
    _oldpos = _pos;
    _map[0][0] = 'P';
    return 0;
}

int NIBBLER::Nibbler::moveRight()
{
    _pos = calcPosNibbler();

    if (_map[_pos.x][_pos.y + 1] == '*') {
        _score += 100;
        _isEating = true;
        _isNotEating = 0;
        increaseTail();
    }
    else
        _isEating = false;
    if (_map[_pos.x][_pos.y + 1] == '+' && _direction != KeyArrowLeft &&
        _direction != KeyNone)
        return 1;
    if (_map[_pos.x][_pos.y + 1] == '*' ||
        _map[_pos.x][_pos.y + 1] == ' ' ||
        _map[_pos.x][_pos.y + 1] == 'S') {
        _map[_pos.x][_pos.y + 1] = 'X';
        _map[_pos.x][_pos.y] = ' ';
        _direction = KeyArrowRight;
        _infinLoop = false;
        _rectDirection = RIGHT;
        tailPos();
        tailMap();
    }
    else if ((_map[_pos.x][_pos.y + 1] != '*' ||
        _map[_pos.x][_pos.y + 1] != ' ' ||
        _map[_pos.x][_pos.y + 1] != 'Q') && _infinLoop == false) {
            _infinLoop = true;
            _rectDirection = RIGHT;
            moveAlone();
        }
    _oldpos = _pos;
    _map[0][0] = 'P';
    return 0;
}

int NIBBLER::Nibbler::move(Key &key)
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

bool NIBBLER::Nibbler::victory()
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



bool NIBBLER::Nibbler::defeat()
{
    return false;
}

void NIBBLER::Nibbler::update(Key &key)
{
    clock_t now = clock();
    float delta = now - _clock;
    clock_t now2 = clock();
    float delta2 = now2 - _timerClock;

    if (key.code != KeyNone)
        _input = key.code;
    if (delta2 / CLOCKS_PER_SEC > _timerSpeed && _input != KeyNone) {
        _timerClock = clock();
        _timer--;
        if (_input != KeyNone) {
            if (_timer == 0)
                if (_lives > 0)
                    looseLife();
            if (_isEating == false)
                _isNotEating += 1;
            if (_isEating == false && _isNotEating >= _notEatingSpeed)
                _timerSpeed = 0.01;
            else
                _timerSpeed = 0.06;
        }
    }
    if (delta / CLOCKS_PER_SEC > _speed) {
        _clock = clock();
        if (_input != KeyNone) {
            if (move(key) == 1) {
                if (_lives > 0)
                    looseLife();
            }
        }
    }
    if (victory()) {
        _input = KeyNone;
        _direction = KeyNone;
        _infinLoop = false;
        _rectDirection = LEFT;
        _wave++;
        _speed -= 0.02;
        _timer = 990;
        _clock = clock();
        _timerClock = clock();
        _isEating = false;
        _isNotEating = 0;
        _notEatingSpeed -= 5;
        _objectList.clear();
        tailNode *tmp = _tail;
        for (;_tail != NULL; _tail = tmp) {
            tmp = _tail->next;
            delete(_tail);
        }
        if (_wave % 3 == 0)
            createMap2();
        else
            createMap();
        loadBody();
    }
    updateMap();
}
