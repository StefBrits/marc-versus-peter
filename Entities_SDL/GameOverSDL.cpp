//
// Created by koro-sensei on 13/06/2020.
//

#include <SDL2/SDL_image.h>
#include "GameOverSDL.h"


SDL::GameOverSDL::GameOverSDL(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound1,
                              int yBound1, bool isExisting, int xBound, int yBound,
                              gameLogic::AbstractHandler *handler, int isWin) : GameOver(xCoordinate, yCoordinate, speed, width, height, xBound1, yBound1, isExisting, isWin) {

    handlerSDL = (SDL::HandlerSDL*) handler;
    SDL_Surface* tempSurface;
    SDL_Surface* tempSurface2;
    SDL_Surface* tempSurface3;
    SDL_Surface* tempSurface4;
    SDL_Surface* tempSurface5;
    tempSurface = IMG_Load("..//files//VictoryRoyale.png");
    tempSurface2 = IMG_Load("..//files//ZiekePeter.png");
    tempSurface3 = IMG_Load("..//files//wat.png");
    tempSurface4 = IMG_Load("..//files//wat2.png");
    tempSurface5 = IMG_Load("..//files//wat3.png");
    textureWin = SDL_CreateTextureFromSurface(handlerSDL->renderer, tempSurface);
    textureLose = SDL_CreateTextureFromSurface(handlerSDL->renderer, tempSurface2);
    textureStart = SDL_CreateTextureFromSurface(handlerSDL->renderer, tempSurface3);
    textureStart2 = SDL_CreateTextureFromSurface(handlerSDL->renderer, tempSurface4);
    textureStart3 = SDL_CreateTextureFromSurface(handlerSDL->renderer, tempSurface5);
    SDL_FreeSurface(tempSurface);
}

void SDL::GameOverSDL::draw() {
    SDL_Rect dest;
    SDL_Rect src;
    if(getIsWin()==0 || getIsWin()==1) {
        dest.h=dest.w=dest.x=dest.y=0;
        src.x=src.y=src.h=src.w=0;
        dest.x = getxCoordinate();
        dest.y = getyCoordinate();
        src.h = getHeight()*3;
        src.w = getWidth()*2;
        dest.h = getHeight();
        dest.w = getWidth();
    }
    else if (getIsWin()==2 || getIsWin()==3 || getIsWin()==4){

        dest.h=dest.w=dest.x=dest.y=0;
        src.x=src.y=src.h=src.w=0;
        dest.x = 0;
        dest.y = 0;
        src.h = 800;
        src.w = 1000;
        dest.h = 800;
        dest.w = 1000;

    }
    if(getIsWin()==1) {
        SDL_RenderCopy(handlerSDL->renderer, textureWin, &src, &dest);
    } else if(getIsWin()==0) {
        SDL_RenderCopy(handlerSDL->renderer, textureLose, &src, &dest);
    } else if(getIsWin()==2) {
        SDL_RenderCopy(handlerSDL->renderer, textureStart, &src, &dest);
    } else if(getIsWin()==3) {
        SDL_RenderCopy(handlerSDL->renderer, textureStart2, &src, &dest);
    } else if(getIsWin()==4) {
        SDL_RenderCopy(handlerSDL->renderer, textureStart3, &src, &dest);
    }
}

