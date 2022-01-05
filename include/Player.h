#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "Sprite.h"

class Player : public Sprite
{
public:
    Player(int x, int y, int w, int h) : Sprite{ x, y, w, h}{
        affectedByGravity = true;
    }
};

#endif