/*
   Subklass till Sprite som tillhandahåller objekt i världen som avslutar nivån om de plockas upp
*/

#ifndef GOAL_H
#define GOAL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include <string>


class Goal : public Sprite
{
public:
   ~Goal(){SDL_DestroyTexture(getTexture());}
   static Goal* getInstance(int x, int y, int w, int h, const std::string& imgPath);
protected:
   Goal(int x, int y, int w, int h, const std::string& imgPath);

};

#endif