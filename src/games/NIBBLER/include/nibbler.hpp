/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <vector>
#include "IGames.hpp"
#include "Object.hpp"

extern "C" IGames *createGame();

static int nbCreatures = 5;

namespace NIBBLER {

    enum Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    enum NibblerObjectID {
        head,
        body,
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
        enum NibblerObjectID ID;
    } mapLinkObject;

    typedef struct tailNode_t {
        Vect2i pos;
        Vect2i oldPos;
        struct tailNode_t *next;
    } tailNode;

    class Nibbler : public IGames {
        public:
            Nibbler();
            ~Nibbler();
            void update(Key &key);
            std::vector<Object> getObjectList() const;
            void createCreatures();
            void createMap();
            std::vector<std::string> createFileLines(std::string buff);
            Object createBlock(int i, int j);
            int move(Key &key);
            int moveAlone();
            int moveUp();
            int moveDown();
            int moveLeft();
            int moveRight();
            int getScore() const;
            int getLives() const;
            int getWave() const;
            int getTime() const;
            void restart();
            Vect2i calcPosNibbler();
            void increaseTail();
            void tailMap();
            void tailPos();
            bool victory();
            bool defeat();
            int looseLife();
            void updateMap();
            void loadBody();
            Vect2i findBody(Vect2i pos, Vect2i oldPos);
            void addNodeTail(Vect2i pos, Vect2i oldPos);
            void createMap2();
        private:
            clock_t _timerClock;
            float _timerSpeed;
            bool _isEating;
            int _isNotEating;
            int _notEatingSpeed;
            tailNode *_tail;
            int _sizeTail;
            Vect2i _oldpos;
            bool _starOn;
            enum Direction _rectDirection;
    };
}

static const NIBBLER::mapLinkObject mapCharLinksNib[] {
    {'X', NIBBLER::NibblerObjectID::head},
    {'+', NIBBLER::NibblerObjectID::body},
    {' ', NIBBLER::NibblerObjectID::empty},
    {'*', NIBBLER::NibblerObjectID::dot},
    {'Q', NIBBLER::NibblerObjectID::bigDot},
    {'H', NIBBLER::NibblerObjectID::HWall},
    {'V', NIBBLER::NibblerObjectID::VWall},
    {'P', NIBBLER::NibblerObjectID::topLeftCorner},
    {'T', NIBBLER::NibblerObjectID::topRightCorner},
    {'L', NIBBLER::NibblerObjectID::bottomLeftCorner},
    {'J', NIBBLER::NibblerObjectID::bottomRightCorner},
    {'O', NIBBLER::NibblerObjectID::TDownWall},
    {'D', NIBBLER::NibblerObjectID::TRightWall},
    {'Z', NIBBLER::NibblerObjectID::TLeftWall},
    {'Y', NIBBLER::NibblerObjectID::TUpWall},
    {'N', NIBBLER::NibblerObjectID::EndUpWall},
    {'W', NIBBLER::NibblerObjectID::EndDownWall},
    {'C', NIBBLER::NibblerObjectID::EndRightWall},
    {'A', NIBBLER::NibblerObjectID::EndLeftWall},
    {'K', NIBBLER::NibblerObjectID::PinkTopLeftCorner},
    {'U', NIBBLER::NibblerObjectID::PinkHWall},
    {'B', NIBBLER::NibblerObjectID::PinkRightSideHWall}
};

static const int nbLinksNib = 20;

static const Object NibblerObjects[] = {
    {NIBBLER::NibblerObjectID::head, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {48*0, 48*2, 48, 48}, "\"", 2, {-10, -10}},
    {NIBBLER::NibblerObjectID::body, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {48*1, 48*0, 48, 48}, "O", 2, {-10, -10}},
    {NIBBLER::NibblerObjectID::empty, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*4, 32*3, 32, 32}, "#", 14, {0, 0}},
    {NIBBLER::NibblerObjectID::dot, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*0, 32*0, 32, 32}, ".", 1, {0, 0}},
    {NIBBLER::NibblerObjectID::bigDot, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*0, 32*1, 32, 32}, "o", 1, {0, 0}},
    {NIBBLER::NibblerObjectID::VWall, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*0, 32*2, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::HWall, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*0, 32*3, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::topLeftCorner, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*1, 32*0, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::topRightCorner, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*1, 32*1, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::bottomLeftCorner, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*1, 32*2, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::bottomRightCorner, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*1, 32*3, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::TDownWall, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*2, 32*0, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::TRightWall, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*2, 32*1, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::TLeftWall, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*2, 32*2, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::TUpWall, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*2, 32*3, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::EndUpWall, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*3, 32*0, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::EndDownWall, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*3, 32*1, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::EndRightWall, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*3, 32*2, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::EndLeftWall, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*3, 32*3, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::PinkTopLeftCorner, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*4, 32*0, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::PinkHWall, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*4, 32*1, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::PinkRightSideHWall, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*4, 32*2, 32, 32}, "#", 18, {0, 0}},
    {NIBBLER::NibblerObjectID::wayOut, "assets/nibbler_srpite_sheet.png", {0, 0}, {0, 0}, {96 + 32*4, 32*3, 32, 32}, "#", 18, {0, 0}}
};
#endif /* !NIBBLER_HPP_ */
