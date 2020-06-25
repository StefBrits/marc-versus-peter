#include <iostream>
#include <regex>
#include <chrono>
#include <zconf.h>
#include <dshow.h>
#include "Game.h"
#include "../Factories/FactorySDL.h"

//Constructor
gameLogic::Game::Game(gameLogic::AbstractFactory* abstractFactory) {
    factory = abstractFactory;
}

//Game loop that calls
void gameLogic::Game::run() {
    initialize();
    //PlaySound("..//files//matrix.wav",NULL,SND_FILENAME | SND_ASYNC);
    soundHandler->playMusic(songStory);
    while(isGameRunning) {
        //To make sure the framerate is always 60 Hz
        frameStart = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count();
        //! game logic start
        handler->clear();           //clear the screen that was rendered on the last frame
        handler->handleEvents();    //call event handler for input from keyboard
        for(EntityAbstract* e : entities) {
            e->draw();
            e->update();
        }
        if(firstRun) {

            isWinning = 2;
            if(i==0) {
                makeGameOver();
            }
            if(i==sceneDuur+1) {
                isWinning = 3;
                makeGameOver();
            }
            if(i==(sceneDuur*2)+1) {
                isWinning = 4;
                makeGameOver();
            }
            if(i==sceneDuur) {
                gameOvers.at(0)->setIsExisting(false);
            }
            if(i==sceneDuur*2) {
                gameOvers.at(0)->setIsExisting(false);
            }
            if(i==sceneDuur*3) {
                i=0;
                firstRun=false;
                gameOvers.at(0)->setIsExisting(false);
                //PlaySound("..//files//deepMindedSong.wav",NULL,SND_FILENAME | SND_ASYNC);
                soundHandler->playMusic(songGame);
                isWinning = 1;
            }
            i++;
        }

        if(!firstRun) {

            oneManKillingMachinePeter(); //Control for player
            collisionDetection(); //Detects collisions with bullets/bonus/players/enemies
            if(!isGameOver) {
                victoryCheck(); //check if the game is over
            }
            std::cout<<"Score :"<<score<<std::endl;
            if(isGameOver) {

                for(Bonus* e : bonus) {
                    e->setIsExisting(0);
                }
                if(i==1 && isWinning==1) {
                    //PlaySound("..//files//winner.wav",NULL,SND_FILENAME | SND_ASYNC);
                    soundHandler->playMusic(songWinner);
                    makePeter(1);
                }
                if(i==1 && isWinning==0) {
                    //PlaySound("..//files//loser.wav",NULL,SND_FILENAME | SND_ASYNC);
                    soundHandler->playMusic(songLoser);
                }
                if((i==1600 && isWinning==1) || (i==300 && isWinning==0)){
                    //wait for the endscreen and then restart
                    restart();
                    i=0;
                }
                i++;

            }
        }
        hiveMindMarc(); //Limited AI for the enemies
        handler->render();          //update the screen
        jackTheRipper(); //kills off entities who died
        //! game logic end
        frameStop = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count() - frameStart;
        if (frameDelay > frameStop) {
            usleep((frameDelay - frameStop) * 1000);
        }



    }
}

void gameLogic::Game::initialize() {
    isWinning = 1;
    if(marcsPerRow <= 5) {
        marcsPerRow++;
    }
    score = 0;
    counter = 0;
    controller = factory->createController();
    handler = factory->createHandler(controller);
    soundHandler = factory->createSoundHandler();
    soundHandler->init();
    soundHandler->loadSounds("..//files//deepMindedSong.wav","..//files//piew.wav","..//files//matrix.wav","..//files//winner.wav","..//files//loser.wav","..//files//bluh.wav", "..//files//bonus.wav");
    handler->initialize("Awesome Space Invader Version 1.0", xBound, yBound);
    makePeter(0);    //make player - the unstoppable force - 'Peter' HELLincxkxc
    for(int numberOfMarc=0;numberOfMarc<marcsPerRow;numberOfMarc++) { //make some Marc - immovable object - keulemans
        makeMarc((numberOfMarc*170)+5,0);
        makeMarc((numberOfMarc*170)+82,170);
    }
}

