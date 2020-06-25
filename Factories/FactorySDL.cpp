#include "FactorySDL.h"
#include "../Controllers/ControllerSDL.h"
#include "../Handlers/HandlerSDL.h"
#include "../Entities_SDL/EnemySDL.h"
#include "../Entities_SDL/PlayerSDL.h"
#include "../Entities_SDL/BonusSDL.h"
#include "../Entities_SDL/BulletSDL.h"
#include "../Entitites_Abstract/GameOver.h"
#include "../Entities_SDL/GameOverSDL.h"
#include "../Music/SoundHandlerSDL.h"

gameLogic::Enemy *SDL::FactorySDL::createEnemy(int xCoordinate, int yCoordinate, int xBound, int yBound, gameLogic::AbstractHandler* abstractHandler) {
    return new SDL::EnemySDL(xCoordinate, yCoordinate, 1, 165, 175, xBound, yBound, true, 20, 0, abstractHandler);
}

gameLogic::Player *SDL::FactorySDL::createPlayer(int xBound, int yBound, gameLogic::AbstractController* abstractController, gameLogic::AbstractHandler* abstractHandler, bool isCool) {
    return new SDL::PlayerSDL(xBound / 2, yBound-157, 6, 105, 157, xBound, yBound, true, abstractController, abstractHandler, isCool);
}

gameLogic::Bonus *SDL::FactorySDL::createBonus(int xCoordinate, int yCoordinate, int xBound, int yBound, gameLogic::AbstractHandler* abstractHandler) {
    return new SDL::BonusSDL(xCoordinate, yCoordinate, 1, 75, 75, xBound, yBound, true, 100, abstractHandler);
}

gameLogic::Bullet *SDL::FactorySDL::createBullet(int xCoordinate, int yCoordinate, int xBound, int yBound, bool isFriendly, gameLogic::AbstractHandler* abstractHandler) {
    return new SDL::BulletSDL(xCoordinate, yCoordinate, 4, 45, 45, xBound, yBound, true, isFriendly, abstractHandler);
}



gameLogic::AbstractController *SDL::FactorySDL::createController() {
    return new SDL::ControllerSDL();
}

gameLogic::AbstractHandler *SDL::FactorySDL::createHandler(gameLogic::AbstractController* abstractController) {
    return new SDL::HandlerSDL(abstractController);
}

gameLogic::GameOver *
SDL::FactorySDL::createGameOver(int xBound, int yBound, gameLogic::AbstractHandler *abstractHandler, int isWin) {
    return new SDL::GameOverSDL(xBound/4, yBound/4, 0, 576, 425, xBound, yBound, true, xBound, yBound, abstractHandler, isWin);
}

gameLogic::AbstractSoundHandler *SDL::FactorySDL::createSoundHandler() {
    return new SDL::SoundHandlerSDL();
}





