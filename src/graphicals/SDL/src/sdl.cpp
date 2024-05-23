/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** sdl
*/

#include <iostream>

#include "sdl.hpp"

extern "C" ILib *createLibrary()
{
    return (dynamic_cast<ILib *>(new SDL::LibSDL));
}

std::string SDL::LibSDL::getLibName()
{
    return ("sdl2");
}

void SDL::LibSDL::init()
{
    SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    _background = new elemSDL(texturesPaths[0][0], _renderer, SDL_Rect{0, 0, 0, 0});
    _text = new TextSDL;
    _text->fontPath = "";
}

SDL::LibSDL::LibSDL()
{
}

SDL::LibSDL::~LibSDL()
{
    SDL_DestroyWindow(_window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}

void SDL::LibSDL::displayBackground()
{
    SDL_RenderCopy(_renderer, _background->getTexture(), NULL, NULL);
}

void SDL::LibSDL::displayObject(Object &Object)
{
    _spriteGame->setElemSDL(Object.fPos, Object.rect, _renderer);
}

void SDL::LibSDL::displayWindow()
{
    SDL_RenderPresent(_renderer);
    SDL_UpdateWindowSurface(_window);
}

void SDL::LibSDL::clearWindow()
{
}

void SDL::LibSDL::destroyWindow()
{
    SDL_DestroyWindow(_window);
}

void SDL::LibSDL::putText(Text &text)
{
    int height = 10;
    int width = 10;

    if (_text->fontPath != text.fontPath) {
        _text->fontPath = text.fontPath;
        _text->font = TTF_OpenFont(text.fontPath.c_str(), text.size);
    }
    _text->color = {255, 255, 255, 255};
    _text->surface = TTF_RenderText_Solid(_text->font, text.text.c_str(), _text->color);
    _text->texture = SDL_CreateTextureFromSurface(_renderer, _text->surface);
    SDL_QueryTexture(_text->texture, NULL, NULL, &height, &width);
    _text->rect = {(int)text.floatPos.x, (int)text.floatPos.y, height, width};
    SDL_RenderCopy(_renderer, _text->texture, NULL, &_text->rect);
	SDL_DestroyTexture(_text->texture);
	SDL_FreeSurface(_text->surface);
}

void SDL::LibSDL::getInput(Key &input)
{
    input.code = KeyNone;
    input.state = StateNone;
    while (SDL_PollEvent(&_event) != 0) {
        if (_event.type == SDL_KEYUP)
            input.state = KeyReleased;
        else if (_event.type == SDL_KEYDOWN)
            input.state = KeyPressed;
        if (_event.type == SDL_QUIT)
            input.code = KeyEscape;
        if (_event.key.keysym.sym == SDLK_RETURN)
            input.code = KeyEnter;
        for (int i = 0; i < nbKeys; i++) {
            if (_event.key.keysym.sym == SDLKeyCodes[i] && input.state == KeyPressed && input.code == KeyNone)
                input.code = (KeyCode)i;
        }
    }
}

void SDL::LibSDL::createObjects(int &gameID)
{
    _spriteGame = new elemSDL(texturesPaths[gameID][0], _renderer,
    SDL_Rect{0, 0, 0, 0});
}

void SDL::LibSDL::destroyObjects()
{
    SDL_DestroyTexture(_spriteGame->getTexture());
    delete(_spriteGame);
}