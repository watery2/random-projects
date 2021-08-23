#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "include/Entity.hpp"

Entity::Entity(float p_x, float p_y, float p_w ,float p_h, SDL_Texture* p_tex, int p_frames):x(p_x), y(p_y),w(p_w),h(p_h),tex(p_tex), frame(p_frames){
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;

}
float Entity::getX(){
    return x;
}
float Entity::getY(){
    return y;
}
float Entity::getW(){
    return w;
}
float Entity::getH(){
    return h;
}
float Entity::setX(float p_x){
    x = p_x;
}
float Entity::setY(float p_y){
    y = p_y;
}

SDL_Texture* Entity::getTex(){
    return tex;
}
SDL_Rect Entity::getCurrentFrame(){
    return currentFrame;
}
SDL_Texture* Entity::setTex(SDL_Texture* p_tex){
    tex = p_tex;
}
