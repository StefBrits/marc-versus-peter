#include <iostream>
#include "Player.h"
#include "../Controllers/AbstractController.h"

//Constructor
gameLogic::Player::Player(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound, int yBound,
                          bool isExisting,
                          gameLogic::AbstractController* pController, bool isCool) : EntityAbstract(xCoordinate, yCoordinate, speed, width, height, xBound, yBound, isExisting) {
    controller = pController;
    this->isCool = isCool;
}

//Update function that gets called every frame tick
void gameLogic::Player::update() {
    if(controller->getLeft() && getxCoordinate()>=0) {
        // Go to the left
        setxCoordinate(getxCoordinate()-(1*getSpeed()));

    }
    if(controller->getRight() && getxCoordinate()+getWidth()<=getxBound()) {
        // Go to the right
        setxCoordinate(getxCoordinate()+(1*getSpeed()));

    }

}

bool gameLogic::Player::getIsShooting() {
    return isShooting;
}

void gameLogic::Player::setIsShooting(bool isShooting) {
    Player::isShooting = isShooting;
}

bool gameLogic::Player::getIsCool() {
    return isCool;
}


