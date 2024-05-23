/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** highscore
*/

#include "IArcade.hpp"

std::string parseName(std::vector<std::string> fileVector, int index)
{
    std::string name;

    name = fileVector[index].substr(0, fileVector[index].find(' '));
    return (name);
}

int parseScore(std::vector<std::string> fileVector, int index)
{
    std::string scoreString;
    size_t posNum = 0;
    size_t numLen = 0;
    int spaceCounter = 0;

    for (int i = 0; i != fileVector[index].size(); i++) {
        if (fileVector[index][i] == ' ') {
            posNum = i + 1;
            break;
        }
    }
    if (posNum == 0)
        return (0);
    for (int i = posNum; i != fileVector[index].size(); i++, numLen++) {
        if (fileVector[index][i] == ' ')
            break;
    }
    scoreString = fileVector[index].substr(posNum, numLen);
    return (std::stoi(scoreString));
}

std::string parseGameName(std::vector<std::string> fileVector, int index)
{
    std::string game;

    std::reverse(fileVector[index].begin(), fileVector[index].end());
    game = fileVector[index].substr(0, fileVector[index].find(' '));
    std::reverse(game.begin(), game.end());
    return (game);
}

std::vector<PlayerScore_s> IArcade::parseHighScore(std::string filename)
{
    std::vector<std::string> fileVector = parseFile(filename);
    std::vector<PlayerScore_s> Vector;
    PlayerScore_s tmp;

    for (int i = 0; i != fileVector.size(); i++) {
        tmp.name = parseName(fileVector, i);
        tmp.score = parseScore(fileVector, i);
        tmp.game = parseGameName(fileVector, i);
        Vector.push_back(tmp);
    }
    return (Vector);
}

std::vector<std::string> IArcade::parseHighScoreText(std::string filename)
{
    std::vector<std::string> fileVector = parseFile(filename);
    std::vector<std::string> tmp;

    tmp.push_back("HIGHSCORE :");
    for (int i = 0; i != fileVector.size(); i++)
        tmp.push_back(fileVector[i]);
    return (tmp);
}