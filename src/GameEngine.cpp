#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "Sprite.h"
#include "System.h"

#define FPS 60


using namespace std;

void GameEngine::add(Sprite* sprite) {
	added.push_back(sprite);
}

void GameEngine::remove(Sprite* sprite) {
	removed.push_back(sprite);
}

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
			}
		}

		for (Sprite* s : sprites)
			s->tick(this);
		for (Sprite* s : added)
			sprites.push_back(s);
		added.clear();
		for (Sprite* s : removed)
			for (vector<Sprite*>::iterator i = sprites.begin();
				i != sprites.end();)
				if (*i == s) {
					i = sprites.erase(i);
				}
				else
					i++;
		removed.clear();
		
		SDL_RenderClear(sys.get_renderer());
		SDL_SetRenderDrawColor(sys.get_renderer(), 255, 255, 255, 255);
		//SDL_RenderClear(sys.get_renderer());
		for (Sprite* s : sprites)
			s->draw();
		SDL_RenderPresent(sys.get_renderer());
		int delay = nextTick - SDL_GetTicks();
        if(delay > 0){
            SDL_Delay(delay);
        }
	}
}
