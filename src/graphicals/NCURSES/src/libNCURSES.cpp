/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** ncurses
*/

#include "libNCURSES.hpp"

extern "C" ILib *createLibrary()
{
    return (dynamic_cast<ILib *>(new LibNCURSES));
}

std::string LibNCURSES::getLibName()
{
    return ("ncurses");
}

void LibNCURSES::init()
{
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    set_escdelay(0);
    start_color();
    for (int i = 1; i != colorsTabSize; i++)
        init_pair(i, colorsTab[i].foreground, colorsTab[i].background);
}

LibNCURSES::LibNCURSES()
{
}

LibNCURSES::~LibNCURSES()
{
    refresh();
    endwin();
}

void LibNCURSES::displayObject(Object &object)
{
    attron(COLOR_PAIR(object.colorID));
    mvprintw(10 + object.iPos.y, 5 + object.iPos.x, object.character);
    attroff(COLOR_PAIR(object.colorID));
}

void LibNCURSES::displayBackground()
{

}

void LibNCURSES::displayWindow()
{
}

void LibNCURSES::clearWindow()
{
    clear();
}

void LibNCURSES::destroyWindow()
{
    refresh();
    endwin();
}

void LibNCURSES::putText(Text &text)
{
    refresh();
    // if (LINES < 40 || COLS < 80) {
    //     attron(COLOR_PAIR(1) | A_BOLD);
    //     mvprintw(LINES/2,  COLS/2 - 12, "Terminal is too small...");
    //     attroff(COLOR_PAIR(1) | A_BOLD);
    // }
    // else {
        attron(COLOR_PAIR(text.color));
        mvprintw(text.intPos.y, text.intPos.x, text.text.c_str());
        attroff(COLOR_PAIR(text.color));
    // }
}

void LibNCURSES::getInput(Key &input)
{
    int ch = -1;

    input.code = KeyNone;
    input.state = StateNone;
    ch = getch();
    if (ch != -1) {
        erase();
        input.state = KeyPressed;
    }
    for (int i = 0; i != inputTabSize; i++) {
        if (ch == inputTab[i]) {
            input.code = (KeyCode)i;
        }
    }
}

void LibNCURSES::createObjects(int &gameID)
{
}

void LibNCURSES::destroyObjects()
{
}