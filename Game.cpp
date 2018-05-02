//
// Created by matti on 22/04/18.
//

#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;
GameObject* enemy;
bool touch;
float accumulator = 0;
Game::Game() {
}
Game::~Game() {
}

void Game::init(const char* title,int xpos,int ypos,int width,int height,bool fullscreen) {
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized!!"<<std::endl;
        int flags= fullscreen?SDL_WINDOW_FULLSCREEN:0;
        window=SDL_CreateWindow(title,xpos,ypos,width,height,flags);
        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            std::cout << "Renderer created!" << std::endl;
        }
        isRunning = true;
    }
    else {
        isRunning = false;

    }
    player = new GameObject("../images/sprite1.png",renderer,150,150);
    enemy = new GameObject("../images/sprite2.png",renderer,100,150,2);
    touch=false;
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            isRunning=false;
            break;

        default:
            break;

    }
}

void Game::update(float dt) {
    player->Update();
    enemy->Update();
    if(abs(player->getXpos()-enemy->getXpos()) <= 50 && abs(player->getYpos()-enemy->getYpos()) <= 50) {

        accumulator += dt;
        if(accumulator > 0.2){
            player->setObjTexture(TextureManager::LoadTexture("../images/sprite3.png",renderer));
            enemy->setObjTexture(TextureManager::LoadTexture("../images/sprite4.png",renderer));
        }
        if(accumulator > 0.4){
            accumulator -= 0.4;
            player->setObjTexture(TextureManager::LoadTexture("../images/sprite1.png",renderer));
            enemy->setObjTexture(TextureManager::LoadTexture("../images/sprite2.png",renderer));

        }
        enemy->setSpeed(1);
        player->setSpeed(0);
    }
    else {
        touch=false;
        player->setObjTexture(TextureManager::LoadTexture("../images/sprite1.png",renderer));
        enemy->setObjTexture(TextureManager::LoadTexture("../images/sprite2.png",renderer));
        player->setSpeed(1);
        enemy->setSpeed(2);
    }
    count++;
    std::cout << count << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    //where we put stuff to render
    player->Render();
    enemy->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned." << std::endl;
}

bool Game::running() {return isRunning;}