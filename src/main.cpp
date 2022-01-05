#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

class MyPlayer : public Player {
public:
	MyPlayer() : Player(0, 460, 40, 40, "C:/Users/arsol/OneDrive/Skrivbord/cprogproject-5/resources/images/821759741633626212.png")
	{
		
	}
	void keyDownHandler(const SDL_Event& event) 
	{
		switch (event.key.keysym.sym) 
		{
		case SDLK_RIGHT:
			rect.x += 1; 
			break;
	    case SDLK_LEFT: 
			rect.x -= 1; 
			break;
		}
    }

};

class MyEnemy : public Enemy {
public:
	MyEnemy() : Enemy(400, 660, 40, 40, "C:/Users/arsol/OneDrive/Skrivbord/cprogproject-5/resources/images/evilsprite.jpg")
	{

    }
    bool isMovingLeft = true;
    void scriptedMovement(){
    if (isMovingLeft){
        rect.x -= 2; 
    }
    else{
        rect.x += 2; 
    }
    if(rect.x == 0)
       isMovingLeft = false;
    else if(rect.x == 660)
       isMovingLeft = true;
 }
};

int main(int argc, char* argv[]) {
    GameEngine gameEngine;
    Player* player = new MyPlayer();
    Enemy* enemy = new MyEnemy();
    gameEngine.add(player);
    gameEngine.add(enemy);
    gameEngine.run();
    return 0;
}