void gameLogic::Game::makePeter(bool isCool) {
    gameLogic::Player* peter = factory->createPlayer(xBound,yBound,controller,handler,isCool);
    entities.emplace_back(peter);
    players.emplace_back(peter);
}

void gameLogic::Game::makeMarc(int x, int y) {
    gameLogic::Enemy* marc = factory->createEnemy(x,y,xBound,yBound,handler);
    std::cout<<"amount of Marc: "<<entities.size()<<std::endl;
    entities.emplace_back(marc);
    enemies.emplace_back(marc);
}

void gameLogic::Game::makeBonus(int x, int y) {
    gameLogic::Bonus* bonusje = factory->createBonus(x,y,xBound,yBound,handler);
    entities.emplace_back(bonusje);
    bonus.emplace_back(bonusje);
}

void gameLogic::Game::makeGameOver() {
    gameLogic::GameOver* gameOver = factory->createGameOver(xBound,yBound,handler,isWinning);
    entities.emplace_back(gameOver);
    gameOvers.emplace_back(gameOver);
}

void gameLogic::Game::hiveMindMarc() {
    for(Enemy* e : enemies) {
        //bouncing
        if(e->getxCoordinate() < 0 || e->getxCoordinate()+e->getWidth() > xBound) {
            for(Enemy* enemy : enemies) {
                enemy->setDirection(!enemy->getDirection());
                enemy->setyCoordinate(enemy->getyCoordinate()+(enemy->getHeight()/10));
            }

        }

        //shooting
        int shoot = rand() % 350;
        if (shoot == 23 && e->getIsExisting() && isWinning==1) {
            Bullet *bullet = factory->createBullet(e->getxCoordinate() + (e->getWidth() / 2),
                                                   e->getyCoordinate() + e->getHeight(), xBound, yBound, false,
                                                   handler);
            entities.emplace_back(bullet);
            bullets.emplace_back(bullet);
            e->setIsShooting(true);
            soundHandler->marcSound();
        }
    }
}

void gameLogic::Game::oneManKillingMachinePeter() {
    if(!players.empty()) {
        if(controller->getShoot() && counter == 0) {
            for(Player* player : players) {
                player->setIsShooting(true);
            }
            Bullet* bullet = factory->createBullet(players.at(0)->getxCoordinate()+(players.at(0)->getWidth()/2),players.at(0)->getyCoordinate(),xBound,yBound,true,handler);
            entities.emplace_back(bullet);
            bullets.emplace_back(bullet);
            soundHandler->playerShot();
            counter = 30;
        }
        if(counter > 0) {
            counter--;
        }
        if(counter == 15) {
            for(Player* player : players) {
                player->setIsShooting(false);
            }
        }
    }

}

void gameLogic::Game::collisionDetection() {
    for(Bullet* a : bullets) {  //player gets killed
        for(Player* b : players) {
                if(!a->getIsFriendly() &&
                b->getxCoordinate() + b->getWidth() >= a->getxCoordinate() &&
                a->getxCoordinate() + a->getWidth() >= b->getxCoordinate() &&
                b->getyCoordinate() + b->getHeight() >= a->getyCoordinate() &&
                a->getyCoordinate() + a->getHeight() >= b->getyCoordinate()) {
                    b->deleteEntity();
                    a->deleteEntity();
                }

        }
    }
    for(Bullet* a : bullets) { // enemy gets killed
        for(Enemy* b : enemies) {
            if(a->getIsFriendly() &&
               b->getxCoordinate() + b->getWidth() >= a->getxCoordinate() &&
               a->getxCoordinate() + a->getWidth() >= b->getxCoordinate() &&
               b->getyCoordinate() + b->getHeight() >= a->getyCoordinate() &&
               a->getyCoordinate() + a->getHeight() >= b->getyCoordinate()) {

                b->setHealth(b->getHealth()-1);
                if(b->getHealth()==0) {
                    b->deleteEntity();
                }
                a->deleteEntity();
                score += b->getScoreWorth();
            }
        }
    }
    for(Bonus* a : bonus) { //player takes bonus
        for(Player* b : players) {
            if(
               b->getxCoordinate() + b->getWidth() >= a->getxCoordinate() &&
               a->getxCoordinate() + a->getWidth() >= b->getxCoordinate() &&
               b->getyCoordinate() + b->getHeight() >= a->getyCoordinate() &&
               a->getyCoordinate() + a->getHeight() >= b->getyCoordinate()) {
                //b->deleteEntity();
                a->deleteEntity();
                score += a->getScoreWorth();
                soundHandler->bonusSound();
            }
        }
    }

    for(Enemy* e : enemies) { //lose when enemies reach the end of the level
        if(e->getyCoordinate()+e->getHeight() > yBound) {
            for(Player* p : players) {
                p->deleteEntity();
            }
        }
    }
}

