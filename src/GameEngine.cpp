/*
Central klass för biblioteket. Sköter allt från vilka sprites som visas på skärmen
till själva tick-systemet.
*/

#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "Sprite.h"
#include "System.h"
#include "Ground.h"
#include "Enemy.h"
#include "Player.h"
#include "Collectable.h"
#include <iostream>
#define FPS 60
using namespace std;

//Lägger till en ny sprite i spelsystemet till nästa tick
void GameEngine::add(Sprite* sprite) {
	added.push_back(sprite);
	if (Ground* ground = dynamic_cast<Ground*>(sprite)){
		grounds.push_back(ground);
	}
	if (Enemy* enemy = dynamic_cast<Enemy*>(sprite)){
		enemies.push_back(enemy);
	}
	if (Collectable* col = dynamic_cast<Collectable*>(sprite)){
		collectables.push_back(col);
	}
	if (Player* player = dynamic_cast<Player*>(sprite)){
		players.push_back(player);
	}
}

//Plockar bort en sprite från spelsystemet till nästa tick
void GameEngine::remove(Sprite* sprite) {
	removed.push_back(sprite);
}

//Loopen som tillhandahåller hela spelomgången
void GameEngine::run() {
	bool quit = false;
	const int tickIntervall = 1000/FPS;
	while (!quit) {
		Uint32 nextTick = SDL_GetTicks() + tickIntervall;
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT: quit = true; 
            break;
			case SDL_KEYDOWN:
			for (Sprite* s : sprites)
				 s->keyDown(event);
			break;
			}
		}
		for (Sprite* s : sprites)
			s->tick(this);
		for (Sprite* s : added)
			sprites.push_back(s);
		added.clear();
		for (Sprite* s : removed) {
			for (vector<Sprite*>::iterator i = sprites.begin(); i != sprites.end();) {
				if (*i == s) {
					i = sprites.erase(i);
				}
				else
					i++;
			}
		}
		removed.clear();
		
		SDL_RenderClear(sys.get_renderer());
		SDL_SetRenderDrawColor(sys.get_renderer(), 255, 255, 255, 255);
		for (Sprite* s : sprites){
			s->draw();
		}
		SDL_RenderPresent(sys.get_renderer());
		int delay = nextTick - SDL_GetTicks();
        if(delay > 0){
            SDL_Delay(delay);
        }
	}
}
