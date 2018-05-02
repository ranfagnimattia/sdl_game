#include "Game.h"

Game *game=nullptr;

int main(int argc,const char* args[]) {
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    float frameTime = 0;
    game= new Game();
    game->init("Hello!",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,640,false);
    while (game->running()) {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update(frameTime /60);
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