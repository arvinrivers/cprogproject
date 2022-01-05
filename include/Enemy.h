#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"


class Enemy : public Sprite
{
public:
   Enemy(int x, int y, int w, int h, const string& imgPath);
   void draw() const;
   virtual void scriptedMovement(){};
   virtual void tick(GameEngine* ge);
};

#endif