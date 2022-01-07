#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include "Enemy.h"
#include "GameEngine.h"
#include <iostream>


Enemy::Enemy(int x, int y, int w, int h,const string& imgPath):Sprite(x,y,w,h,imgPath){
	setySpeed(0);
	affectedByGravity = true;
}

void Enemy::draw() const{
	//	Uint32 white = SDL_MapRGB(surface->format, 255, 255, 255);
	//	SDL_SetColorKey(surface, true, white);
        const SDL_Rect &rect = getRect();
		SDL_RenderCopy(sys.get_renderer(), getTexture(), NULL, &rect);
}

void Enemy::tick(GameEngine* ge)
{
	updateGrounded(ge->grounds);
	if (!isGrounded()){
		rect.y += 1;
	}
	scriptedMovement();
}

int Enemy::nextEdge(){
	if (getWalkingGround() != nullptr){
		SDL_Rect groundRect = getWalkingGround()->getRect();
		int x1 = groundRect.x;
		int x2 = groundRect.x + groundRect.w;
		if(speed > 0){
			return x1;
		}return x2;
	}return 0;
}