#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity{
    public:
        bool dead = false;
        int frame;
        Entity(float p_x, float p_y, float p_w ,float p_h, SDL_Texture* p_tex, int p_frames);
        float getX();
        float getY();
        float setX(float p_x);
        float setY(float p_y);
        float getW();
        float getH();
        SDL_Texture* setTex(SDL_Texture* p_tex);
        SDL_Texture* getTex();
        SDL_Rect getCurrentFrame();


    private:
        float x, y, w, h;
        SDL_Rect currentFrame;
        SDL_Texture* tex;
};