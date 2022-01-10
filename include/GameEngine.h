/*
Central klass för biblioteket. Sköter allt från vilka sprites som visas på skärmen
till själva tick-systemet.
*/

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
	
	//Grounds, enemies, collectables och players är de sprites som syns på skärmen ett givet tick
	//added är de nya sprites som skall ritas upp av spelmotorn denna tick
	std::vector<Sprite*> grounds, enemies, collectables, added, players;
private:
	void removeHelp(std::vector<Sprite*>);
	//Sprites är alla sprites som finns på skärmen ett givet tick
	std::vector<Sprite*> sprites;	
	//Removed är alla sprites som skall tas bort av spelmotorn ett givet tick
	std::vector<Sprite*> removed;
};

#endif