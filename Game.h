//
// Created by matti on 22/04/18.
//

#ifndef PROVASDL_GAME_H
#define PROVASDL_GAME_H
#include<SDL2/SDL.h>
#include<iostream>

class Game {
public:
    Game();
    ~Game();

    void init(const char* title,int xpos,int ypos,int width,int height,bool fullscreen);
    void update();
    void render();
    void clean(); //avoid memory leak and optimize

    bool running();
    void handleEvents();
private:
    int count = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif //PROVASDL_GAME_H
