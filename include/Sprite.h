#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <string>
using namespace std;
class GameEngine;
class Sprite
{
public:
	virtual void draw() const = 0;
    virtual void tick(GameEngine* ge){}
	SDL_Rect getRect() const { return rect; }
    virtual ~Sprite(){}
    virtual void keyDown(const SDL_Event& event) {}
    bool isGrounded(){return grounded;}
    bool isAffectedByGravity(){return affectedByGravity;}
protected:
	Sprite(int x, int y, int w, int h, const string& imgPath);
    bool affectedByGravity = false;
    SDL_Texture* getTexture() const { return texture; }
    SDL_Rect rect;
private:
    bool grounded = false;
    Sprite(const Sprite& other) = delete;
    const Sprite& operator=(const Sprite& other) = delete;
    SDL_Texture* texture = nullptr;
};

#endif