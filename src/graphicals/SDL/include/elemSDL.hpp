/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** elemSDL
*/

#ifndef ELEMSDL_HPP_
#define ELEMSDL_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "ObjectInfo.hpp"

static const SDL_KeyCode SDLKeyCodes[] = {
    SDL_KeyCode::SDLK_LALT,
    SDL_KeyCode::SDLK_UP,
    SDL_KeyCode::SDLK_DOWN,
    SDL_KeyCode::SDLK_LEFT,
    SDL_KeyCode::SDLK_RIGHT,
    SDL_KeyCode::SDLK_ESCAPE,
    SDL_KeyCode::SDLK_SPACE,
    SDL_KeyCode::SDLK_F1,
    SDL_KeyCode::SDLK_F2,
    SDL_KeyCode::SDLK_F3,
    SDL_KeyCode::SDLK_F4,
    SDL_KeyCode::SDLK_F5,
    SDL_KeyCode::SDLK_F6,
    SDL_KeyCode::SDLK_F7,
    SDL_KeyCode::SDLK_F8,
    SDL_KeyCode::SDLK_F9,
    SDL_KeyCode::SDLK_F10,
    SDL_KeyCode::SDLK_F11,
    SDL_KeyCode::SDLK_F12,
    SDL_KeyCode::SDLK_a,
    SDL_KeyCode::SDLK_b,
    SDL_KeyCode::SDLK_c,
    SDL_KeyCode::SDLK_d,
    SDL_KeyCode::SDLK_e,
    SDL_KeyCode::SDLK_f,
    SDL_KeyCode::SDLK_g,
    SDL_KeyCode::SDLK_h,
    SDL_KeyCode::SDLK_i,
    SDL_KeyCode::SDLK_j,
    SDL_KeyCode::SDLK_k,
    SDL_KeyCode::SDLK_l,
    SDL_KeyCode::SDLK_m,
    SDL_KeyCode::SDLK_n,
    SDL_KeyCode::SDLK_o,
    SDL_KeyCode::SDLK_p,
    SDL_KeyCode::SDLK_q,
    SDL_KeyCode::SDLK_r,
    SDL_KeyCode::SDLK_s,
    SDL_KeyCode::SDLK_t,
    SDL_KeyCode::SDLK_u,
    SDL_KeyCode::SDLK_v,
    SDL_KeyCode::SDLK_w,
    SDL_KeyCode::SDLK_x,
    SDL_KeyCode::SDLK_y,
    SDL_KeyCode::SDLK_z,
    SDL_KeyCode::SDLK_BACKSPACE,
    SDL_KeyCode::SDLK_RETURN
};

static const int nbKeys = 46;

namespace SDL {

    class elemSDL {
        public:
            elemSDL(std::string texturePath, SDL_Renderer *renderer, SDL_Rect rect);
            ~elemSDL();
            void setElemSDL(Vect2f &pos, Rectangle &rect, SDL_Renderer *renderer);
            SDL_Texture *getTexture();
        protected:
        private:
            SDL_Texture *_texture;
            SDL_Rect _rect;
            SDL_Surface *_surface;
    };
}

#endif /* !ELEMSDL_HPP_ */
