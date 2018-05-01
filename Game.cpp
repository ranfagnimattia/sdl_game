//
// Created by matti on 22/04/18.
//

#include "Game.h"
#include "TextureManager.h"

SDL_Texture* playerTex;
SDL_Rect srcR,destR1,destR2;
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
    playerTex = TextureManager::LoadTexture("../images/sprite1.png",renderer);
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
    count++;
    destR1.y = 250;
    destR2.y = 250;
    destR1.h = 64;
    destR2.h = 64;
    destR1.w = 64;
    destR2.w = 64;
    if(destR1.x >= 500)
        destR1.x = 0;
    if(destR2.x >= 500)
        destR2.x = 0;
    if(abs(destR1.x-destR2.x)> 20)
        destR2.x+=1;
    destR1.x+=2;
    std::cout << count << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    //where we put stuff to render
    SDL_RenderCopy(renderer,playerTex,NULL,&destR1); //primo null usa tutta l'immagine per la texture, il secondo null inserisce l'immagine sull'intera finestra
    SDL_RenderCopy(renderer,playerTex,NULL,&destR2); //primo null usa tutta l'immagine per la texture, il secondo null inserisce l'immagine sull'intera finestra
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned." << std::endl;
}

bool Game::running() {return isRunning;}