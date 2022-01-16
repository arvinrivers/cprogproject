/*
Subklass till Sprite som tillhandahåller själva spelarkaraktären.
Kommer med funktionalitet för spelarstyrd rörelse samt win/lose-conditions.
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include "Player.h"
#include "GameEngine.h"

//Konstruktor
Player::Player(int x, int y, int w, int h,const std::string& imgPath):Sprite(x,y,w,h,imgPath){
	setAffectedByGravity(true);
}

//Returnerar en instans av klassen
Player* Player::getInstance(int x, int y, int w, int h, const std::string& imgPath) {
		return new Player(x, y, w, h, imgPath);
}

//Hjälpfunktion för spelarinput
void Player::keyDown(const SDL_Event& event) {
	keyDownHandler(event);
}

//Logiken som sker varje tick, framförallt rörelse och kollision
void Player::tick(GameEngine* ge)
{
	updateGrounded(ge->grounds);
	for (Sprite* s : ge->enemies){
		if (checkCollision(getRect(), s->getRect()) == true) loseConditionMet = true;
	}
	for (Sprite* s : ge->goals){
   		if (checkCollision(getRect(), s->getRect()) == true) winConditionMet = true;
	}
    winConditionHandler();
	loseConditionHandler();
	if (!isGrounded()){
		SDL_Rect thisRect = getRect();
		setRectY(thisRect.y + getySpeed());
	}
}


