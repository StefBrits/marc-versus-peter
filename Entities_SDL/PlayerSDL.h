#ifndef STEFSPACE_PLAYERSDL_H
#define STEFSPACE_PLAYERSDL_H

#include <SDL2/SDL_render.h>
#include "../Entitites_Abstract/Player.h"
#include "../Handlers/AbstractHandler.h"
#include "../Handlers/HandlerSDL.h"

namespace SDL {
    class PlayerSDL : public gameLogic::Player {
    SDL::HandlerSDL* handlerSDL;
    SDL_Texture* texture;
    SDL_Texture* textureShoot;
    SDL_Texture* textureCool;
    public:
        PlayerSDL(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound,
                  int yBound, bool isExisting, gameLogic::AbstractController *pController, gameLogic::AbstractHandler* handler, bool isCool);
        void draw() override ;
    };

}
#endif //STEFSPACE_PLAYERSDL_H
