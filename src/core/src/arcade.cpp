/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** Arcade
*/

#include "IArcade.hpp"

IArcade::IArcade(const char *lib)
{
    _lib = getLib(lib);
    _libs = getLibs();
    _libIndex = getLibIndex(lib);
    _lib = _libs[_libIndex];
    _game = nullptr;
    _gameNameVector = {"PACMAN", "NIBBLER"};
    _currentGameName = "";
    _score = 0;
    _pause = false;
    _arrowUp = true;
    _run = true;
    _game_run = true;
    _commandText = parseFile("./conf/command.txt");
    _highScoreVector = parseHighScore("./conf/highscore.txt");
    _scoreTextVector = parseHighScoreText("./conf/highscore.txt");
    _input = (Key){StateNone, KeyNone};
}

IArcade::~IArcade()
{
}

void IArcade::handleInput()
{
    if ((_input.code == KeyArrowUp || _input.code == KeyArrowDown) && _arrowUp == true)
        _arrowUp = false;
    else if ((_input.code == KeyArrowUp || _input.code == KeyArrowDown) && _arrowUp == false)
        _arrowUp = true;
    if (_input.code == KeyEnter && _arrowUp == true) {
        _choosenGame = "PACMAN";
        _lib->clearWindow();
        gameLoop(PACMAN_ID);
        _lib->clearWindow();
    }
    else if (_input.code == KeyEnter && _arrowUp == false) {
        _choosenGame = "NIBBLER";
        _lib->clearWindow();
        gameLoop(NIBBLER_ID);
        _lib->clearWindow();
    }
    if (_input.code >= KeyA && _input.code <= KeyZ && _input.state == KeyPressed && _playerName.length() < 10) {
        _playerName += 'A' + _input.code - KeyA;
    }
    if (_input.code == KeyBackspace && _playerName.c_str() != NULL && _input.state == KeyPressed)
        _playerName = _playerName.substr(0, _playerName.size() - 1);
}

void IArcade::menuLoop()
{
    while (_input.code != KeyEscape) {
        _lib->getInput(_input);
        _lib->displayBackground();
        handleInput();
        handleLibChange();
        displayArrowMenu();
        displayStringMenu("PLAYER : ", {300, 100}, {2, 2}, 10, 12);
        displayStringMenu(_playerName, {400, 100}, {12, 2}, 8, 12);
        displayStringMenu("LIB : ", {300, 120}, {2, 3}, 10, 12);
        displayStringMenu(_lib->getLibName(), {380, 120}, {9, 3}, 7, 12);
        displayStringMenu("CONTROLS :", {300, 670}, {2, 31}, 10, 12);
        displayTextMenu(_commandText, {300, 690}, {2, 32}, 1, 12);
        displayTextMenu(_scoreTextVector, {1350, 100}, {60, 1}, 2, 12);
        displayTextMenu(_gameNameVector, {910, 300}, {30, 14}, 3, 12);
        _lib->displayWindow();
    }
}

void IArcade::coreLoop()
{
    _lib->init();
    menuLoop();
    _lib->destroyWindow();
    highScoreConf();
}