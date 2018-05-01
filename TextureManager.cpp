//
// Created by matti on 01/05/18.
//
#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char *fileName, SDL_Renderer *ren) {
    SDL_Surface* tmpSurface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(ren,tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return texture;
}
