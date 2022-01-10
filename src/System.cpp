#include <SDL2/SDL.h>
#include "System.h"

System::System() {
    SDL_Init(SDL_INIT_EVERYTHING);
    win = SDL_CreateWindow("VideoGame", 50, 50, 700, 500, 0);
    ren = SDL_CreateRenderer(win, -1, 0);
}

System::~System() {
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    SDL_Quit();
}

SDL_Renderer* System::get_renderer() const 
	{
		return ren;
	}

System sys;