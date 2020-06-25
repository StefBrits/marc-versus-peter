//
// Created by koro-sensei on 13/06/2020.
//

#include "GameOver.h"

gameLogic::GameOver::GameOver(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound,
                              int yBound, bool isExisting, int isWin) : EntityAbstract(xCoordinate, yCoordinate, speed, width, height, xBound, yBound, isExisting) {
    this->isWin = isWin;
}



void gameLogic::GameOver::update() {

}

int gameLogic::GameOver::getIsWin() {
    return isWin;
}
