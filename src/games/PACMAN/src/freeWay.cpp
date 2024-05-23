/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** freeWay
*/

#include "pacman.hpp"

int isUpFree(Vect2i pos, std::vector<std::string> map)
{
    return (map[pos.y - 1][pos.x] == 'X' ||
            map[pos.y - 1][pos.x] == '*' ||
            map[pos.y - 1][pos.x] == ' ' ||
            map[pos.y - 1][pos.x] == 'U' ||
            map[pos.y - 1][pos.x] == 'Q');
}

int isDownFree(Vect2i pos, std::vector<std::string> map)
{
    return (map[pos.y + 1][pos.x] == 'X' ||
            map[pos.y + 1][pos.x] == '*' ||
            map[pos.y + 1][pos.x] == ' ' ||
            map[pos.y + 1][pos.x] == 'U' ||
            map[pos.y + 1][pos.x] == 'Q');
}

int isLeftFree(Vect2i pos, std::vector<std::string> map)
{
    return (map[pos.y][pos.x - 1] == 'X' ||
            map[pos.y][pos.x - 1] == '*' ||
            map[pos.y][pos.x - 1] == ' ' ||
            map[pos.y][pos.x - 1] == 'U' ||
            map[pos.y][pos.x - 1] == 'Q');
}

int isRightFree(Vect2i pos, std::vector<std::string> map)
{
    return (map[pos.y][pos.x + 1] == 'X' ||
            map[pos.y][pos.x + 1] == '*' ||
            map[pos.y][pos.x + 1] == ' ' ||
            map[pos.y][pos.x + 1] == 'U' ||
            map[pos.y][pos.x + 1] == 'Q');
}