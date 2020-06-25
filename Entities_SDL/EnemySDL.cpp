#include <SDL2/SDL_image.h>
#include <iostream>
#include "EnemySDL.h"

SDL::EnemySDL::EnemySDL(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound, int yBound,
                        bool isExisting, int scoreWorth, int rateOfFire,  gameLogic::AbstractHandler *handler) : Enemy(xCoordinate, yCoordinate, speed, width, height, xBound, yBound, isExisting, scoreWorth, rateOfFire) {
    handlerSDL = (SDL::HandlerSDL*) handler;
    SDL_Surface* tempSurface;
    SDL_Surface* tempSurfaceShoot;

    tempSurface = IMG_Load("..//files//Marc.png");
    tempSurfaceShoot = IMG_Load("..//files//MarcSchiet.png");

    texture = SDL_CreateTextureFromSurface(handlerSDL->renderer, tempSurface);
    textureShoot = SDL_CreateTextureFromSurface(handlerSDL->renderer, tempSurfaceShoot);
    SDL_FreeSurface(tempSurface);

}

void SDL::EnemySDL::draw() {
    SDL_Rect dest;
    SDL_Rect src;
    dest.h=dest.w=dest.x=dest.y=0;
    src.x=src.y=src.h=src.w=0;
    dest.x = getxCoordinate();
    dest.y = getyCoordinate();
    src.h = getHeight();
    src.w = getWidth();
    dest.h = getHeight();
    dest.w = getWidth();
    if(getIsShooting()) {
        SDL_RenderCopy(handlerSDL->renderer, textureShoot, &src, &dest);
    } else {
        SDL_RenderCopy(handlerSDL->renderer, texture, &src, &dest);
    }

}








