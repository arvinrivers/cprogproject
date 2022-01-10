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
Ground* won = Ground::getInstance(0 , 0, 700, 500, resPath + "images/won.jpg");
Ground* lost = Ground::getInstance(0 , 0, 700, 500, resPath + "images/lost.jpg");
GameEngine gameEngine;

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
    void winConditionHandler(){
        if (winConditionMet){
         gameEngine.remove(this);
         gameEngine.add(won);
        }
    }

    void loseConditionHandler(){
        if (loseConditionMet){
         gameEngine.remove(this);
         gameEngine.add(lost);
        }
    }


};

class MyEnemy : public Enemy {
public:
	MyEnemy() : Enemy(50, 250, 40, 40, resPath + "images/enemy.jpg")
	{
        
    }
    

};

class MyCoin : public Collectable {
public:
	MyCoin() : Collectable(660, 300, 40, 40, resPath + "images/coin.png")
	{
    }
};

int main(int argc, char* argv[]) {
    Player* player = new MyPlayer();
    Enemy* enemy = new MyEnemy();
    enemy->setSpeed(-10);
    Collectable* coin = new MyCoin();
    Ground* ground = Ground::getInstance(300, 300, 300, 20, resPath + "images/ground.jpg");
    Ground* ground2 = Ground::getInstance(15, 300, 250, 20, resPath + "images/ground.jpg");
    gameEngine.add(player);
    gameEngine.add(enemy);
    gameEngine.add(coin);
    gameEngine.add(ground);
    gameEngine.add(ground2);
    gameEngine.run();
    return 0;
}