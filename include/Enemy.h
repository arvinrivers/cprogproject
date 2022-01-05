#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>
#include "Sprite.h"

class Enemy : public Sprite
{
public:
    Enemy(int x, int y, int w, int h) : Sprite{ x, y, w, h}{
        affectedByGravity = true;
    }
};

#endif