/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** libSFML
*/

#ifndef LIBSFML_HPP_
#define LIBSFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Config.hpp>
#include <vector>
#include "ILib.hpp"
#include "elemSFML.hpp"

extern "C" ILib *createLibrary();

namespace SFML {

    typedef struct TextSFML_t
    {
        sf::Text text;
        sf::Vector2f pos;
        sf::Font font;
        std::string fontPath = "";
    } TextSFML;

    class LibSFML : public ILib {
    public:
        LibSFML(/*game*/);
        ~LibSFML();
        void init();
        void displayObject(Object &object);
        void displayBackground();
        void displayWindow();
        void destroyWindow();
        void putText(Text &text);
        void getInput(Key &input);
        void createObjects(int &gameID);
        // void getInput(Key *input);
        std::string getLibName();
        void clearWindow();
        void destroyObjects();
        // void createObjects(int &libID);
        // void destroyObjects();
        // void setPositions(/*iterateur de la lib*/);
        // void animePlayer();
    protected:
    private:
        elemSFML *_background;
        elemSFML *_spriteGame;
        TextSFML _text;
        sf::RenderWindow _window;
        sf::Event _event;
        sf::VideoMode _videoMode;
    };
}

#endif /* !LIBSFML_HPP_ */
