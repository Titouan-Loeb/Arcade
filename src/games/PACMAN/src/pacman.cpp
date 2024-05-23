/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** pacman
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "pacman.hpp"
#include "errors.hpp"

extern "C" IGames *createGame()
{
    return (dynamic_cast<IGames *>(new PACMAN::Pacman));
}

PACMAN::Pacman::Pacman()
{
    srand(time(NULL));
    _input = KeyNone;
    _direction = KeyNone;
    _rectDirection = UP;
    _animPacman = 0;
    _infinLoop = false;
    _score = 0;
    _clock = clock();
    _lives = 3;
    _enemyDirection[0] = UP;
    _enemyDirection[1] = UP;
    _enemyDirection[2] = UP;
    _enemyDirection[3] = UP;
    _scaredEnemy[0] = 0;
    _scaredEnemy[1] = 0;
    _scaredEnemy[2] = 0;
    _scaredEnemy[3] = 0;
    _wave = 1;
    _speed = 0.20;
    _oldCharTab[0] = ' ';
    _oldCharTab[1] = ' ';
    _oldCharTab[2] = ' ';
    _oldCharTab[3] = ' ';
    createMap();
}

PACMAN::Pacman::~Pacman()
{
}

std::vector<std::string> PACMAN::Pacman::createFileLines(std::string buff)
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

Object PACMAN::Pacman::createBlock(int i, int j)
{
    Object obj;

    for (int k = 0; k < nbLinks; k++) {
        if (mapCharLinks[k].lettre == _map[i][j]) {
            obj = PacmanObjects[mapCharLinks[k].ID];
            obj.fPos.y = 1080 / 2 - 32 * 24 / 2 + i * 32 + obj.fOffSet.y - 90;
            obj.fPos.x = 1920 / 2 - 32 * 21 / 2 + j * 32 + obj.fOffSet.x;
            obj.iPos.y = i;
            obj.iPos.x = j;
            obj.mapChar = mapCharLinks[k].lettre;
            return (obj);
        }
    }
    throw ErrUnknowBlock("Error : map contain an unknonw block : " + _map[i][j]);
}

void PACMAN::Pacman::createMap()
{
    std::ifstream file("assets/maps/pacmanMap.txt", std::ifstream::in);
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

void PACMAN::Pacman::createCreatures()
{
    Object obj;

    for (int i = 0; i < nbCreatures; i++) {
        obj = PacmanObjects[i];
        obj.fPos.y = i * 48;
        obj.iPos.x = -5;
        obj.iPos.y = -3 + i;
        _objectList.push_back(obj);
    }
}

void PACMAN::Pacman::restart()
{
    _input = KeyNone;
    _direction = KeyNone;
    _infinLoop = false;
    _score = 0;
    _clock = clock();
    _objectList.clear();
    _lives = 3;
    _enemyDirection[0] = UP;
    _enemyDirection[1] = DOWN;
    _enemyDirection[2] = LEFT;
    _enemyDirection[3] = RIGHT;
    _scaredEnemy[0] = 0;
    _scaredEnemy[1] = 0;
    _scaredEnemy[2] = 0;
    _scaredEnemy[3] = 0;
    _wave = 1;
    _oldCharTab[0] = ' ';
    _oldCharTab[1] = ' ';
    _oldCharTab[2] = ' ';
    _oldCharTab[3] = ' ';
    createMap();
}

int PACMAN::Pacman::looseLife()
{
    Vect2i pacmanPos = calcPosPacMan();
    Vect2i enemy1Pos = getEnemyPosition('1');
    Vect2i enemy2Pos = getEnemyPosition('2');
    Vect2i enemy3Pos = getEnemyPosition('3');
    Vect2i enemy4Pos = getEnemyPosition('4');

    _input = KeyNone;
    _direction = KeyNone;
    _infinLoop = false;
    _clock = clock();
    _scaredEnemy[0] = 0;
    _scaredEnemy[1] = 0;
    _scaredEnemy[2] = 0;
    _scaredEnemy[3] = 0;
    _enemyDirection[0] = UP;
    _enemyDirection[1] = DOWN;
    _enemyDirection[2] = LEFT;
    _enemyDirection[3] = RIGHT;
    _map[pacmanPos.x][pacmanPos.y] = ' ';
    _map[13][10] = 'X';
    _map[enemy1Pos.y][enemy1Pos.x] = _oldCharTab[0];
    _map[enemy2Pos.y][enemy2Pos.x] = _oldCharTab[1];
    _map[enemy3Pos.y][enemy3Pos.x] = _oldCharTab[2];
    _map[enemy4Pos.y][enemy4Pos.x] = _oldCharTab[3];
    _map[10][9] = '1';
    _map[10][11] = '2';
    _map[11][9] = '3';
    _map[11][11] = '4';
    _oldCharTab[0] = ' ';
    _oldCharTab[1] = ' ';
    _oldCharTab[2] = ' ';
    _oldCharTab[3] = ' ';
    _lives--;
    return 0;
}

void PACMAN::Pacman::animEntities(int k)
{
    switch (_objectList[k].objectID)
    {
    case pacman:
        _objectList[k].rect.left = _objectList[k].rect.width * _rectDirection * 2 + _objectList[k].rect.width * _animPacman;
        break;
    case redGhost:
        scareEnemy(0, k);
        break;
    case pinkGhost:
        scareEnemy(1, k);
        break;
    case blueGhost:
        scareEnemy(2, k);
        break;
    case orangeGhost:
        scareEnemy(3, k);
        break;
    default:
        break;
    }
}

void PACMAN::Pacman::updateMap()
{
    int k = 0;

    for (int i = 0; i < _map.size(); i++)
        for (int j = 0; j < _map[i].length(); j++) {
            if (_map[i][j] != _objectList[k].mapChar) {
                _objectList[k] = createBlock(i, j);
            }
            animEntities(k);
            k++;
        }
}

std::vector<Object> PACMAN::Pacman::getObjectList() const
{
    return (_objectList);
}

int PACMAN::Pacman::getScore() const
{
    return (_score);
}

int PACMAN::Pacman::getLives() const
{
    return _lives;
}

int PACMAN::Pacman::getWave() const
{
    return _wave;
}

int PACMAN::Pacman::getTime() const
{
    return _timer;
}