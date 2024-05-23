/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** ILib
*/

#ifndef ILIB_HPP_
#define ILIB_HPP_

#include <iostream>
#include <vector>
#include "ObjectInfo.hpp"
#include "Object.hpp"

enum {
    PACMAN_ID = 1,
    NIBBLER_ID = 2
};

static const std::vector<std::vector<std::string>> texturesPaths =
{
    {"assets/background_arcade_2.png"}, //bg
    {"assets/pacman_srpite_sheet.png"}, // walls
    {"assets/nibbler_sprite_sheet.png"} //nibbler
};

class ILib {
    public:
        virtual ~ILib() = default;
        virtual void init() = 0;
        virtual void displayObject(Object &object) = 0;
        virtual void displayBackground() = 0;
        virtual void displayWindow() = 0;
        virtual void destroyWindow() = 0;
        virtual void putText(Text &text) = 0;
        virtual void createObjects(int &gameID) = 0;
        // virtual void getInput(Key *input) = 0;
        virtual void getInput(Key &input) = 0;
        virtual std::string getLibName() = 0;
        virtual void clearWindow() = 0;
        virtual void destroyObjects() = 0;
        // virtual void createObjects() = 0;
        // virtual void destroyObjects() = 0;
        // virtual void setPositions(/*iterateur de la lib*/) = 0;
        // virtual void animePlayer() = 0;
    protected:
    private:
};

#endif /* !ILIB_HPP_ */
