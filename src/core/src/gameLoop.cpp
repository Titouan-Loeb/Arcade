/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** gameLoop
*/

#include "IArcade.hpp"

void IArcade::fillCurrentGame(int gameID)
{
    if (_game != nullptr)
        delete (_game);
    if (gameID == PACMAN_ID) {
        _game = getGame("lib/arcade_pacman.so");
        _currentGameName = "Pacman";
    }
    else if (gameID == NIBBLER_ID) {
        _game = getGame("lib/arcade_nibbler.so");
        _currentGameName = "Nibbler";
    }
}

void IArcade::handleGameInput(int gameID)
{
    if (_input.code == KeyF6)
        menuLoop();
    if (_input.code == KeyF3 || _input.code == KeyF4) {
        if (gameID == PACMAN_ID)
            fillCurrentGame(NIBBLER_ID);
        else if (gameID == NIBBLER_ID)
            fillCurrentGame(PACMAN_ID);
    }
    if (_input.code == KeyP && _game->getLives() != 0) {
        if (_pause == true)
            _pause = false;
        else if (_pause == false)
            _pause = true;
    }
    if (_input.code == KeyF5)
        _game->restart();
}

void IArcade::gameLoop(int gameID)
{
    std::vector<Object> objectList;
    int formattedTime = 0;

    fillCurrentGame(gameID);
    while (_input.code != KeyEscape) {
        handleLibChange();
        _lib->getInput(_input);
        handleGameInput(gameID);
        _lib->createObjects(gameID);
        _lib->displayBackground();
        displayStringMenu("GAME : ", {300, 140}, {2, 2}, 10, 12);
        displayStringMenu(_choosenGame, {400, 140}, {10, 2}, ((_choosenGame == "PACMAN") ? 1 : 21), 12);
        displayStringMenu("PLAYER : ", {300, 100}, {2, 3}, 10, 12);
        displayStringMenu((_playerName == "") ? "ANONYMOUS" : _playerName, {400, 100}, {11, 3}, 8, 12);
        displayStringMenu("SCORE : ", {300, 180}, {2, 4}, 10, 12);
        displayStringMenu(std::to_string(_game->getScore()), {400, 180}, {11, 4}, 8, 12);
        displayStringMenu("LIB : ", {300, 120}, {2, 6}, 10, 12);
        displayStringMenu(_lib->getLibName(), {380, 120}, {9, 6}, 7, 12);
        displayStringMenu("WAVE : ", {300, 200}, {2, 8}, 10, 12);
        displayStringMenu(std::to_string(_game->getWave()), {400, 200}, {9, 8}, 1, 12);
        displayStringMenu("LIVES : ", {300, 220}, {2, 9}, 10, 12);
        displayStringMenu(std::to_string(_game->getLives()), {400, 220}, {10, 9}, 1, 12);
        if (_choosenGame == "NIBBLER") {
            displayStringMenu("TIME : ", {300, 260}, {12, 9}, 10, 12);
            if (_game->getTime() >= 100) {
                formattedTime = (_game->getTime() / 10) * 10;
                displayStringMenu(std::to_string(formattedTime), {400, 260}, {20, 9}, 1, 12);
            }
            if (_game->getTime() < 100) {
                formattedTime = (_game->getTime() / 10) * 10;
                displayStringMenu(std::to_string(formattedTime), {400, 260}, {20, 9}, 1, 12);
                displayStringMenu(" ", {300, 400}, {22, 9}, 1, 12);
                if (_game->getTime() < 9)
                    displayStringMenu(" ", {300, 400}, {21, 9}, 1, 12);
            }
        }
        if (_game->getLives() == 0) {
            displayStringMenu("GAME OVER", {1350, 400}, {50, 20}, 10, 30);
            displayStringMenu("press escape to exit", {1360, 450}, {45, 22}, 10, 12);
        }
        if (_pause == false && _game->getLives() > 0)
            _game->update(_input);
        else if (_pause == true)
            displayStringMenu("PAUSE", {1350, 400}, {5, 5}, 10, 30);
        objectList = _game->getObjectList();
        for (int i = 0; i < objectList.size(); i++)
            _lib->displayObject(objectList[i]);
        _lib->displayWindow();
        _lib->destroyObjects();
    }
    _input.code = KeyNone;
    _score = _game->getScore();
}