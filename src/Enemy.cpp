/*
Subklass till Sprite som tillhandahåller fiender i världen.
Kommer med funktionalitet för skriptad rörelse av fienderna.
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include "Enemy.h"
#include "GameEngine.h"

//Konstruktor
Enemy::Enemy(int x, int y, int w, int h,const std::string& imgPath):Sprite(x,y,w,h,imgPath){
	setySpeed(0);
	setAffectedByGravity(true);
}

//Returnerar en instans av klassen
Enemy* Enemy::getInstance(int x, int y, int w, int h, const std::string& imgPath) {
		return new Enemy(x, y, w, h, imgPath);
}

//Logiken som sker varje tick i spelmotorn, i detta fall rörelserelaterat
void Enemy::tick(GameEngine* ge)
{
	updateGrounded(ge->grounds);
	SDL_Rect thisRect = getRect();
	if (!isGrounded()){
		setRectY(thisRect.y + 1);
	}
	scriptedMovement();
}

//Hjälpfunktion för rörelselogiken så att fiender inte trillar av plattformar
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

//Sköter rörelsen av fienden givet plattformen den står på
void Enemy::scriptedMovement(){
    if(isGrounded()){
    	int edge = nextEdge();
		SDL_Rect thisRect = getRect();
		if (thisRect.x + speed < edge && speed < 0){
			setRectX(edge);
		}else if(thisRect.x + thisRect.w + speed > edge && speed > 0){
			setRectX(edge - thisRect.w);
		}else{
			setRectX(thisRect.x + speed);
		}
		if(thisRect.x == edge || thisRect.x + thisRect.w == edge){
			speed = -speed;
		}
    }
}