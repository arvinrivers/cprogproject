/*
   Subklass till Sprite som tillhandahåller objekt i världen som inte är spelaren, fiender eller plattformar, 
   exempelvis mynt som spelaren kan plocka upp.
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include "Collectable.h"

//Konstruktor
Collectable:: Collectable(int x, int y, int w, int h,const string& imgPath):Sprite(x,y,w,h,imgPath){
  
}

//Returnerar ett objekt av klassen
Collectable* Collectable::getInstance(int x, int y, int w, int h, const string& imgPath) {
		return new Collectable(x, y, w, h, imgPath);
}
