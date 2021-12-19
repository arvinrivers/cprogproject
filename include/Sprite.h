#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
class GameEngine;
class Sprite
{
public:
	virtual void draw() const = 0;
    virtual void tick(GameEngine* ge){}
	SDL_Rect getRect() const { return rect; }
    virtual ~Sprite(){}
    virtual void keyRight(const SDL_Event& event) {}
	virtual void keyLeft(const SDL_Event& event) {}
protected:
	Sprite(int x, int y, int w, int h) : rect{ x,y,w,h } {}
	SDL_Rect rect;
private:
    Sprite(const Sprite& other) = delete;
    const Sprite& operator=(const Sprite& other) = delete;
};

#endif