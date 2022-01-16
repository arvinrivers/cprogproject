/*
Central klass för biblioteket. Sköter allt från vilka sprites som visas på skärmen
till själva tick-systemet.
*/

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Sprite.h"
#include <vector>
#include <string>

class GameEngine
{
public:
	void add(Sprite*);
	void remove(Sprite*);
	void run();

	void removeAll();
	
	//Grounds, enemies, goals och players är de sprites som syns på skärmen ett givet tick
	std::vector<Sprite*> grounds, enemies, goals, players;
private:
	void removeHelp(std::vector<Sprite*>);
	//Sprites är alla sprites som finns på skärmen ett givet tick
	std::vector<Sprite*> sprites;	

	//Sprites som skall ritas upp på skärmen ett givet tick
	std::vector<Sprite*> added;

	//Removed är alla sprites som skall tas bort av spelmotorn ett givet tick
	std::vector<Sprite*> removed;
};

#endif