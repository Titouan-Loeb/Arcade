/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** pos
*/

#include "pacman.hpp"

Vect2i PACMAN::Pacman::calcPosPacMan()
{
    int i = 0;
    int j = 0;

    for (i = 0; i < _map.size(); i++)
        for (j = 0; j < _map[i].size(); j++)
            if (_map[i][j] == 'X')
                return (Vect2i{i, j});
    return (Vect2i{13, 10});
}