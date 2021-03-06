#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "Sprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Goal.h"
#include "Ground.h"
#include <iostream>
#include <string>

std::string resPath = "resources/";
Ground* won = Ground::getInstance(0 , 0, 700, 500, resPath + "images/won.jpg");
Ground* lost = Ground::getInstance(0 , 0, 700, 500, resPath + "images/lost.jpg");
GameEngine gameEngine;

class MyPlayer : public Player {

public:
    static MyPlayer* getInstance(int x, int y, int w, int h, const std::string& imgPath) {
		return new MyPlayer();
    }

	void keyDownHandler(const SDL_Event& event) 
	{
        SDL_Rect thisRect = getRect();
		switch (event.key.keysym.sym) 
		{
		case SDLK_RIGHT:
            if(thisRect.x < 660)
			    setRectX(thisRect.x + 15); 
			break;
	    case SDLK_LEFT: 
            if(thisRect.x > 0)
			    setRectX(thisRect.x - 15); 
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
            gameEngine.removeAll();
            gameEngine.add(won);
        }
    }

    void loseConditionHandler(){
        if (getLoseConditionMet()){
            gameEngine.removeAll();
            gameEngine.add(lost);
        }
    }
    protected:
	MyPlayer() : Player(25, 400, 40, 40, resPath + "images/player.jpg")
	{
		
	}

};

int main(int argc, char* argv[]) {
    MyPlayer* player = MyPlayer::getInstance(25, 400, 40, 40, resPath + "images/player.jpg");
    Goal* coin = Goal::getInstance(650, 50, 40, 40, resPath + "images/coin.png");
    Ground* ground = Ground::getInstance(300, 420, 300, 20, resPath + "images/ground.jpg");
    Ground* ground2 = Ground::getInstance(15, 360, 250, 20, resPath + "images/ground.jpg");
    Ground* ground3 = Ground::getInstance(300, 300, 250, 20, resPath + "images/ground.jpg");
    Ground* ground4 = Ground::getInstance(15, 240, 250, 20, resPath + "images/ground.jpg");
    Ground* ground5 = Ground::getInstance(280, 160, 420, 20, resPath + "images/ground.jpg");
    Ground* bottomGround = Ground::getInstance(0, 480, 700, 20, resPath + "images/ground.jpg");
    Enemy* enemy1 = Enemy::getInstance(50, 250, 40, 40, resPath + "images/enemy.jpg");
    Enemy* enemy2 = Enemy::getInstance(350, 340, 40, 40, resPath + "images/enemy.jpg");
    Enemy* enemy3 = Enemy::getInstance(350, 180, 40, 40, resPath + "images/enemy.jpg");
    Enemy* enemy4 = Enemy::getInstance(50, 100, 40, 40, resPath + "images/enemy.jpg");
    Enemy* enemy5 = Enemy::getInstance(400, 20, 40, 40, resPath + "images/enemy.jpg");
    Enemy* enemy6 = Enemy::getInstance(600, 400, 40, 40, resPath + "images/enemy.jpg");
    enemy1->setSpeed(-2);
    enemy2->setSpeed(-2);
    enemy3->setSpeed(-2);
    enemy4->setSpeed(-3);
    enemy5->setSpeed(2);
    enemy6->setSpeed(1);
    gameEngine.add(player);
    gameEngine.add(enemy1);
    gameEngine.add(enemy2);
    gameEngine.add(enemy3);
    gameEngine.add(enemy4);
    gameEngine.add(enemy5);
    gameEngine.add(enemy6);
    gameEngine.add(coin);
    gameEngine.add(ground);
    gameEngine.add(ground2);
    gameEngine.add(ground3);
    gameEngine.add(ground4);
    gameEngine.add(ground5);
    gameEngine.add(bottomGround);
    gameEngine.run();
    return 0;
}