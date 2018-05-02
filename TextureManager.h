//
// Created by matti on 01/05/18.
//
#ifndef PROVASDL_TEXTUREMANAGER_H
#define PROVASDL_TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

};
#endif //PROVASDL_TEXTUREMANAGER_H
