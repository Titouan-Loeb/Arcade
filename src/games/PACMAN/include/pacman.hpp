/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <vector>
#include "IGames.hpp"
#include "Object.hpp"
#include <stdlib.h>
#include <time.h>

extern "C" IGames *createGame();

static int nbCreatures = 5;

namespace PACMAN {

    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    enum PacmanObjectID {
        pacman,
        redGhost,
        pinkGhost,
        blueGhost,
        orangeGhost,
        scaredGhost,
        cherry,
        strawberry,
        peach,
        apple,
        pineapple,
        galaxian,
        bell,
        key,
        empty,
        dot,
        bigDot,
        VWall,
        HWall,
        topLeftCorner,
        topRightCorner,
        bottomLeftCorner,
        bottomRightCorner,
        TDownWall,
        TRightWall,
        TLeftWall,
        TUpWall,
        EndUpWall,
        EndDownWall,
        EndRightWall,
        EndLeftWall,
        PinkTopLeftCorner,
        PinkHWall,
        PinkRightSideHWall,
        wayOut
    };
    typedef struct mapLinkObject_t {
        char lettre;
        enum PacmanObjectID ID;
    } mapLinkObject;

    class Pacman : public IGames {
        public:
            Pacman();
            ~Pacman();
            std::vector<Object> getObjectList() const;
            void createCreatures();
            void createMap();
            void update(Key &key);
            std::vector<std::string> createFileLines(std::string buff);
            Object createBlock(int i, int j);
            int move(Key &key);
            int moveAlone();
            int moveUp();
            int moveDown();
            int moveLeft();
            int moveRight();
            Vect2i calcPosPacMan();
            int getScore() const;
            int getLives() const;
            int getWave() const;
            int getTime() const;
            void restart();
            bool victory();
            bool defeat();
            int looseLife();
            void updateMap();
            void animEntities(int k);
            int enemyMoveUp(char character, int id, Vect2i enemyPos);
            int enemyMoveDown(char character, int id, Vect2i enemyPos);
            int enemyMoveLeft(char character, int id, Vect2i enemyPos);
            int enemyMoveRight(char character, int id, Vect2i enemyPos);
            int moveEnemy(char character, int id, int direction, Vect2i enemyPos);
            int enemyMovement(char character, int id, bool allowStepBack);
            Vect2i getEnemyPosition(char id);
            int enemyMoveHandling();
            enum Direction oppositeDirection(enum Direction direction);
            int chooseDirection(char character, int id, bool allowStepBack, int numWay);
            void eatBigDot();
            void scareEnemy(int id, int k);
            void enemyLessScared();
            int eatEnemy(int id, Vect2i posPacman, Vect2i posEnemy, int dir);
            int eatEnemy(int id, Vect2i posEnemy, char tmpChar);
        protected:
        private:
            enum Direction _rectDirection;
            enum Direction _enemyDirection[4];
            int _scaredEnemy[4];
            int _animPacman;
            char _oldCharTab[4];
            int _freeWay[4];
    };
}

int isUpFree(Vect2i pos, std::vector<std::string> map);
int isDownFree(Vect2i pos, std::vector<std::string> map);
int isLeftFree(Vect2i pos, std::vector<std::string> map);
int isRightFree(Vect2i pos, std::vector<std::string> map);

static const PACMAN::mapLinkObject mapCharLinks[] {
    {' ', PACMAN::PacmanObjectID::empty},
    {'*', PACMAN::PacmanObjectID::dot},
    {'Q', PACMAN::PacmanObjectID::bigDot},
    {'H', PACMAN::PacmanObjectID::HWall},
    {'V', PACMAN::PacmanObjectID::VWall},
    {'P', PACMAN::PacmanObjectID::topLeftCorner},
    {'T', PACMAN::PacmanObjectID::topRightCorner},
    {'L', PACMAN::PacmanObjectID::bottomLeftCorner},
    {'J', PACMAN::PacmanObjectID::bottomRightCorner},
    {'O', PACMAN::PacmanObjectID::TDownWall},
    {'D', PACMAN::PacmanObjectID::TRightWall},
    {'Z', PACMAN::PacmanObjectID::TLeftWall},
    {'Y', PACMAN::PacmanObjectID::TUpWall},
    {'N', PACMAN::PacmanObjectID::EndUpWall},
    {'W', PACMAN::PacmanObjectID::EndDownWall},
    {'C', PACMAN::PacmanObjectID::EndRightWall},
    {'A', PACMAN::PacmanObjectID::EndLeftWall},
    {'K', PACMAN::PacmanObjectID::PinkTopLeftCorner},
    {'U', PACMAN::PacmanObjectID::PinkHWall},
    {'B', PACMAN::PacmanObjectID::PinkRightSideHWall},
    {'S', PACMAN::PacmanObjectID::wayOut},
    {'X', PACMAN::PacmanObjectID::pacman},
    {'1', PACMAN::PacmanObjectID::redGhost},
    {'2', PACMAN::PacmanObjectID::pinkGhost},
    {'3', PACMAN::PacmanObjectID::blueGhost},
    {'4', PACMAN::PacmanObjectID::orangeGhost},
};

