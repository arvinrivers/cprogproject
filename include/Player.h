/*
Subklass till Sprite som tillhandahåller själva spelarkaraktären.
Kommer med funktionalitet för spelarstyrd rörelse samt win/lose-conditions.
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include <string>
#include <iostream>
using namespace std;

class Player : public Sprite
{
public:
   ~Player(){SDL_DestroyTexture(getTexture());}
   static Player* getInstance(int x, int y, int w, int h, const string& imgPath);
   void keyDown(const SDL_Event& event);
   virtual void jump(){};
   virtual void keyDownHandler(const SDL_Event& event){}
   virtual void tick(GameEngine* ge);
   virtual void winConditionHandler(){};
   virtual void loseConditionHandler(){};
   void setWinConditionMet(bool value){winConditionMet = value;}
   void setLoseConditionMet(bool value){loseConditionMet = value;}
   bool getWinConditionMet(){return winConditionMet;}
   bool getLoseConditionMet(){return loseConditionMet;}
protected:
   Player(int x, int y, int w, int h, const string& imgPath);
private:
   bool winConditionMet = false;
   bool loseConditionMet = false;

};

#endif