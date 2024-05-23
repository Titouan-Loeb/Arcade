/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** nibbler
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "nibbler.hpp"
#include "errors.hpp"

extern "C" IGames *createGame()
{
    return (dynamic_cast<IGames *>(new NIBBLER::Nibbler));
}

NIBBLER::Nibbler::Nibbler()
{
    _score = 0;
    _input = KeyNone;
    _direction = KeyNone;
    _rectDirection = LEFT;
    _clock = clock();
    _timerClock = clock();
    _oldpos = calcPosNibbler();
    _starOn = false;
    _tail = nullptr;
    _sizeTail = 0;
    _lives = 3;
    _wave = 1;
    _speed = 0.20;
    _timer = 990;
    _timerSpeed = 0.05;
    _isNotEating = 0;
    _isEating = false;
    _notEatingSpeed = 70;
    createMap();
    loadBody();
}

NIBBLER::Nibbler::~Nibbler()
{
}

std::vector<std::string> NIBBLER::Nibbler::createFileLines(std::string buff)
{
    size_t pos = 0;
    std::vector<std::string> fileLines;

    while ((pos = buff.find("\n")) != buff.npos) {
        fileLines.push_back(buff.substr(0, pos));
        buff.erase(0, pos + 1);
    }
    if (buff.length() != 0)
        fileLines.push_back(buff);
    return (fileLines);
}

Object NIBBLER::Nibbler::createBlock(int i, int j)
{
    Object obj;

    for (int k = 0; k < nbLinksNib; k++) {
        if (mapCharLinksNib[k].lettre == _map[i][j]) {
            obj = NibblerObjects[mapCharLinksNib[k].ID];
            obj.fPos.y = 1080 / 2 - 32 * 19 / 2 + i * 32 + obj.fOffSet.y - 90;
            obj.fPos.x = 1920 / 2 - 32 * 19 / 2 + j * 32 + obj.fOffSet.x;
            obj.iPos.y = i;
            obj.iPos.x = j;
            return (obj);
        }
    }
    throw ErrUnknowBlock("Error : map contain an unknonw block : " + _map[i][j]);
}

void NIBBLER::Nibbler::addNodeTail(Vect2i pos, Vect2i oldPos)
{
    tailNode *tmp = _tail;

    if (_tail == NULL) {
        _tail = new tailNode;
        _tail->pos = pos;
        _tail->oldPos = oldPos;
        _tail->next = NULL;
        return;
    }
    while (tmp->next != NULL)
         tmp = tmp->next;
    tmp->next = new tailNode;
    tmp->next->pos = pos;
    tmp->next->oldPos = oldPos;
    tmp->next->next = NULL;
    _sizeTail++;
}

Vect2i NIBBLER::Nibbler::findBody(Vect2i pos, Vect2i oldPos)
{
    if (_map[pos.x - 1][pos.y] == '+' &&
        (pos.x - 1 != oldPos.x || pos.y != oldPos.y)) {
        addNodeTail({pos.x - 1, pos.y}, {0, 0});
        return ((Vect2i){pos.x - 1, pos.y});
    }
    if (_map[pos.x + 1][pos.y] == '+' &&
        (pos.x + 1 != oldPos.x || pos.y != oldPos.y)) {
        addNodeTail({pos.x + 1, pos.y}, {0, 0});
        return ((Vect2i){pos.x + 1, pos.y});
    }
    if (_map[pos.x][pos.y - 1] == '+' &&
        (pos.x != oldPos.x || pos.y - 1 != oldPos.y)) {
        addNodeTail({pos.x, pos.y - 1}, {0, 0});
        return ((Vect2i){pos.x, pos.y - 1});
    }
    if (_map[pos.x][pos.y + 1] == '+' &&
        (pos.x != oldPos.x || pos.y + 1 != oldPos.y)) {
        addNodeTail({pos.x, pos.y + 1}, {0, 0});
        return ((Vect2i){pos.x, pos.y + 1});
    }
    return ((Vect2i){-1, -1});
}

