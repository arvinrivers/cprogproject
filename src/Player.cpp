#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include "Player.h"
#include "GameEngine.h"
#include <iostream>


Player::Player(int x, int y, int w, int h,const string& imgPath):Sprite(x,y,w,h,imgPath){
	affectedByGravity = true;
}

void Player::draw() const{
	//	Uint32 white = SDL_MapRGB(surface->format, 255, 255, 255);
	//	SDL_SetColorKey(surface, true, white);
        const SDL_Rect &rect = getRect();
		SDL_RenderCopy(sys.get_renderer(), getTexture(), NULL, &rect);
}

void Player::keyDown(const SDL_Event& event) {
	
    keyDownHandler(event);
}

void Player::tick(GameEngine* ge)
{
	updateGrounded(ge->grounds);
	if (!isGrounded()){
		rect.y += getySpeed();
	}
}



