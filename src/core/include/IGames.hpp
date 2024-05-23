/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** IGames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_

#include <vector>
#include <string>
#include <ostream>
#include <iostream>
#include <ctime>
#include "Object.hpp"

class IGames {
    public:
        virtual ~IGames() = default;
        virtual void update(Key &key) = 0;
        virtual std::vector<Object> getObjectList() const = 0;
        virtual int move(Key &key) = 0;
        virtual int moveAlone() = 0;
        virtual int moveUp() = 0;
        virtual int moveDown() = 0;
        virtual int moveLeft() = 0;
        virtual int moveRight() = 0;
        virtual int getScore() const = 0;
        virtual int getLives() const = 0;
        virtual int getWave() const = 0;
        virtual int getTime() const = 0;
        virtual void restart() = 0;
        virtual bool victory() = 0;
        virtual bool defeat() = 0;
        virtual int looseLife() = 0;
    protected:
        clock_t _clock;
        std::vector<Object> _objectList;
        std::vector<std::string> _map;
        int _input;
        int _score;
        int _direction;
        Vect2i _pos;
        bool _infinLoop;
        int _wave;
        int _lives;
        float _speed;
        int _timer;
};

#endif /* !IGAMES_HPP_ */
