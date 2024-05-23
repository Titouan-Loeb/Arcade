/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** pos
*/

#include "nibbler.hpp"

Vect2i NIBBLER::Nibbler::calcPosNibbler()
{
    int i = 0;
    int j = 0;

    for (i = 0; i < _map.size(); i++)
        for (j = 0; j < _map[i].size(); j++)
            if (_map[i][j] == 'X')
                return (Vect2i{i, j});
    return (Vect2i{13, 10});
}