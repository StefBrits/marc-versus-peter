//
// Created by koro-sensei on 13/06/2020.
//

#ifndef STEFSPACE_GAMEOVERSDL_H
#define STEFSPACE_GAMEOVERSDL_H

#include "../Entitites_Abstract/GameOver.h"
#include "../Handlers/HandlerSDL.h"

namespace SDL {
class GameOverSDL : public gameLogic::GameOver {


    SDL::HandlerSDL* handlerSDL{};
    SDL_Texture* textureWin{};
    SDL_Texture* textureLose{};
    SDL_Texture* textureStart{};
    SDL_Texture* textureStart2{};
    SDL_Texture* textureStart3{};

public:
    GameOverSDL(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound1,
                int yBound1, bool isExisting, int xBound, int yBound,
                gameLogic::AbstractHandler *handler, int isWin);
    void draw() override ;
};

};


#endif //STEFSPACE_GAMEOVERSDL_H
