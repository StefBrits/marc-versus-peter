#include <iostream>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include "HandlerSDL.h"

//Constructor
SDL::HandlerSDL::HandlerSDL(gameLogic::AbstractController* abstractController) {
    this->controller = abstractController;


}


void SDL::HandlerSDL::initialize(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "subsystems Initialised!..." << std::endl;

        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_RENDERER_ACCELERATED);
        if (window)
            std::cout << "window created!.." << std::endl;
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 20, 169, 225);
            std::cout << "renderer created!.." << std::endl;
        }
    }
}

void SDL::HandlerSDL::clear() {
    SDL_RenderClear(renderer);

    SDL_Rect dest;
    SDL_Rect src;
    dest.h=dest.w=dest.x=dest.y=0;
    src.x=src.y=src.h=src.w=0;
    dest.x = 0;
    dest.y = 0;
    src.h = 800;
    src.w = 1000;
    dest.h = 800;
    dest.w = 1000;

    if(isOnce) {
        srand ( time(NULL) );
        random = rand() % 11 + 1;
        backGroundA = "..//files//"+ std::to_string(random) +".jpg";
        backGroundStart = "..//files//wat.png";
        tempSurfaceA = IMG_Load(backGroundA.c_str());
        tempSurfaceStart = IMG_Load(backGroundStart.c_str());
        textureA = SDL_CreateTextureFromSurface(renderer, tempSurfaceA);
        textureStart = SDL_CreateTextureFromSurface(renderer, tempSurfaceStart);
        SDL_FreeSurface(tempSurfaceA);
        SDL_FreeSurface(tempSurfaceStart);
        isOnce = false;
    }






    SDL_RenderCopy(renderer, textureA, &src, &dest);
}

void SDL::HandlerSDL::render() {
    SDL_RenderPresent(renderer);
}

void SDL::HandlerSDL::handleEvents() {
    SDL_PollEvent(&event);
    if((event.type)==SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                controller->pressLeft(true);
                break;

            case SDLK_RIGHT:
                controller->pressRight(true);
                break;
            case SDLK_SPACE:
                controller->pressShoot(true);
                break;
        }
    }
        else {
            switch(event.key.keysym.sym) {
                case SDLK_LEFT:
                    controller->pressLeft(false);
                    break;

                case SDLK_RIGHT:
                    controller->pressRight(false);
                    break;
                case SDLK_SPACE:
                    controller->pressShoot(false);
                    break;
            }
        }
}

void SDL::HandlerSDL::setIsOnce(bool isOnces) {
    this->isOnce = isOnces;
}



