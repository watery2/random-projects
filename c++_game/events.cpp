#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cmath>

#include "include/Entity.hpp"
#include "include/events.hpp"
#include "include/RenderWindow.hpp"

void Events::startJump(Entity& p_entity, float p_y, float p_go_to){
    if (jumping == false && p_entity.dead == false){
        y = p_entity.getY();
        y2 = p_entity.getY();
        y3 = p_entity.getY();
        go_to = p_go_to;
        y -= p_y;
        y3 -= p_y;
        jumping = true;
    }
}
void Events::Jump(Entity& p_entity,float speed){
    if(jumping == true ){
        if(y2 > y){
            y2 -= speed;
            p_entity.setY(y2);
        }else if (y2 <= y){
            if(go_to  > y3){
                y3 += speed;
                p_entity.setY(y3);
            }else{
                y = 0;
                y2 = 0;
                y3 = 0;
                go_to  = 0;
                jumping = false;

            }
        }
    }
    
}
void Events::startShoot(Entity& p_entity, float p_x, float p_y){
    if(shooting == false && p_entity.dead == false){
        p_entity.setX(p_x);
        p_entity.setY(p_y);
        shooting = true;
    }
}
void Events::Shoot(Entity& p_entity, float speed){
    if(shooting == true){
        p_entity.setX(p_entity.getX() + speed);
        if(p_entity.getX() >= 1280){
            shooting = false;
            p_entity.setX(-1100);
            p_entity.setY(-100);
        }
    }
}
float Events::Collision(Entity& p_entety1, Entity& p_entety2, float range){
    float distance = sqrt(pow(p_entety1.getX()-p_entety2.getX(),2)+pow(p_entety1.getY()-p_entety2.getY(),2));
    if (distance < range && p_entety2.dead == false){
        return true;
    }else{
        return false;
    }
}
