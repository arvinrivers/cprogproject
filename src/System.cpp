/*
Utility-klass som står för själva fönstret och dess renderer
*/

#include <SDL2/SDL.h>
#include "System.h"

//Konstruktor
System::System() {
    SDL_Init(SDL_INIT_EVERYTHING);
    win = SDL_CreateWindow("VideoGame", 50, 50, 700, 500, 0);
    ren = SDL_CreateRenderer(win, -1, 0);
}

//Destruktor
System::~System() {
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    SDL_Quit();
}

//Returnerar fönstrets renderare
SDL_Renderer* System::get_renderer() const 
	{
		return ren;
	}

System sys;