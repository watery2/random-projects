#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>


#include "include/events.hpp"
#include "include/Entity.hpp"
#include "include/RenderWindow.hpp"

void HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

int main(int argc, char* args[]){
    HideConsole();
    // checks for erros
    if(SDL_Init(SDL_INIT_VIDEO) > 0){
        std::cout << "Someting Just Happend. WTF???" << SDL_GetError() << std::endl;
    }

    if(!(IMG_Init(IMG_INIT_PNG))){
        std::cout << "IMG_INIT HAS FAILED" << SDL_GetError() << std::endl;
    }

    RenderWindow window("Runner", 1280, 720);

    SDL_Texture* grassTexture = window.loadTexture("img/img/grass.png");

    Events m_event;
    Events m_event2;
    Events m_event3;
    float cord[2] = {1280, 2560};
    float wall_cord = 1;
    float enemy_cord = 0; 

    Entity sign(500, 310, 32 ,32, window.loadTexture("img/img/sign.png"), 1);
    Entity platforms[2] = {Entity(0,280,320,110, grassTexture, 1),Entity(1280,280,320,110, grassTexture, 1)};
    Entity wall(2000, 410, 32, 44, window.loadTexture("img/img/wall.png"), 1);
    Entity enemy(1280, 494, 32, 32, window.loadTexture("img/img/enemy.png"), 1);
    Entity player(100,494,32 ,32, window.loadTexture("img/img/guy.png"), 10);
    Entity bullet(-1000, -100, 16, 16, window.loadTexture("img/img/bullet.png"), 1);
    Entity backgroud(0, 0, 320, 180, window.loadTexture("img/img/background.png"), 1);

    bool dead = true;
    bool gameRunning = true;
    int faze = 1;
    float speed = 10;

    SDL_Event event;

    while(gameRunning){

        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                gameRunning = false;
            }
            if (event.type == SDL_KEYDOWN){
                switch(event.key.keysym.sym){
                    case SDLK_SPACE:
                        m_event.startJump(player, 400, 494);
                        break;
                    case SDLK_f:
                        m_event.startShoot(bullet, player.getX() +100, player.getY() + 25);
                        break;
                    case SDLK_e:
                        if(dead == true){
                            faze++;
                        }
                        break;
                }
            }
        }
            
        window.clear();
        window.render(backgroud);
        switch(faze){
            case 1:
                window.render(sign);
                player.frame = 10;
                player.setTex(window.loadTexture("img/img/guy.png"));
                player.dead = false;
                player.setY(494);
                enemy.setX(1280);
                enemy.setY(494);
                wall.setX(2000);
                break;
            case 2:
                dead = false;
                for(int i = 0; i < 2; i++){
                    window.render(platforms[i]); 
                }
        
                window.render(player);
                window.render(wall);
                window.render(enemy);
                window.render(bullet);

                float a = platforms[0].getX();
                float b = platforms[1].getX();
                if(a <= -1280){
                    a = 1280;
                    platforms[0].setX(a);
                }else if(b <= -1280){
                    b = 1280;
                    platforms[1].setX(b);
                }
                if(wall.getX() < -128){
                    wall_cord = rand() % 2;
                    if (enemy_cord == 1){
                        wall.setX(cord[0]);
                    }else{
                        wall.setX(cord[1]);
                    }
                }
                if(enemy.getX() < -128 || enemy.getY() > 720){
                    enemy_cord = rand() % 2;
                    if (wall_cord == 1){
                        enemy.setTex(window.loadTexture("img/img/enemy.png"));
                        enemy.setX(cord[0]);
                        enemy.setY(494);
                        enemy.dead = false;
                    }else{
                        enemy.setTex(window.loadTexture("img/img/enemy.png"));
                        enemy.setX(cord[1]);
                        enemy.setY(494);
                        enemy.dead = false;
                    }
                }
                a -= speed;
                b -= speed;
                platforms[0].setX(a);
                platforms[1].setX(b);
                wall.setX(wall.getX()- speed);
                enemy.setX(enemy.getX()- speed);

                m_event.Shoot(bullet, 20);
                m_event.Jump(player, 10);
                m_event3.Jump(player, 10);
                if(m_event.Collision(bullet, enemy, 100)){
                    enemy.setTex(window.loadTexture("img/img/enemy_dead.png"));
                    m_event2.startJump(enemy, 100, 720);
                    enemy.dead = true;
                }
                m_event2.Jump(enemy, 10);
                if(m_event.Collision(player, wall, 100)){
                    player.frame = 1;
                    player.setTex(window.loadTexture("img/img/guy_dead.png"));
                    m_event3.startJump(player,100, 720);
                    player.dead = true;
                }
                if(m_event.Collision(player, enemy, 100)){
                    player.frame = 1;
                    player.setTex(window.loadTexture("img/img/guy_dead.png"));

                    m_event3.startJump(player,100, 720);
                    player.dead = true;
                }
                if(player.getY() >= 720){
                    dead = true;
                    faze--;
                }
                break;


        }

        window.display();


    }

    window.cleanUp();
    SDL_Quit();
    
    return 0;
}