/*
Subklass till Sprite som tillhandahåller plattformar som spelaren kan stå på
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include "Ground.h"

//Konstruktor
Ground:: Ground(int x, int y, int w, int h,const std::string& imgPath):Sprite(x,y,w,h,imgPath){
  
}

//Returnerar en instans av klassen
Ground* Ground::getInstance(int x, int y, int w, int h, const std::string& imgPath) {
		return new Ground(x, y, w, h, imgPath);
}
