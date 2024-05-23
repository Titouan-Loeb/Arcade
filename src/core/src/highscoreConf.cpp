/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** highScoreConf
*/

#include "IArcade.hpp"

void IArcade::sortHighScore()
{
    if (_playerName.empty())
        _playerName = "ANONYMOUS";
    PlayerScore_s tmp = {_playerName, _score, _currentGameName};

    for (int i = 0; i != _highScoreVector.size(); i++) {
        if (_score > _highScoreVector[i].score) {
            _highScoreVector.insert(_highScoreVector.begin() + i, tmp);
            break;
        }
    }
}

void IArcade::highScoreConf()
{
    sortHighScore();
    std::ofstream file;

    file.open("./conf/highscore.txt");
    for (int i = 0; i != _highScoreVector.size(); i++) {
        file << _highScoreVector[i].name
            << " "
            << _highScoreVector[i].score
            << " "
            << _highScoreVector[i].game
            << "\n";
    }
    file.close();
}