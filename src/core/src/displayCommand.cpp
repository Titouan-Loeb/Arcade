/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** displayCommand
*/

#include "ObjectInfo.hpp"
#include "IArcade.hpp"

int IArcade::getColor(int ID, int i)
{
    if (ID == 3) {
        if (_arrowUp == true && i == 0)
            return 1;
        else if (_arrowUp == false && i == 1)
            return 1;
    }
    if (ID == 2) {
        if (i == 0)
            return 10;
        else if (i % 2 == 0)
            return 19;
        else
            return 20;
    }
    return 16;
}

void IArcade::displayTextMenu(std::vector<std::string> vector, Vect2f posFloat, Vect2i posInt, int ID, int size)
{
    Text tmp;
    int endLoop = (ID == 2) ? 6 : vector.size();

    for (int i = 0; i != endLoop; i++) {
        tmp.fontPath = "./assets/ARCADE_N.TTF";
        posFloat.y = posFloat.y + 18;
        posInt.y = posInt.y + 1;
        tmp.floatPos = posFloat;
        tmp.intPos = posInt;
        tmp.text = vector[i];
        tmp.color = getColor(ID, i);
        tmp.size = size;
        _lib->putText(tmp);
    }
}

void IArcade::displayStringMenu(std::string string, Vect2f posFloat, Vect2i posInt, int color, int size)
{
    Text tmp;

    tmp.fontPath = "./assets/ARCADE_N.TTF";
    tmp.floatPos = posFloat;
    tmp.intPos = posInt;
    tmp.text = string;
    tmp.color = color;
    tmp.size = size;
    _lib->putText(tmp);
}

void IArcade::displayArrowMenu()
{
    Text tmp;

    tmp.fontPath = "./assets/ARCADE_N.TTF";
    tmp.text = ">";
    tmp.floatPos.x = 890;
    tmp.intPos.x = 28;
    tmp.size = 12;
    if (_arrowUp == true) {
        tmp.floatPos.y = 320;
        tmp.intPos.y = 15;
    }
    else {
        tmp.floatPos.y = 337;
        tmp.intPos.y = 16;
    }
    tmp.color = 1;
    _lib->putText(tmp);
}