void NIBBLER::Nibbler::loadBody()
{
    Vect2i posNibbler = calcPosNibbler();
    Vect2i tmp = {0, 0};
    Vect2i oldPos = {0, 0};

    tmp = posNibbler;
    posNibbler = findBody(posNibbler, oldPos);
    oldPos = tmp;
    tmp = posNibbler;
    while (posNibbler.x != -1 && posNibbler.y != -1) {
        posNibbler = findBody(posNibbler, oldPos);
        oldPos = tmp;
        tmp = posNibbler;
    }
}

void NIBBLER::Nibbler::restart()
{
    _input = KeyNone;
    _direction = KeyNone;
    _infinLoop = false;
    _rectDirection = LEFT;
    _score = 0;
    _clock = clock();
    _timerClock = clock();
    _objectList.clear();
    tailNode *tmp = _tail;
    for (;_tail != NULL; _tail = tmp) {
        tmp = _tail->next;
        delete(_tail);
    }
    _lives = 3;
    _wave = 1;
    _speed = 0.20;
    _timer = 990;
    _timerSpeed = 0.05;
    _isNotEating = 0;
    _isEating = false;
    _notEatingSpeed = 70;
    createMap();
    loadBody();
}

int NIBBLER::Nibbler::looseLife()
{
    _input = KeyNone;
    _direction = KeyNone;
    _infinLoop = false;
    _rectDirection = LEFT;
    _clock = clock();
    _timerClock = clock();
    _timer = 990;
    _timerSpeed = 0.05;
    _isEating = false;
    _isNotEating = 0;
    tailNode *tmp = _tail;
    for (;_tail != NULL; _tail = tmp) {
        tmp = _tail->next;
        delete(_tail);
    }
    for (int i = 0; i != _map.size(); i++)
        for (int j = 0; j != _map[i].length(); j++)
            if (_map[i][j] == '+' || _map[i][j] == 'X')
                _map[i][j] = ' ';
    _map[9][7] = 'X';
    _map[9][8] = '+';
    _map[9][9] = '+';
    _map[9][10] = '+';
    --_lives;
    loadBody();
    return 0;
}


void NIBBLER::Nibbler::createMap()
{
    std::ifstream file("assets/maps/nibblerMap.txt", std::ifstream::in);
    std::stringstream stream;

    if (file.good()) {
        stream << file.rdbuf();
        file.close();
        _map = createFileLines(stream.str());
        for (int i = 0; i < _map.size(); i++)
            for (int j = 0; j < _map[i].length(); j++) {
                _objectList.push_back(createBlock(i, j));
            }
    } else
        throw ErrMapNotFound();
}

void NIBBLER::Nibbler::createMap2()
{
    std::ifstream file("assets/maps/nibblerMap2.txt", std::ifstream::in);
    std::stringstream stream;

    if (file.good()) {
        stream << file.rdbuf();
        file.close();
        _map = createFileLines(stream.str());
        for (int i = 0; i < _map.size(); i++)
            for (int j = 0; j < _map[i].length(); j++) {
                _objectList.push_back(createBlock(i, j));
            }
    } else
        throw ErrMapNotFound();
}

void NIBBLER::Nibbler::updateMap()
{
    int k = 0;

    for (int i = 0; i < _map.size(); i++)
        for (int j = 0; j < _map[i].length(); j++) {
            if (_map[i][j] != _objectList[k].mapChar) {
                _objectList[k] = createBlock(i, j);
                if (_objectList[k].objectID == head)
                    _objectList[k].rect.left = _objectList[k].rect.width * _rectDirection;
            }
            k++;
        }
}

std::vector<Object> NIBBLER::Nibbler::getObjectList() const
{
    return (_objectList);
}

int NIBBLER::Nibbler::getScore() const
{
    return (_score);
}

int NIBBLER::Nibbler::getLives() const
{
    return _lives;
}

int NIBBLER::Nibbler::getWave() const
{
    return _wave;
}

int NIBBLER::Nibbler::getTime() const
{
    return _timer;
}