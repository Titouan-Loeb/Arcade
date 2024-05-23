/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** ncurses
*/

#ifndef LIBNCURSES_HPP_
#define LIBNCURSES_HPP_

#include <ncurses.h>
#include <vector>
#include <map>
#include "../../../core/include/ILib.hpp"

extern "C" ILib *createLibrary();

typedef struct colors_t
{
    int foreground;
    int background;
} colors;

static const colors colorsTab[] = {
    {COLOR_YELLOW, COLOR_YELLOW},
    {226, COLOR_BLACK}, // pacman 1
    {COLOR_WHITE, 196}, // redghost 2
    {COLOR_WHITE, 218}, // pinkghost 3
    {COLOR_WHITE, 51}, // blueghost 4
    {COLOR_WHITE, 208}, // orangeghost 5
    {88, COLOR_BLACK}, // cherry 6
    {196, COLOR_BLACK}, // strawberry 7
    {217, COLOR_BLACK}, // peach 8
    {160, COLOR_BLACK}, // apple 9
    {82, COLOR_BLACK}, // pineapple 10
    {21, COLOR_BLACK}, // galaxian 11
    {220, COLOR_BLACK}, // bell 12
    {178, COLOR_BLACK}, // key 13
    {COLOR_BLACK, COLOR_BLACK}, //empty 14
    {COLOR_BLUE, COLOR_BLUE}, // wall 15
    {COLOR_WHITE, COLOR_BLACK}, // dot 16
    {COLOR_WHITE, COLOR_WHITE}, //pink wall 17
    {13, 13}, //nibbler wall 18
    {218, COLOR_BLACK}, //19 Highscore text 1
    {51, COLOR_BLACK}, //20 High score text 2
    {13, COLOR_BLACK},
    {COLOR_WHITE, 21},
};

static const int colorsTabSize = 22;

static const int inputTab[] = {
    -1,
    259,
    258,
    260,
    261,
    27,
    32,
    265,
    266,
    267,
    268,
    269,
    270,
    271,
    272,
    273,
    274,
    275,
    276,
    97,
    98,
    99,
    100,
    101,
    102,
    103,
    104,
    105,
    106,
    107,
    108,
    109,
    110,
    111,
    112,
    113,
    114,
    115,
    116,
    117,
    118,
    119,
    120,
    121,
    122,
    263,
    10
};

static const int inputTabSize = 47;

class LibNCURSES : public ILib {
public:
    LibNCURSES(/*game*/);
    ~LibNCURSES();
    void init();
    void displayObject(Object &object);
    void displayBackground();
    void displayWindow();
    void destroyWindow();
    void putText(Text &text);
    void getInput(Key &input);
    void createObjects(int &gameID);
    std::string getLibName();
    void clearWindow();
    void destroyObjects();
    // void destroyObjects();
    // void setPositions(/*iterateur de la lib*/);
    // void animePlayer();
protected:
private:
};

#endif /* !LIBNCURSES_HPP_ */