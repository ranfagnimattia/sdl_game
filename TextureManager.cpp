//
// Created by matti on 01/05/18.
//
#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char *fileName) {
    SDL_Surface* tmpSurface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return texture;
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(Game::renderer,tex,&src,&dest);
}
