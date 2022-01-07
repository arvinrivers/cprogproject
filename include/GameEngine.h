#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Sprite.h"
#include <vector>

class GameEngine
{
public:
	void add(Sprite*);
	void remove(Sprite*);
	void run();
	std::vector<Sprite*> grounds, enemies, collectables, added, players;
private:
	std::vector<Sprite*> sprites;	
	std::vector<Sprite*> removed;
};

#endif