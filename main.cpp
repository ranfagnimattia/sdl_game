#include "Game.h"

Game *game=nullptr;

int main(int argc,const char* args[]) {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;
    game= new Game();
    game->init("Hello!",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,500,500,false);
    while (game->running()) {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();
        //per vedere tempo trascorso a fare render e tutto
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }

    }
    game->clean();
    return 0;
}