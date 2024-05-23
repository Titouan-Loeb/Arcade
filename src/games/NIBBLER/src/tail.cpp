/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** tail
*/

#include "nibbler.hpp"

void NIBBLER::Nibbler::tailPos()
{
    tailNode *current = _tail;
    Vect2i pos1 = _pos;

    for (; current != NULL; current = current->next) {
        current->oldPos = current->pos;
        current->pos = pos1;
        pos1 = current->oldPos;
    }
}

void NIBBLER::Nibbler::tailMap()
{
    tailNode *current = _tail;

    for (; current != NULL; current = current->next) {
        _map[current->pos.x][current->pos.y] = '+';
        _map[current->oldPos.x][current->oldPos.y] = ' ';
    }
}

void NIBBLER::Nibbler::increaseTail()
{
    tailNode *current = _tail;
    tailNode *newNode = new tailNode;


    if (_sizeTail == 0) {
        newNode->next = NULL;
        newNode->pos = _oldpos;
        newNode->oldPos = {0, 0};
        _tail = newNode;
    }
    else {
        for (; current->next != NULL; current = current->next);
        newNode->pos = current->oldPos;
        newNode->oldPos = {0, 0};
        newNode->next = NULL;
        current->next = newNode;
    }
    _sizeTail++;
}