//
// Created by matti on 02/05/18.
//

#ifndef PROVASDL_GAMEOBJECT_H
#define PROVASDL_GAMEOBJECT_H

#include "Game.h"

class GameObject {

public:
    GameObject(const char* texturesheet, SDL_Renderer* ren,int x=0, int y=0,float speed=1);
    ~GameObject();

    void Update();
    void Render();

    int getXpos() const;

    int getYpos() const;

    void setObjTexture(SDL_Texture *objTexture);

    void setSpeed(float speed);

private:
    int xpos;
    int ypos;
    float speed;
    SDL_Texture* objTexture;
    SDL_Rect srcRect,destRect;
    SDL_Renderer* renderer;

};




#endif //PROVASDL_GAMEOBJECT_H
