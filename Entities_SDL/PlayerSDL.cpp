#include "PlayerSDL.h"
#include <SDL2/SDL_image.h>


SDL::PlayerSDL::PlayerSDL(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound,
                          int yBound, bool isExisting, gameLogic::AbstractController *pController ,
                          gameLogic::AbstractHandler *handler, bool isCool) : Player(xCoordinate, yCoordinate, speed, width, height, xBound, yBound, isExisting, pController, isCool) {
    handlerSDL = (SDL::HandlerSDL*) handler;
    SDL_Surface* tempSurface = IMG_Load("..//files//Peter.png");
    SDL_Surface* tempSurfaceShoot = IMG_Load("..//files//PeterSchiet.png");
    SDL_Surface* coolSurface = IMG_Load("..//files//AgentPeter.png");

    texture = SDL_CreateTextureFromSurface(handlerSDL->renderer, tempSurface);
    textureShoot = SDL_CreateTextureFromSurface(handlerSDL->renderer, tempSurfaceShoot);
    textureCool = SDL_CreateTextureFromSurface(handlerSDL->renderer, coolSurface);
    SDL_FreeSurface(tempSurface);

}

void SDL::PlayerSDL::draw() {
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
    if(getIsCool()) {
        SDL_RenderCopy(handlerSDL->renderer, textureCool, &src, &dest);
    }
    else if(getIsShooting()) {
        SDL_RenderCopy(handlerSDL->renderer, textureShoot, &src, &dest);
    }
    else {
        SDL_RenderCopy(handlerSDL->renderer, texture, &src, &dest);
    }

}



