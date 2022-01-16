/*
Basklass för objekt i spelvärlden. Kommer med en uppsjö av funktionalitet som exempelvis
gravitation, att kunna hoppa (om objektet är levande, ex. spelare och fiender) samt 
funktioner för att kunna ritas upp på skärmen.
*/

#include "Sprite.h"
#include "System.h"
#include "GameEngine.h"

//Konstruktor
Sprite::Sprite(int x, int y, int w, int h, const std::string& imgPath): rect{x,y,w,h}{
    SDL_Surface* surface = IMG_Load(imgPath.c_str());
    texture = SDL_CreateTextureFromSurface(sys.get_renderer(), surface);
    SDL_FreeSurface(surface);
    setJumping(false);
    walkingGround = nullptr;
}

//Kollar huruvida sprite-en står på en plattform, hoppar eller faller och sätter hastigheten därefter.
void Sprite::updateGrounded(std::vector<Sprite*> grounds){
    if(!grounded){
        ticksSinceGrounded += 1;
    }
    if(jumping && jumpCounter > 0){
        jumpCounter -= 1;
        if (jumpCounter%5 == 0){
            verticalSpeed += 1;
        }
        return;
    }else if(jumping){
        ticksSinceGrounded = 0;
        setJumping(false);
    }
    if (affectedByGravity){
        SDL_Rect sprite = rect;
        int spriteMidPoint = (sprite.x + sprite.x + sprite.w) / 2;
        int spriteHeight = sprite.y + sprite.h;
        for(Sprite* ground : grounds){
            SDL_Rect groundRect = ground->rect;
            int groundLeftEdge = groundRect.x;
            int y = groundRect.y;
            int groundRightEdge = groundRect.x + groundRect.w;
            if((spriteHeight == y) && (groundLeftEdge < spriteMidPoint) && (spriteMidPoint < groundRightEdge)){
                grounded = true;
                ticksSinceGrounded = 0;
                verticalSpeed = 0;
                walkingGround = ground;
                return;
            }else if((groundLeftEdge < spriteMidPoint) && (spriteMidPoint < groundRightEdge) && (spriteHeight < y) && (spriteHeight + getySpeed() > y)){
                verticalSpeed = y - spriteHeight;
                walkingGround = ground;
                return;
            }
            
        }
    }
    setySpeed(getGravityForce());
    walkingGround = nullptr;
    grounded = false;
}

//Get-metod för huruvida objektet har fötterna på marken
bool Sprite::isGrounded(){
    return grounded;
}

//Beräknar hur mycket objektet ska påverkas av gravitation under denna tick. Eskalerar över tid
int Sprite::getGravityForce(){
    int force = (ticksSinceGrounded * ticksSinceGrounded) / 50;
    if(force >=5){
        return 5;
    } else if(force < -5){
        return -5;
    }
    return force;
}

//Sätter objektet i ett hoppande tillstånd
void Sprite::setJumping(bool state){
    jumping = state;
    setGrounded(false);
    if(state){
        jumpCounter = 40;
        verticalSpeed = -6;
    }
}

//Kollar huruvida angivna objekt kolliderar med varandra
bool Sprite::checkCollision(const SDL_Rect& a, const SDL_Rect& b) {
     return (a.x+a.w > b.x && b.x+b.w > a.x && a.y + a.h > b.y && b.y+b.h > a.y);
}

//Ritar upp objektet på skärmen
void Sprite::draw() const{
        const SDL_Rect &rect = getRect();
		SDL_RenderCopy(sys.get_renderer(), getTexture(), NULL, &rect);
}