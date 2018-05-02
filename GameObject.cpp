//
// Created by matti on 02/05/18.
//

#include "GameObject.h"
#include "TextureManager.h"
GameObject::GameObject(const char *texturesheet, SDL_Renderer *ren, int x,int y,float spd): renderer(ren),objTexture(TextureManager::LoadTexture(texturesheet,ren)),xpos(x),ypos(y), speed(spd){
}

void GameObject::Update() {
    xpos+=speed;
    //ypos+=speed;
    if(xpos>=500)
        xpos=0;
    if(ypos>=500)
        ypos=0;

    srcRect.h=32;
    srcRect.w=32;
    srcRect.x=0;
    srcRect.y=0;

    destRect.x=xpos;
    destRect.y=ypos;
    destRect.w=srcRect.w*2;
    destRect.h=srcRect.h*2;
}

void GameObject::Render() {
    SDL_RenderCopy(renderer,objTexture,&srcRect,&destRect);
}

int GameObject::getXpos() const {
    return xpos;
}

int GameObject::getYpos() const {
    return ypos;
}

void GameObject::setObjTexture(SDL_Texture *objTexture) {
    GameObject::objTexture = objTexture;
}

void GameObject::setSpeed(float speed) {
    GameObject::speed = speed;
}