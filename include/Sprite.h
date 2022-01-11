/*
Basklass för objekt i spelvärlden. Kommer med en uppsjö av funktionalitet som exempelvis
gravitation, att kunna hoppa (om objektet är levande, ex. spelare och fiender) samt 
funktioner för att kunna ritas upp på skärmen.
*/

#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <string>
#include <vector>
using namespace std;


class GameEngine;
class Sprite
{
public:
	void draw() const;
    virtual void tick(GameEngine* ge){}
	SDL_Rect getRect() const { return rect; }
    virtual ~Sprite(){}
    virtual void keyDown(const SDL_Event& event) {}
    bool isGrounded();
    void updateGrounded(std::vector<Sprite*> grounds);
    void setGrounded(bool state){grounded = state;}
    bool isAffectedByGravity(){return affectedByGravity;}
    void setJumping(bool state);
    bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);
protected:
	Sprite(int x, int y, int w, int h, const string& imgPath);
    bool affectedByGravity = false;
    SDL_Texture* getTexture() const { return texture; }
    SDL_Rect rect;
    int getTicksSinceGrounded(){return ticksSinceGrounded;}
    int getySpeed(){return verticalSpeed;}
    void setySpeed(int speed){verticalSpeed = speed;}
    int getGravityForce();
    bool isJumping(){return jumping;}
    Sprite* getWalkingGround(){return walkingGround;}
private:
    bool grounded = true;
    bool jumping;
    int jumpCounter;
    Sprite(const Sprite& other) = delete;
    const Sprite& operator=(const Sprite& other) = delete;
    SDL_Texture* texture = nullptr;
    int verticalSpeed;
    int ticksSinceGrounded;
    Sprite* walkingGround;
};

#endif