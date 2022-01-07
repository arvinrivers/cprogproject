#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Collectable.h"
#include "Ground.h"
#include <iostream>
#include <string>

std::string resPath = "resources/";

class MyPlayer : public Player {
public:
	MyPlayer() : Player(320, 40, 40, 40, resPath + "images/player.jpg")
	{
		
	}
	void keyDownHandler(const SDL_Event& event) 
	{
		switch (event.key.keysym.sym) 
		{
		case SDLK_RIGHT:
			rect.x += 15; 
			break;
	    case SDLK_LEFT: 
			rect.x -= 15; 
			break;
        case SDLK_UP: 
            jump();
            break;
		}
    }
    void jump(){
        if(isGrounded()){
            setJumping(true);
        }
    }

};

class MyEnemy : public Enemy {
public:
	MyEnemy() : Enemy(30, 150, 40, 40, resPath + "images/enemy.jpg")
	{
        
    }
    bool isMovingLeft = true;
    void scriptedMovement(){
        int edge = nextEdge();
        if (isMovingLeft){
            rect.x -= 1;
        }
        else{
            rect.x += 1; 
        }
        if(rect.x == edge)
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
    enemy->setSpeed(-10);
    Collectable* coin = new MyCoin();
    Ground* ground = new Ground(300, 300, 300, 20, resPath + "images/ground.jpg");
    Ground* ground2 = new Ground(0, 300, 250, 20, resPath + "images/ground.jpg");
    gameEngine.add(player);
    gameEngine.add(enemy);
    gameEngine.add(coin);
    gameEngine.add(ground);
    gameEngine.add(ground2);
    gameEngine.run();
    return 0;
}