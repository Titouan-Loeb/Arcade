/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** libSFML
*/

#include "libSFML.hpp"
#include "elemSFML.hpp"
#include "SFML/Window/Keyboard.hpp"

extern "C" ILib *createLibrary()
{
    return (dynamic_cast<ILib *>(new SFML::LibSFML));
}

std::string SFML::LibSFML::getLibName()
{
    return ("sfml");
}

void SFML::LibSFML::init()
{
    _videoMode = (sf::VideoMode){1920, 1080, 32};
    _window.create(_videoMode, "Arcade", sf::Style::Fullscreen);
    _background = new elemSFML(texturesPaths[0][0], sf::IntRect(
        0, 0, _videoMode.width, _videoMode.height), sf::Vector2f(0, 0));
}

SFML::LibSFML::LibSFML()
{
}

SFML::LibSFML::~LibSFML()
{
}

void SFML::LibSFML::displayObject(Object &object)
{
    _spriteGame->setElemSFML(object.fPos, object.rect);
    _window.draw(_spriteGame->getSprite());
}

void SFML::LibSFML::displayBackground()
{
    _window.draw(_background->getSprite());
}

void SFML::LibSFML::displayWindow()
{
    _window.display();
}

void SFML::LibSFML::destroyWindow()
{
    _window.close();
    delete _background;
}

void SFML::LibSFML::clearWindow()
{
    _window.clear();
}

void SFML::LibSFML::putText(Text &text)
{
    if (_text.fontPath != text.fontPath) {
        _text.fontPath = text.fontPath;
        _text.font.loadFromFile(_text.fontPath);
    }
    _text.pos.x = text.floatPos.x;
    _text.pos.y = text.floatPos.y;
    _text.text.setFont(_text.font);
    _text.text.setString(text.text);
    _text.text.setCharacterSize(text.size);
    _text.text.setPosition(_text.pos);
    _window.draw(_text.text);
}

void SFML::LibSFML::getInput(Key &input)
{
    input.code = KeyNone;
    input.state = StateNone;
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::EventType::KeyPressed)
            input.state = KeyPressed;
        else if (_event.type == sf::Event::EventType::KeyReleased)
            input.state = KeyReleased;
        if (_event.type == sf::Event::EventType::Closed)
            input.code = KeyEscape;
        if (_event.key.code == sf::Keyboard::Key::Return)
            input.code = KeyEnter;
        for (int i = 0; i < nbKeys; i++) {
            if (_event.key.code == sfKeyCodes[i] && input.state == KeyPressed && input.code == KeyNone) {
                input.code = (KeyCode)i;
            }
        }
    }
}

void SFML::LibSFML::createObjects(int &gameID)
{
    _spriteGame = new elemSFML(texturesPaths[gameID][0], sf::IntRect(
        0, 0, _videoMode.width, _videoMode.height), sf::Vector2f(0, 0));
}

void SFML::LibSFML::destroyObjects()
{
    delete(_spriteGame);
}