#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include "Collectable.h"


Collectable:: Collectable(int x, int y, int w, int h,const string& imgPath):Sprite(x,y,w,h,imgPath){
  
}

Collectable* Collectable::getInstance(int x, int y, int w, int h, const string& imgPath) {
		return new Collectable(x, y, w, h, imgPath);
}
