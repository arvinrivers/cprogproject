/*
   Subklass till Sprite som tillhandahåller objekt i världen som avslutar nivån om de plockas upp.
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include "Goal.h"

//Konstruktor
Goal:: Goal(int x, int y, int w, int h,const std::string& imgPath):Sprite(x,y,w,h,imgPath){
  
}

//Returnerar ett objekt av klassen
Goal* Goal::getInstance(int x, int y, int w, int h, const std::string& imgPath) {
		return new Goal(x, y, w, h, imgPath);
}
