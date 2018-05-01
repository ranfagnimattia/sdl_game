//
// Created by matti on 02/05/18.
//

#ifndef PROVASDL_GAMEOBJECT_H
#define PROVASDL_GAMEOBJECT_H

#include "Game.h"

class GameObject {

public:
    explicit GameObject(const char* texturesheet, SDL_Renderer* ren,int x=0, int y=0);
    ~GameObject();

    void Update();
    void Render();

private:
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect,destRect;
    SDL_Renderer* renderer;

};


#endif //PROVASDL_GAMEOBJECT_H
