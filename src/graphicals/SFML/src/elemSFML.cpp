/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** elemSFML
*/

#include "elemSFML.hpp"

SFML::elemSFML::elemSFML(std::string texturePath,
    sf::IntRect rect, sf::Vector2f pos)
{
    _rect = rect;
    _pos = pos;
    _texture.loadFromFile(texturePath, _rect);
    _sprite.setTexture(_texture, true);
}

SFML::elemSFML::elemSFML()
{
    _rect = (sf::IntRect) {0, 0, 0, 0};
    _pos = (sf::Vector2f) {0, 0};
}

SFML::elemSFML::~elemSFML()
{
}

void SFML::elemSFML::setPos(Vect2f &pos)
{
    _pos = (sf::Vector2f) {pos.x, pos.y};
}

void SFML::elemSFML::setRect(Rectangle &rect)
{
    _rect = (sf::IntRect) {rect.left, rect.top, rect.width, rect.height};
}

void SFML::elemSFML::setElemSFML(Vect2f &pos, Rectangle &rect)
{
    setPos(pos);
    setRect(rect);
    setElemSFML();
}

void SFML::elemSFML::setElemSFML()
{
    _sprite.setTextureRect(_rect);
    _sprite.setPosition(_pos);
}

sf::Sprite SFML::elemSFML::getSprite() const
{
    return (_sprite);
}