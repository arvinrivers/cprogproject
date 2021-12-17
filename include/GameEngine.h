

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class GameEngine {
public:
    GameEngine();
    ~GameEngine();
private:
    SDL_Window* win;
    SDL_Renderer* ren;
    Mix_Chunk* music;
};

extern std::string resPath;
extern GameEngine sys;

#endif GAMEENGINE_H
