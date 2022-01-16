/*
   Subklass till Sprite som tillhandahåller plattformar som spelaren kan stå på
*/

#ifndef GROUND_H
#define GROUND_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include <string>


class Ground : public Sprite
{
public:
   ~Ground(){SDL_DestroyTexture(getTexture());}
   static Ground* getInstance(int x, int y, int w, int h, const std::string& imgPath);
protected:
   Ground(int x, int y, int w, int h, const std::string& imgPath);
};

#endif