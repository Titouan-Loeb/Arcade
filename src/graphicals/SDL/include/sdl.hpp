/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** sdl
*/

#ifndef SDL_HPP_
#define SDL_HPP_

#include "ILib.hpp"
#include "elemSDL.hpp"

extern "C" ILib *createLibrary();
namespace SDL
{
    typedef struct TextSDL_t
    {
        SDL_Rect rect;
        TTF_Font *font;
        SDL_Color color;
        SDL_Surface *surface;
        SDL_Texture *texture;
        std::string fontPath = "";
    } TextSDL;

    class LibSDL : public ILib {
        public:
            LibSDL();
            ~LibSDL();
            void displayObject(Object &object);
            void init();
            void displayBackground();
            void displayWindow();
            void destroyWindow();
            void putText(Text &text);
            void getInput(Key &input);
            void createObjects(int &gameID);
            void getInput(Key *input);
            std::string getLibName();
            void clearWindow();
            void destroyObjects();
            // void createObjects();
            // void destroyObjects();
            // void setPositions(/*iterateur de la lib*/);
            // void animePlayer();
        protected:
        private:
            elemSDL *_background;
            elemSDL *_spriteGame;
            SDL_Renderer *_renderer;
            TextSDL *_text;
            SDL_Window *_window;
            SDL_Event _event;
    };
}

#endif /* !SDL_HPP_ */