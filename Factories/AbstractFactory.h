#ifndef STEFSPACE_ABSTRACTFACTORY_H
#define STEFSPACE_ABSTRACTFACTORY_H

#include "../Entitites_Abstract/Enemy.h"
#include "../Entitites_Abstract/Player.h"
#include "../Entitites_Abstract/Bullet.h"
#include "../Entitites_Abstract/Bonus.h"
#include "../Controllers/AbstractController.h"
#include "../Handlers/AbstractHandler.h"
#include "../Entitites_Abstract/GameOver.h"
#include "../Music/AbstractSoundHandler.h"

namespace gameLogic {
    class AbstractFactory {

    public:
        virtual Enemy* createEnemy(int xCoordinate, int yCoordinate, int xBound, int yBound, gameLogic::AbstractHandler* abstractHandler) = 0;
        virtual Player* createPlayer(int xBound, int yBound, gameLogic::AbstractController* abstractController, gameLogic::AbstractHandler* abstractHandler, bool isCool) = 0;
        virtual Bonus* createBonus(int xCoordinate, int yCoordinate, int xBound, int yBound, gameLogic::AbstractHandler* abstractHandler) = 0;
        virtual Bullet* createBullet(int xCoordinate, int yCoordinate, int xBound, int yBound, bool isFriendly, gameLogic::AbstractHandler* abstractHandler) = 0;
        virtual AbstractController* createController() = 0;
        virtual AbstractHandler* createHandler(gameLogic::AbstractController* abstractController) = 0;
        virtual GameOver* createGameOver(int xBound, int yBound, gameLogic::AbstractHandler* abstractHandler, int isWin) = 0;
        virtual AbstractSoundHandler* createSoundHandler() =0;
        virtual ~AbstractFactory() = default;
    };

}
#endif //STEFSPACE_ABSTRACTFACTORY_H
