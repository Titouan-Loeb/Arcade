/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** IArcade
*/

#ifndef IARCADE_HPP_
#define IARCADE_HPP_

#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>
#include <dlfcn.h>

#include "ILib.hpp"
#include "ObjectInfo.hpp"
#include "IGames.hpp"

typedef struct PlayerScore_t
{
    std::string name;
    int score;
    std::string game;
} PlayerScore_s;

class IArcade {
    public:
        IArcade(const char *lib);
        ~IArcade();
        ILib *getLib(const char *lib);
        IGames *getGame(const char *libname);
        std::vector<ILib *> getLibs();
        int getLibIndex(const char * lib);
        void coreLoop();
        void gameLoop(int gameID);
        void menuLoop();
        std::vector<std::string> parseFile(std::string filename);
        std::vector<PlayerScore_s> parseHighScore(std::string filename);
        std::vector<std::string> parseHighScoreText(std::string filename);
        void handleInput();
        void displayTextMenu(std::vector<std::string> vector, Vect2f posFloat, Vect2i posInt, int ID, int size);
        void displayStringMenu(std::string string, Vect2f posFloat, Vect2i posInt, int color, int size);
        void displayArrowMenu();
        void highScoreConf();
        void sortHighScore();
        void handleLibChange();
        void handleGameInput(int gameID);
        void fillCurrentGame(int gameID);
        int getColor(int, int);
    private:
        bool _arrowUp;
        bool _run;
        bool _game_run;
        std::string _currentGameName;
        std::vector<std::string> _gameNameVector;
        std::string _playerName;
        std::vector<std::string> _commandText;
        std::vector<PlayerScore_s> _highScoreVector;
        std::vector<std::string> _scoreTextVector;
        int _score;
        Key _input;
        IGames *_game;
        int _gameID;
        int _libIndex;
        ILib *_lib;
        std::vector<ILib *> _libs;
        std::string _choosenGame;
        bool _pause;
};

#endif /* !IARCADE_HPP_ */
