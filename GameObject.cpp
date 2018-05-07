//
// Created by matti on 02/05/18.
//

#include "GameObject.h"
#include "TextureManager.h"
GameObject::GameObject(char* pathSprite1,char * pathSprite2,int x,int y,int spd): pathSprite1(pathSprite1),pathSprite2(pathSprite2),xpos(x),ypos(y), speed(spd){
   objTexture= TextureManager::LoadTexture(pathSprite1);
}

void GameObject::Update() {
    srcRect.h=32;
    srcRect.w=32;
    srcRect.x=0;
    srcRect.y=0;

    destRect.x=xpos;
    destRect.y=ypos;
    destRect.w=srcRect.w*2;
    destRect.h=srcRect.h*2;

    xpos+=speed;
    if(xpos>=500)
        xpos=0;
    if(xpos<0)
        xpos=500;
}

void GameObject::Render() {
    TextureManager::Draw(objTexture,srcRect,destRect);
}

int GameObject::getXpos() const {
    return xpos;
}

int GameObject::getYpos() const {
    return ypos;
}

void GameObject::setObjTexture(char* path) {
    objTexture=TextureManager::LoadTexture(path);
}

void GameObject::setSpeed(int speed) {
    GameObject::speed = speed;
}

/*void GameObject::collisionMovement(GameObject *obj,int maxdistance, int range, int shakes, bool collided) {
    int speed_tmp = speed;
    if(checkCollision(obj,maxdistance) && !collided) {
        collided = true;
        setObjTexture(pathSprite2);
        obj->setObjTexture(obj->getPathSprite2());
        for (int i = 0; i < shakes * 2; i++) {
            speed = -speed;
            for (int j = 0; j < range; j++){
                Update();
                Render();
            }
        }
        speed = speed_tmp;
        obj->setObjTexture(obj->getPathSprite1());
        setObjTexture(pathSprite1);
    }
    else if(!checkCollision(obj,maxdistance))
        collided = false;
    Update();
    obj->Update();
    Render();
    obj->Render();
}*/

bool GameObject::checkCollision(const GameObject *obj, int maxdistance) {
    bool result=false;
    if(maxdistance >= abs(xpos - obj->getXpos()))
        result = true;
    return result;
}

char *GameObject::getPathSprite1() const {
    return pathSprite1;
}

char *GameObject::getPathSprite2() const {
    return pathSprite2;
}

int GameObject::getSpeed() const {
    return speed;
}
