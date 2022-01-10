/*
Utility-klass som står för själva fönstret och dess renderer
*/

#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

class System {
public:
    System();
    ~System();
    SDL_Renderer* get_renderer() const;
private:
    SDL_Window* win;
    SDL_Renderer* ren;
};
extern System sys;

#endif
