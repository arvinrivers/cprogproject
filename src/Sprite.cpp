#include "Sprite.h"
#include "System.h"
#include "GameEngine.h"
#include <iostream>
#include <string>

Sprite::Sprite(int x, int y, int w, int h, const string& imgPath): rect{x,y,w,h}{
    SDL_Surface* surface = IMG_Load(imgPath.c_str());
    texture = SDL_CreateTextureFromSurface(sys.get_renderer(), surface);
    SDL_FreeSurface(surface);
    setJumping(false);
    walkingGround = nullptr;


}
void Sprite::updateGrounded(std::vector<Sprite*> grounds){
    if(!grounded){
        ticksSinceGrounded += 1;
    }
    if(jumping && jumpCounter > 0){
        jumpCounter -= 1;
        if (jumpCounter%5 == 0){
            ySpeed += 1;
        }
        return;
    }else if(jumping){
        ticksSinceGrounded = 0;
        setJumping(false);
    }
    if (affectedByGravity){
        SDL_Rect sprite = rect;
        int sx = (sprite.x + sprite.x + sprite.w) / 2;
        int sy = sprite.y + sprite.h;
        for(Sprite* ground : grounds){
            SDL_Rect groundRect = ground->rect;
            int x1 = groundRect.x;
            int y = groundRect.y;
            int x2 = groundRect.x + groundRect.w;
            if((sy == y) && (x1 < sx) && (sx < x2)){
                grounded = true;
                ticksSinceGrounded = 0;
                ySpeed = 0;
                walkingGround = ground;
                return;
            }else if((x1 < sx) && (sx < x2) && (sy < y) && (sy + getySpeed() > y)){
                ySpeed = y - sy;
                walkingGround = ground;
                return;
            }
            
        }
    }
    setySpeed(getGravityForce());
    walkingGround = nullptr;
    grounded = false;
}
bool Sprite::isGrounded(){
    return grounded;
}
int Sprite::getGravityForce(){
    int force = (ticksSinceGrounded * ticksSinceGrounded) / 50;
    if(force >=5){
        return 5;
    } else if(force < -5){
        return -5;
    }
    return force;
}
void Sprite::setJumping(bool state){
    jumping = state;
    setGrounded(false);
    if(state){
        jumpCounter = 40;
        ySpeed = -6;
    }
    
}