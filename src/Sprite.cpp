#include "Sprite.h"
#include "System.h"
#include "GameEngine.h"
#include <iostream>
#include <string>

Sprite::Sprite(int x, int y, int w, int h, const string& imgPath): rect{x,y,w,h}{
    SDL_Surface* surface = IMG_Load(imgPath.c_str());
    texture = SDL_CreateTextureFromSurface(sys.get_renderer(), surface);
    SDL_FreeSurface(surface);


}
void Sprite::updateGrounded(std::vector<Sprite*> grounds){
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
                return;
            }
            
        }
    }
    grounded = false;
}
bool Sprite::isGrounded(){
    return grounded;
}