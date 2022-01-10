#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"


class Collectable : public Sprite
{
public:
   static Collectable* getInstance(int x, int y, int w, int h, const string& imgPath);
   void draw() const;
protected:
   Collectable(int x, int y, int w, int h, const string& imgPath);

};

#endif