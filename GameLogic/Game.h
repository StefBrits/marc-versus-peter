#ifndef STEFSPACE_GAME_H
#define STEFSPACE_GAME_H

#include <vector>
#include "../Factories/AbstractFactory.h"
#include "../Music/AbstractSoundHandler.h"

namespace gameLogic {
    class Game {
        std::vector<Enemy* > enemies;
        std::vector<Bullet* > bullets;
        std::vector<Bonus* > bonus;
        std::vector<Player* > players;
        std::vector<EntityAbstract* > entities;
        std::vector<GameOver*> gameOvers;
        int counter;
        int score;
        int sceneDuur=200;
        int isWinning = 1;
        bool isGameOver = 0;
        bool isGameRunning = 1;
        int i =0;
        const int xBound = 1000, yBound = 800;
        uint32_t frameStart, frameStop;
        const int frameDelay = 1000 / 60; //60 FPS
        AbstractFactory* factory;
        AbstractController* controller;
        AbstractHandler* handler;
        AbstractSoundHandler* soundHandler;
        int marcsPerRow=2;
        bool firstRun=true;
        int songStory = 1;
        int songGame = 2;
        int songWinner = 3;
        int songLoser = 4;

    public:
        void initialize();
        void restart();
        void makePeter(bool isCool);
        void makeMarc(int x, int y);
        void makeBonus(int x, int y);
        void run();
        void hiveMindMarc();
        void oneManKillingMachinePeter();
        void collisionDetection();
        void jackTheRipper();
        void victoryCheck();
        void makeGameOver();
        void clearScreen();
        Game(gameLogic::AbstractFactory* abstractFactory);
    };

}
#endif //STEFSPACE_GAME_H
