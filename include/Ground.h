#ifndef GROUND_H
#define GROUND_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"


class Ground : public Sprite
{
public:
   static Ground* getInstance(int x, int y, int w, int h, const string& imgPath);
protected:
   Ground(int x, int y, int w, int h, const string& imgPath);

};

#endif