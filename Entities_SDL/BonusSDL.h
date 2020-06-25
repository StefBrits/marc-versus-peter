#ifndef STEFSPACE_BONUSSDL_H
#define STEFSPACE_BONUSSDL_H

#include "../Handlers/HandlerSDL.h"
#include "../Entitites_Abstract/Bonus.h"

namespace SDL {
class BonusSDL : public gameLogic::Bonus {
        SDL::HandlerSDL* handlerSDL{};
        SDL_Texture* texture{};
    public:
        BonusSDL(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound, int yBound,
                 bool isExisting, int scoreWorth, gameLogic::AbstractHandler *handler);
        void draw() override ;
    };

}
#endif //STEFSPACE_BONUSSDL_H
