//
// Created by matti on 22/04/18.
//

#include "Game.h"

SDL_Texture* playerTex;

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
    SDL_Surface* tmpSurface = IMG_Load("../images/sprite1.png");
    playerTex = SDL_CreateTextureFromSurface(renderer,tmpSurface);
    SDL_FreeSurface(tmpSurface);

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
    std::cout << count << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    //where we put stuff to render
    SDL_RenderCopy(renderer,playerTex,NULL,NULL); //primo null usa tutta l'immagine per la texture, il secondo null inserisce l'immagine sull'intera finestra
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned." << std::endl;
}

bool Game::running() {return isRunning;}