#include "Enemy.h"

//Constructor
gameLogic::Enemy::Enemy(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound, int yBound,
                        bool isExisting, int scoreWorth, int rateOfFire) : EntityAbstract(xCoordinate, yCoordinate, speed, width, height, xBound, yBound, isExisting) {
    this->scoreWorth = scoreWorth;
    this->rateOfFire = rateOfFire;

}

//Getters and setters
int gameLogic::Enemy::getScoreWorth() {
    return scoreWorth;
}

int gameLogic::Enemy::getRateOfFire() {
    return rateOfFire;
}

void gameLogic::Enemy::setScoreWorth(int scoreWorth) {
    this->scoreWorth = scoreWorth;
}

void gameLogic::Enemy::setRateOfFire(int rateOfFire) {
    this->rateOfFire = rateOfFire;
}

bool gameLogic::Enemy::getDirection() {
    return currentDirection;
}

void gameLogic::Enemy::setDirection(bool direction) {
    currentDirection = direction;
}

bool gameLogic::Enemy::getIsShooting() {
    return isShooting;
}

void gameLogic::Enemy::setIsShooting(bool isShooting) {
    this->isShooting = isShooting;
}

int gameLogic::Enemy::getHealth() {
    return health;
}

void gameLogic::Enemy::setHealth(int health) {
    Enemy::health = health;
}


//Update function that gets called every frame tick
void gameLogic::Enemy::update() {
    if (currentDirection) {
        setxCoordinate(getxCoordinate()+1*getSpeed());
    } else {
        setxCoordinate(getxCoordinate()-1*getSpeed());
    }
    if(getIsShooting() && getIsExisting()) {
        shootCounter++;
        if(shootCounter>=30){
            setIsShooting(false);
            shootCounter= 0;
        }
    }
}





