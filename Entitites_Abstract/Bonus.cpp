#include "Bonus.h"

//Constructor
gameLogic::Bonus::Bonus(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound, int yBound,
                        bool isExisting, int scoreWorth) : EntityAbstract(xCoordinate, yCoordinate, speed, width, height, xBound, yBound, isExisting) {
    this->scoreWorth = scoreWorth;
}


//Getters and setters
int gameLogic::Bonus::getScoreWorth() {
    return scoreWorth;
}

void gameLogic::Bonus::setScoreWorth(int scoreWorth) {
    this->scoreWorth = scoreWorth;
}

//Update function that gets called every frame tick
void gameLogic::Bonus::update() {
    if(getyCoordinate()<=0 || getyCoordinate()>=getyBound()) {
        deleteEntity();
    }
    setyCoordinate(getyCoordinate()+1*getSpeed());
}
