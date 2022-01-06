#include "Sprite.h"
#include "System.h"

Sprite::Sprite(int x, int y, int w, int h, const string& imgPath): rect{x,y,w,h}{
    SDL_Surface* surface = IMG_Load((imgPath).c_str());
    texture = SDL_CreateTextureFromSurface(sys.get_renderer(), surface);
    SDL_FreeSurface(surface);
}