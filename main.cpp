#include <iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

//Key press surfaces constants
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT, //automaticamente sono assegnati i valori rispettivi : 0,1,2,3,4,5
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};
const int SCREEN_WIDTH= 640;
const int SCREEN_HEIGHT= 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );

//Loads individual image
SDL_Surface* loadSurface( std::string path );

//The window renderer
SDL_Renderer* gRenderer = nullptr;

//Current displayed texture
SDL_Texture* gTexture = nullptr;

//The window we'll be rendering to
SDL_Window* gWindow = nullptr;

//The surface contained by the window
SDL_Surface* gScreenSurface = nullptr;

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

//Current displayed image
SDL_Surface* gCurrentSurface = nullptr;


bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE );
        if( gWindow == nullptr )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            int imgFlags = IMG_INIT_PNG;
            if(!(IMG_Init(imgFlags)) & imgFlags) {
                std::cout << "SDL_image could not initialize! SDL_image Error: "<< IMG_GetError();
                success = false;
            }
            else {
                //Get window surface
                gScreenSurface = SDL_GetWindowSurface( gWindow );
            }
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;
    //Load default surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "images/space.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == nullptr )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    //Load up surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface("images/up.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == nullptr )
    {
        printf( "Failed to load up image!\n" );
        success = false;
    }

    //Load down surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "images/down.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == nullptr )
    {
        printf( "Failed to load down image!\n" );
        success = false;
    }

    //Load left surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "images/left.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == nullptr )
    {
        printf( "Failed to load left image!\n" );
        success = false;
    }

    //Load right surface
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "images/right.bmp" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == nullptr )
    {
        printf( "Failed to load right image!\n" );
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface(gScreenSurface );
    gScreenSurface = nullptr;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    //Quit SDL subsystems
    SDL_Quit();
}

SDL_Surface *loadSurface(std::string const path ) {
    SDL_Surface* optimizedSurface = nullptr;
    SDL_Surface *loaded_surface = IMG_Load(path.c_str());
    if(loaded_surface == nullptr)
        std::cout << "Unable to load image" << path.c_str() << std::endl << "SDL Error:" << SDL_GetError();
    else {
        optimizedSurface = SDL_ConvertSurface(loaded_surface,gScreenSurface->format, 0);
        if(optimizedSurface == nullptr)
            std::cout << "Unable to optimize image "<< path.c_str() << "SDL Error: " << SDL_GetError();
        SDL_FreeSurface(loaded_surface);
    }
    return optimizedSurface;
}

int main(int argc, char* args[]) {
    gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
    if( !init() )
        {
            printf( "Failed to initialize!\n" );
        }
    else
    {
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            bool quit = false;
            SDL_Event e;
            while(!quit) {
                while(SDL_PollEvent(&e)!= 0) {
                    if((e).type == SDL_QUIT)
                        quit=true;
                        //User presses a key
                    else if( e.type == SDL_KEYDOWN )
                    {
                        //Select surfaces based on key press
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_UP:
                                gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                                break;

                            case SDLK_DOWN:
                                gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                                break;

                            case SDLK_LEFT:
                                gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                                break;

                            case SDLK_RIGHT:
                                gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                                break;

                            default:
                                gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                                break;
                        }
                    }
                    //Apply the current image
                    //SDL_BlitSurface( gCurrentSurface, nullptr, gScreenSurface, nullptr );
                    SDL_Rect stretchRect;
                    stretchRect.x = 0;
                    stretchRect.y = 0;
                    stretchRect.w = SCREEN_WIDTH;
                    stretchRect.h = SCREEN_HEIGHT;
                    SDL_BlitScaled(gCurrentSurface,nullptr,gScreenSurface,&stretchRect);
                    //Update the surface
                    SDL_UpdateWindowSurface( gWindow );
                }
            }

        }
    }
    close();
    return 0;
}