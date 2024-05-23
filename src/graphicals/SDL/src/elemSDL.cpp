/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** elemSDL
*/

#include "elemSDL.hpp"

SDL::elemSDL::elemSDL(std::string texturePath, SDL_Renderer *renderer, SDL_Rect rect)
{
    _rect = rect;
    _texture = IMG_LoadTexture(renderer, texturePath.c_str());
}

SDL::elemSDL::~elemSDL()
{
}

SDL_Texture *SDL::elemSDL::getTexture()
{
    return (_texture);
}

void SDL::elemSDL::setElemSDL(Vect2f &pos, Rectangle &rect, SDL_Renderer *renderer)
{
    SDL_Rect textureRect = {rect.left, rect.top, rect.width, rect.height};

    _rect = {(int)pos.x, (int)pos.y, rect.height, rect.width};
    SDL_RenderCopy(renderer, _texture, &textureRect, &_rect);
}