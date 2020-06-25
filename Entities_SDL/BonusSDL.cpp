#include "BonusSDL.h"
#include <iostream>
#include <SDL2/SDL_image.h>

SDL::BonusSDL::BonusSDL(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound, int yBound,
                        bool isExisting, int scoreWorth, gameLogic::AbstractHandler *handler) : Bonus(xCoordinate, yCoordinate, speed, width, height, xBound, yBound, isExisting, scoreWorth) {

    handlerSDL = (SDL::HandlerSDL*) handler;
    SDL_Surface* tempSurface = IMG_Load("..//files//Bonus.png");
    texture = SDL_CreateTextureFromSurface(handlerSDL->renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
}

void SDL::BonusSDL::draw() {
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
    SDL_RenderCopy(handlerSDL->renderer, texture, &src, &dest);
}
