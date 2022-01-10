#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include "Ground.h"


Ground:: Ground(int x, int y, int w, int h,const string& imgPath):Sprite(x,y,w,h,imgPath){
  
}

Ground* Ground::getInstance(int x, int y, int w, int h, const string& imgPath) {
		return new Ground(x, y, w, h, imgPath);
}


void Ground::draw() const{
        const SDL_Rect &rect = getRect();
		SDL_RenderCopy(sys.get_renderer(), getTexture(), NULL, &rect);
}
