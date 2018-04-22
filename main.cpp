#include "Game.h"

Game *game=nullptr;

int main(int argc,const char* args[]) {
    game= new Game();
    game->init("Hello!",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,500,500,false);
    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();

    }
    game->clean();
    return 0;
}