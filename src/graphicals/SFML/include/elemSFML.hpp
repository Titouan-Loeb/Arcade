/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** elemSFML
*/

#ifndef ELEMSFML_HPP_
#define ELEMSFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Config.hpp>
#include "Object.hpp"

static const sf::Keyboard::Key sfKeyCodes[] = {
    sf::Keyboard::Key::Unknown,
    sf::Keyboard::Key::Up,
    sf::Keyboard::Key::Down,
    sf::Keyboard::Key::Left,
    sf::Keyboard::Key::Right,
    sf::Keyboard::Key::Escape,
    sf::Keyboard::Key::Space,
    sf::Keyboard::Key::F1,
    sf::Keyboard::Key::F2,
    sf::Keyboard::Key::F3,
    sf::Keyboard::Key::F4,
    sf::Keyboard::Key::F5,
    sf::Keyboard::Key::F6,
    sf::Keyboard::Key::F7,
    sf::Keyboard::Key::F8,
    sf::Keyboard::Key::F9,
    sf::Keyboard::Key::F10,
    sf::Keyboard::Key::F11,
    sf::Keyboard::Key::F12,
    sf::Keyboard::Key::A,
    sf::Keyboard::Key::B,
    sf::Keyboard::Key::C,
    sf::Keyboard::Key::D,
    sf::Keyboard::Key::E,
    sf::Keyboard::Key::F,
    sf::Keyboard::Key::G,
    sf::Keyboard::Key::H,
    sf::Keyboard::Key::I,
    sf::Keyboard::Key::J,
    sf::Keyboard::Key::K,
    sf::Keyboard::Key::L,
    sf::Keyboard::Key::M,
    sf::Keyboard::Key::N,
    sf::Keyboard::Key::O,
    sf::Keyboard::Key::P,
    sf::Keyboard::Key::Q,
    sf::Keyboard::Key::R,
    sf::Keyboard::Key::S,
    sf::Keyboard::Key::T,
    sf::Keyboard::Key::U,
    sf::Keyboard::Key::V,
    sf::Keyboard::Key::W,
    sf::Keyboard::Key::X,
    sf::Keyboard::Key::Y,
    sf::Keyboard::Key::Z,
    sf::Keyboard::Key::BackSpace,
    sf::Keyboard::Key::Return
};

static const int nbKeys = 46;

namespace SFML {

    class elemSFML {
        public:
            elemSFML(std::string texturePath, sf::IntRect rect, sf::Vector2f pos);
            elemSFML();
            ~elemSFML();
            void setPos(Vect2f &pos);
            void setRect(Rectangle &rect);
            void setElemSFML(Vect2f &pos, Rectangle &rect);
            void setElemSFML();
            sf::Sprite getSprite() const;
        protected:
        private:
            sf::Sprite _sprite;
            sf::Texture _texture;
            sf::IntRect _rect;
            sf::Vector2f _pos;
    };
}

#endif /* !ELEMSFML_HPP_ */
