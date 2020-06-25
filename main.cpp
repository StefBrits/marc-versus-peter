#include <iostream>
#include "GameLogic/Game.h"
#include "Factories/FactorySDL.h"

int main( int argc, char **argv ) {

    gameLogic::AbstractFactory* factory = new SDL::FactorySDL;
    gameLogic::Game* game = new gameLogic::Game(factory);
    game->run();

    delete factory;
    delete game;
    return 0;
}
