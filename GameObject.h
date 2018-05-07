//
// Created by matti on 02/05/18.
//

#ifndef PROVASDL_GAMEOBJECT_H
#define PROVASDL_GAMEOBJECT_H

#include "Game.h"

class GameObject {

public:
    GameObject(char * pathSprite1,char * pathSprite2,int x=0, int y=0,int speed=1);

    ~GameObject();

    void Update();

    void Render();

    int getXpos() const;

    int getYpos() const;

    void setObjTexture(char * path);

    void setSpeed(int speed);

    bool checkCollision(const GameObject* obj, int maxdistance=30);

    int getSpeed() const;

    //void collisionMovement(GameObject* obj, int maxdistance=30, int range=15, int shakes=2,bool collided=false);

    char *getPathSprite1() const;

    char *getPathSprite2() const;

private:
    int xpos;
    int ypos;
    int speed;
    char* pathSprite1;
    char* pathSprite2;
    SDL_Texture* objTexture;
    SDL_Rect srcRect,destRect;

};




#endif //PROVASDL_GAMEOBJECT_H
