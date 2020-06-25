#ifndef STEFSPACE_HANDLERSDL_H
#define STEFSPACE_HANDLERSDL_H

#include <SDL2/SDL_render.h>
#include <SDL_events.h>
#include "AbstractHandler.h"
#include "../Controllers/AbstractController.h"
#include "../Controllers/ControllerSDL.h"
#include <string>

namespace SDL {
class HandlerSDL : public gameLogic::AbstractHandler{
    int random;
    bool isOnce=1;
    int i;
    SDL_Surface* tempSurfaceA;
    SDL_Surface* tempSurfaceStart;
    std::string backGroundA;
    std::string backGroundStart;
    SDL_Event event;
    SDL_Window* window;
    gameLogic::AbstractController* controller;
    SDL_Texture* textureA{};


public:
    SDL_Renderer* renderer;

    HandlerSDL(gameLogic::AbstractController* abstractController);
    void initialize(const char* title, int width, int height) override;
    void clear() override;
    void render() override;
    void handleEvents() override ;
    void setIsOnce(bool IsOnces)override ;
};

}
#endif //STEFSPACE_HANDLERSDL_H
