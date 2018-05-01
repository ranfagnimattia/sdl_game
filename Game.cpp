//
// Created by matti on 22/04/18.
//

#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;
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
    player = new GameObject("../images/sprite1.png",renderer);
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

void Game::update() {
    player->Update();

    count++;
    std::cout << count << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    //where we put stuff to render
    player->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned." << std::endl;
}

bool Game::running() {return isRunning;}