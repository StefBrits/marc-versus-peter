//
// Created by koro-sensei on 11/05/2020.
//

#ifndef STEFSPACE_BULLETSDL_H
#define STEFSPACE_BULLETSDL_H

#include <SDL2/SDL_render.h>
#include "../Handlers/HandlerSDL.h"
#include "../Entitites_Abstract/Bullet.h"

namespace SDL {
    class BulletSDL : public gameLogic::Bullet {
        SDL::HandlerSDL* handlerSDL{};
        SDL_Texture* texture{};
    public:
        BulletSDL(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound,
                  int yBound, bool isExisting, bool isFriendly, gameLogic::AbstractHandler *handler);
        void draw() override ;
    };

}
#endif //STEFSPACE_BULLETSDL_H
