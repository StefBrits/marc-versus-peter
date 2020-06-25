#ifndef STEFSPACE_FACTORYSDL_H
#define STEFSPACE_FACTORYSDL_H


#include "AbstractFactory.h"
#include "../Entitites_Abstract/GameOver.h"

namespace SDL {
    class FactorySDL : public gameLogic::AbstractFactory {
    public:
        gameLogic::Enemy* createEnemy(int xCoordinate, int yCoordinate, int xBound, int yBound, gameLogic::AbstractHandler* abstractHandler) override;
        gameLogic::Player* createPlayer(int xBound, int yBound, gameLogic::AbstractController* abstractController, gameLogic::AbstractHandler* abstractHandler, bool isCool) override;
        gameLogic::Bonus* createBonus(int xCoordinate, int yCoordinate, int xBound, int yBound, gameLogic::AbstractHandler* abstractHandler) override;
        gameLogic::Bullet* createBullet(int xCoordinate, int yCoordinate, int xBound, int yBound,bool isFriendly, gameLogic::AbstractHandler* abstractHandler) override;
        gameLogic::GameOver *createGameOver(int xBound,int yBound, gameLogic::AbstractHandler *abstractHandler, int isWin) override;
        gameLogic::AbstractController* createController() override;
        gameLogic::AbstractHandler* createHandler(gameLogic::AbstractController* abstractController) override;
        ~FactorySDL() = default;
    };
}

#endif //STEFSPACE_FACTORYSDL_H
