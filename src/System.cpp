#include <SDL2/SDL.h>
#include "../include/System.h"

System::System() {
    SDL_Init(SDL_INIT_EVERYTHING);
    win = SDL_CreateWindow("VideoGame", 10, 10, 700, 500, 0);
    ren = SDL_CreateRenderer(win, -1, 0);
    Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
    // Path to your own 'sounds' folder!
    //musik = Mix_LoadWAV("/Users/kjellna/dev/cpp21/f13b/sounds/bgMusic.wav");
  //  music = Mix_LoadWAV( ("sounds/bgMusic.wav").c_str() );
  //  Mix_PlayChannel(-1, music, -1);
}

System::System(string gameName) {
  SDL_Init(SDL_INIT_EVERYTHING);
    win = SDL_CreateWindow(gameName, 10, 10, 700, 500, 0);
    ren = SDL_CreateRenderer(win, -1, 0);
    Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
    // Path to your own 'sounds' folder!
    //musik = Mix_LoadWAV("/Users/kjellna/dev/cpp21/f13b/sounds/bgMusic.wav");
  //  music = Mix_LoadWAV( ("sounds/bgMusic.wav").c_str() );
  //  Mix_PlayChannel(-1, music, -1);
}

System::~System() {
 //   Mix_FreeChunk(music);
  //  Mix_CloseAudio();
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    SDL_Quit();
}

SDL_Renderer* System::get_renderer() const 
	{
		return ren;
	}

System sys;