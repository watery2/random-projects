#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "include/Entity.hpp"
#include "include/RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h) :window(NULL), renderer(NULL){
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if(window==NULL){
        std::cout<< "window failed to init error:"<< SDL_GetError() <<std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath){
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if(texture == NULL){
        std::cout<<"failed to load texture"<< SDL_GetError() << std::endl;
    }

    return texture;
}

void RenderWindow::cleanUp(){
    SDL_DestroyWindow(window);
}
void RenderWindow::clear(){
    SDL_RenderClear(renderer);
}
void RenderWindow::render(Entity& p_entity){

    Uint32 ticks = SDL_GetTicks();
    Uint32 seconds = ticks / 1000;
    Uint32 sprite = (ticks / 100) % p_entity.frame;

    // this thing save the x y 
    SDL_Rect src;
    //
    src.x = sprite * 32;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;
    // the destination
    SDL_Rect dst;
    dst.x = p_entity.getX();
    dst.y = p_entity.getY();
    dst.w = p_entity.getW() * 4;
    dst.h = p_entity.getH() * 4;

    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}
void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}