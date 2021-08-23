#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"

class Events{
    public:
        bool jumping = false;
        bool shooting = false;
        float y, y2,y3, go_to;
        void startJump(Entity& p_entity,float p_y, float p_go_to);
        void Jump(Entity& p_entity,float speed);
        void startShoot(Entity& p_entity,float p_x, float p_y);
        void Shoot(Entity& p_entity, float speed);
        float Collision(Entity& p_entety1, Entity& p_entety2, float range);

};