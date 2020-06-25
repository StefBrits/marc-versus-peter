#include "Bullet.h"

//Constructor
gameLogic::Bullet::Bullet(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound,
                          int yBound, bool isExisting, bool isFriendly) : EntityAbstract(xCoordinate, yCoordinate, speed, width, height, xBound, yBound, isExisting) {
    this->isFriendly = isFriendly;
}


//Getters and setters
bool gameLogic::Bullet::getIsFriendly() {
    return isFriendly;
}

void gameLogic::Bullet::setIsFriendly(bool isFriendly) {
    this->isFriendly = isFriendly;
}

//Update function that gets called every frame tick
void gameLogic::Bullet::update() {
    if(getyCoordinate()<=0 || getyCoordinate()>=getyBound()) {
        deleteEntity();
    }
    if(isFriendly){
        setyCoordinate(getyCoordinate()-1*getSpeed());
    } else {
        setyCoordinate(getyCoordinate()+1*getSpeed());
    }
}