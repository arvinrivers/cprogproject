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
    static MyPlayer* getInstance(int x, int y, int w, int h, const string& imgPath) {
		return new MyPlayer();
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
        if (getWinConditionMet()){
         gameEngine.remove(this);
         gameEngine.add(won);
        }
    }

    void loseConditionHandler(){
        if (getLoseConditionMet()){
         gameEngine.remove(this);
         gameEngine.add(lost);
        }
    }
    protected:
	MyPlayer() : Player(320, 40, 40, 40, resPath + "images/player.jpg")
	{
		
	}

};

int main(int argc, char* argv[]) {
    MyPlayer* player = MyPlayer::getInstance(320, 40, 40, 40, resPath + "images/player.jpg");
    Collectable* coin = Collectable::getInstance(660, 300, 40, 40, resPath + "images/coin.png");
    Ground* ground = Ground::getInstance(300, 300, 300, 20, resPath + "images/ground.jpg");
    Ground* ground2 = Ground::getInstance(15, 300, 250, 20, resPath + "images/ground.jpg");
    Enemy* enemy1 = Enemy::getInstance(50, 250, 40, 40, resPath + "images/enemy.jpg");
    enemy1->setSpeed(-10);
    gameEngine.add(player);
    gameEngine.add(enemy1);
    gameEngine.add(coin);
    gameEngine.add(ground);
    gameEngine.add(ground2);
    gameEngine.run();
    return 0;
}