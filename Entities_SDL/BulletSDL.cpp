#include <SDL2/SDL_image.h>
#include <iostream>
#include "BulletSDL.h"

SDL::BulletSDL::BulletSDL(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound,
                          int yBound, bool isExisting, bool isFriendly, gameLogic::AbstractHandler *handler) : Bullet(xCoordinate, yCoordinate, speed, width, height, xBound, yBound, isExisting, isFriendly) {
    handlerSDL = (SDL::HandlerSDL*) handler;
    SDL_Surface* tempSurface;
    if(isFriendly) {
        tempSurface = IMG_Load("..//files//PeterBullet.png");
    } else {
        tempSurface = IMG_Load("..//files//CoronaBullet.png");
    }

    texture = SDL_CreateTextureFromSurface(handlerSDL->renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}

void SDL::BulletSDL::draw() {
    SDL_Rect dest;
    SDL_Rect src;
    dest.h=dest.w=dest.x=dest.y=0;
    src.x=src.y=src.h=src.w=0;
    dest.x = getxCoordinate();
    dest.y = getyCoordinate();
    src.h = 75;
    src.w = 75;
    dest.h = getHeight();
    dest.w = getWidth();
    SDL_RenderCopy(handlerSDL->renderer, texture, &src, &dest);
}