void gameLogic::Game::jackTheRipper() {
    // loop each vector with the entities and erase the ones with 'isExisting' == false
    int index = 0;
    for (EntityAbstract *ea : entities) {
        if (!ea->getIsExisting() && index < entities.size()) {
            entities.erase(entities.begin() + index);
            //std::cout<<"amount of entities: "<<entities.size()<<std::endl;
        }
        index++;
    }
    index = 0;
    for (Player *p : players) {
        if (!p->getIsExisting() && index < players.size()) {
            players.erase(players.begin() + index);
        }
        index++;
    }
    index = 0;
    for (Bonus *b : bonus) {
        if (!b->getIsExisting() && index < bonus.size()) {
            bonus.erase(bonus.begin() + index);
        }
        index++;
    }
    index = 0;
    for (Bullet *bull : bullets) {
        if (!bull->getIsExisting() && index < bullets.size()) {
            bullets.erase(bullets.begin() + index);
        }
        index++;
    }
    index = 0;
    for (Enemy *e : enemies) {
        if (!e->getIsExisting() && index < enemies.size()) {
            enemies.erase(enemies.begin() + index);

            // Chance to drop a bonus if an enemy gets killed
            if (2 == rand() % 5) {
                makeBonus(e->getxCoordinate() + index * 5, e->getyCoordinate() + index * 5);
            }
        }
        index++;
    }
    index = 0;
    for (GameOver *e : gameOvers) {
        if (!e->getIsExisting() && index < gameOvers.size()) {
            gameOvers.erase(gameOvers.begin() + index);
        }
        index++;
        if (isGameOver) {
            for (Enemy *e : enemies) {
                enemies.empty();
            }
        }
    }
}

void gameLogic::Game::victoryCheck() {

    if(enemies.size()==0) {
        isWinning = 1;
        isGameOver = 1;
        clearScreen();
        makeGameOver();

    }
    else if(players.size()==0) {
        isWinning = 0;
        isGameOver = 1;
        clearScreen();
        makeGameOver();
    }

}

void gameLogic::Game::clearScreen() {
    for(Bullet* e : bullets) {
        e->setIsExisting(0);
    }
    for(Bonus* e : bonus) {
        e->setIsExisting(0);
    }
    for(Enemy* e : enemies) {
        e->setIsExisting(0);
    }
    for(Player* e : players) {
        e->setIsExisting(0);
    }
}

void gameLogic::Game::restart() {
    //PlaySound("..//files//deepMindedSong.wav",NULL,SND_FILENAME | SND_ASYNC);
    soundHandler->playMusic(songGame);
    clearScreen();
    handler->setIsOnce(1);
    gameOvers.clear();
    entities.clear();
    int desiredMarcsPerRow = 5;
    score = 0;
    counter = 0;
    makePeter(0);    //make player - the unstoppable force - 'Peter' HELLincxkxc

    for(int numberOfMarc=0;numberOfMarc<desiredMarcsPerRow;numberOfMarc++) { //make some Marc - immovable object - keulemans
        makeMarc((numberOfMarc*170)+5,0);
        makeMarc((numberOfMarc*170)+82,170);
    }
    isWinning = 1;
    isGameOver = false;
}










