#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include "Player.h"


Player::Player(int x, int y, int w, int h,const string& imgPath):Sprite(x,y,w,h,imgPath){
  
}

void Player::draw() const{
	//	Uint32 white = SDL_MapRGB(surface->format, 255, 255, 255);
	//	SDL_SetColorKey(surface, true, white);
        const SDL_Rect &rect = getRect();
		SDL_RenderCopy(sys.get_renderer(), getTexture(), NULL, &rect);
		SDL_DestroyTexture(getTexture());
}



