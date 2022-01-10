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

Enemy* Enemy::getInstance(int x, int y, int w, int h, const string& imgPath) {
		return new Enemy(x, y, w, h, imgPath);
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
		if(speed < 0){
			return x1;
		}return x2;
	}return 0;
}


void Enemy::scriptedMovement(){
    if(isGrounded()){
    	int edge = nextEdge();
		if (rect.x + speed < edge && speed < 0){
			rect.x = edge;
		}else if(rect.x + rect.w + speed > edge && speed > 0){
			rect.x = edge - rect.w;
		}else{
			rect.x += speed;
		}
		if(rect.x == edge || rect.x + rect.w == edge){
			speed = -speed;
		}
    }
}