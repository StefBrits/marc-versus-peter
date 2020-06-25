#ifndef STEFSPACE_ENEMYSDL_H
#define STEFSPACE_ENEMYSDL_H


#include <SDL2/SDL_render.h>
#include "../Handlers/HandlerSDL.h"
#include "../Entitites_Abstract/Enemy.h"

namespace SDL {
    class EnemySDL : public gameLogic::Enemy{
        SDL::HandlerSDL* handlerSDL{};
        SDL_Texture* texture{};
        SDL_Texture* textureShoot{};
        int health = 3;
    public:
        EnemySDL(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound, int yBound,
                 bool isExisting, int scoreWorth, int rateOfFire,  gameLogic::AbstractHandler *handler);
        void draw() override ;



    };

}
#endif //STEFSPACE_ENEMYSDL_H