static const int nbLinks = 26;

static const Object PacmanObjects[] = {
    {PACMAN::PacmanObjectID::pacman, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {48*1, 48*6, 48, 48}, "O", 1, {-10, -10}},
    {PACMAN::PacmanObjectID::redGhost, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {48*3, 48*0, 48, 48}, "\"", 2, {-10, -10}},
    {PACMAN::PacmanObjectID::pinkGhost, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {48*4, 48*0, 48, 48}, "\"", 3, {-10, -10}},
    {PACMAN::PacmanObjectID::blueGhost, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {48*5, 48*0, 48, 48}, "\"", 4, {-10, -10}},
    {PACMAN::PacmanObjectID::orangeGhost, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {48*6, 48*0, 48, 48}, "\"", 5, {-10, -10}},
    {PACMAN::PacmanObjectID::scaredGhost, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {48*7, 48*0, 48, 48}, "\"", 5, {-10, -10}},
    {PACMAN::PacmanObjectID::cherry, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {48*2, 48*0, 48, 48}, "%", 6, {-10, -10}},
    {PACMAN::PacmanObjectID::strawberry, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {48*2, 48*1, 48, 48}, "U", 7, {-10, -10}},
    {PACMAN::PacmanObjectID::peach, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {48*2, 48*2, 48, 48}, "0", 8, {-10, -10}},
    {PACMAN::PacmanObjectID::apple, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {48*2, 48*3, 48, 48}, "o", 9, {-10, -10}},
    {PACMAN::PacmanObjectID::pineapple, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {48*2, 48*4, 48, 48}, "o", 10, {-10, -10}},
    {PACMAN::PacmanObjectID::galaxian, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {48*2, 48*5, 48, 48}, "^", 11, {-10, -10}},
    {PACMAN::PacmanObjectID::bell, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {48*2, 48*6, 48, 48}, "8", 12, {-10, -10}},
    {PACMAN::PacmanObjectID::key, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {48*2, 48*7, 48, 48}, "K", 13, {-10, -10}},
    {PACMAN::PacmanObjectID::empty, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*4, 32*3, 32, 32}, " ", 14, {0, 0}},
    {PACMAN::PacmanObjectID::dot, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*0, 32*0, 32, 32}, ".", 16, {0, 0}},
    {PACMAN::PacmanObjectID::bigDot, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*0, 32*1, 32, 32}, "o", 16, {0, 0}},
    {PACMAN::PacmanObjectID::VWall, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*0, 32*2, 32, 32}, "#", 15, {0, 0}},
    {PACMAN::PacmanObjectID::HWall, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*0, 32*3, 32, 32}, "#", 15, {0, 0}},
    {PACMAN::PacmanObjectID::topLeftCorner, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*1, 32*0, 32, 32}, "#", 15, {0, 0}},
    {PACMAN::PacmanObjectID::topRightCorner, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*1, 32*1, 32, 32}, "#", 15, {0, 0}},
    {PACMAN::PacmanObjectID::bottomLeftCorner, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*1, 32*2, 32, 32}, "#", 15, {0, 0}},
    {PACMAN::PacmanObjectID::bottomRightCorner, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*1, 32*3, 32, 32}, "#", 15, {0, 0}},
    {PACMAN::PacmanObjectID::TDownWall, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*2, 32*0, 32, 32}, "#", 15, {0, 0}},
    {PACMAN::PacmanObjectID::TRightWall, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*2, 32*1, 32, 32}, "#", 15, {0, 0}},
    {PACMAN::PacmanObjectID::TLeftWall, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*2, 32*2, 32, 32}, "#", 15, {0, 0}},
    {PACMAN::PacmanObjectID::TUpWall, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*2, 32*3, 32, 32}, "#", 15, {0, 0}},
    {PACMAN::PacmanObjectID::EndUpWall, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*3, 32*0, 32, 32}, "#", 15, {0, 0}},
    {PACMAN::PacmanObjectID::EndDownWall, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*3, 32*1, 32, 32}, "#", 15, {0, 0}},
    {PACMAN::PacmanObjectID::EndRightWall, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*3, 32*2, 32, 32}, "#", 15, {0, 0}},
    {PACMAN::PacmanObjectID::EndLeftWall, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*3, 32*3, 32, 32}, "#", 15, {0, 0}},
    {PACMAN::PacmanObjectID::PinkTopLeftCorner, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*4, 32*0, 32, 32}, "#", 15, {0, 0}},
    {PACMAN::PacmanObjectID::PinkHWall, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*4, 32*1, 32, 32}, "-", 17, {0, 0}},
    {PACMAN::PacmanObjectID::PinkRightSideHWall, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*4, 32*2, 32, 32}, "-", 17, {0, 0}},
    {PACMAN::PacmanObjectID::wayOut, "assets/pacman_srpite_sheet.png", {0, 0}, {0, 0}, {480 + 32*4, 32*3, 32, 32}, " ", 14, {0, 0}}
};
#endif /* !PACMAN_HPP_ */