#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include <string>
using namespace std;

class Player : public Sprite
{
public:
   Player(int x, int y, int w, int h, const string& imgPath);
   void draw() const;
   void keyDown(const SDL_Event& event);
   virtual void jump(){};
   virtual void keyDownHandler(const SDL_Event& event){}
   virtual void tick(GameEngine* ge);

};

#endif