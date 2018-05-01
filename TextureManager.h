//
// Created by matti on 01/05/18.
//
#ifndef PROVASDL_TEXTUREMANAGER_H
#define PROVASDL_TEXTUREMANAGER_H

#include "Game.h"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);

};
#endif //PROVASDL_TEXTUREMANAGER_H
