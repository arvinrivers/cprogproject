/*
   Subklass till Sprite som tillhandahåller objekt i världen som inte är spelaren, fiender eller plattformar, 
   exempelvis mynt som spelaren kan plocka upp.
*/

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
protected:
   Collectable(int x, int y, int w, int h, const string& imgPath);

};

#endif