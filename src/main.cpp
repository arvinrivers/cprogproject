#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Collectable.h"
#include <iostream>
#include <string>

std::string resPath = "resources/";

class MyPlayer : public Player {
public:
	MyPlayer() : Player(0, 460, 40, 40, resPath + "images/player.jpg")
	{
		
	}
	void keyDownHandler(const SDL_Event& event) 
	{
		switch (event.key.keysym.sym) 
		{
		case SDLK_RIGHT:
			rect.x += 30; 
			break;
	    case SDLK_LEFT: 
			rect.x -= 1; 
			break;
        case SDLK_UP: 
            setGrounded(false);
            break;
		}
    }
    void jump(){
        static int foo = 0;
        if(!isGrounded() && foo < 30){
        rect.y -= 10;
        foo++;
        }
    }

};

class MyEnemy : public Enemy {
public:
	MyEnemy() : Enemy(660, 460, 40, 40, resPath + "images/enemy.jpg")
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

class MyCoin : public Collectable {
public:
	MyCoin() : Collectable(660, 0, 40, 40, resPath + "images/coin.png")
	{
    }
};

int main(int argc, char* argv[]) {
    GameEngine gameEngine;
    Player* player = new MyPlayer();
    Enemy* enemy = new MyEnemy();
    Collectable* coin = new MyCoin();
    gameEngine.add(player);
    gameEngine.add(enemy);
    gameEngine.add(coin);
    gameEngine.run();
    return 0;
}