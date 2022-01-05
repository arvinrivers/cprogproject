#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "Sprite.h"
#include "Player.h"

int main(int argc, char* argv[]) {
    GameEngine gameEngine;
    Player* player = new Player(100,100,50,50, "C:/Users/arsol/OneDrive/Skrivbord/cprogproject-5/resources/images/821759741633626212.png");
    gameEngine.add(player);
    gameEngine.run();
    return 0;
}