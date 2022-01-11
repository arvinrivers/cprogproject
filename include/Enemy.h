/*
Subklass till Sprite som tillhandahåller fiender i världen.
Kommer med funktionalitet för skriptad rörelse av fienderna.
*/

#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include "Ground.h"
#include <iostream>

class System;
class Enemy : public Sprite
{
public:
   ~Enemy(){SDL_DestroyTexture(getTexture());}
   static Enemy* getInstance(int x, int y, int w, int h, const string& imgPath);
   void scriptedMovement();
   virtual void tick(GameEngine* ge);
   int nextEdge();
   void moveEnemy(int speed);
   void setSpeed(int s){speed = s;}
   int getSpeed(){return speed;}
protected:
   Enemy(int x, int y, int w, int h, const string& imgPath);

private:
   //Indikerar hastigheten som fienden rör sig varje tick
   int speed;
   //Hjälp-fält för den skriptade rörelse-logiken
   bool isMovingLeft;
};

#endif