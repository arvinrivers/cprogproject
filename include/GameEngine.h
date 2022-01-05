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
private:
	std::vector<Sprite*> sprites;
	std::vector<Sprite*> added, removed;
};

#endif