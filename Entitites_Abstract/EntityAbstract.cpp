#include "EntityAbstract.h"

//constructor
gameLogic::EntityAbstract::EntityAbstract(int xCoordinate, int yCoordinate, int speed, int width, int height,
                                          int xBound, int yBound, bool isExisting) {
    this->xCoordinate = xCoordinate;
    this->yCoordinate = yCoordinate;
    this->speed = speed;
    this->width = width;
    this->height = height;
    this->xBound = xBound;
    this->yBound = yBound;
    this->isExisting = isExisting;
}


//Getters and setters
int gameLogic::EntityAbstract::getxCoordinate() {
    return xCoordinate;
}

int gameLogic::EntityAbstract::getyCoordinate() {
    return yCoordinate;
}
int gameLogic::EntityAbstract::getSpeed() {
    return speed;
}
int gameLogic::EntityAbstract::getWidth() {
    return width;
}
int gameLogic::EntityAbstract::getHeight() {
    return height;
}
int gameLogic::EntityAbstract::getxBound() {
    return xBound;
}
int gameLogic::EntityAbstract::getyBound() {
    return yBound;
}
bool gameLogic::EntityAbstract::getIsExisting() {
    return isExisting;
}

void gameLogic::EntityAbstract::setxCoordinate(int xCoordinate) {
    this->xCoordinate = xCoordinate;
}
void gameLogic::EntityAbstract::setyCoordinate(int yCoordinate) {
    this->yCoordinate = yCoordinate;
}
void gameLogic::EntityAbstract::setSpeed(int speed) {
    this->speed = speed;
}
void gameLogic::EntityAbstract::setWidth(int width) {
    this->width = width;
}
void gameLogic::EntityAbstract::setHeight(int height) {
    this->height = height;
}
void gameLogic::EntityAbstract::setxBound(int xBound) {
    this->xBound = xBound;
}
void gameLogic::EntityAbstract::setyBound(int yBound) {
    this->yBound = yBound;
}
void gameLogic::EntityAbstract::setIsExisting(bool isExisting) {
    this->isExisting = isExisting;
}


//delete entity object
void gameLogic::EntityAbstract::deleteEntity() {
    isExisting = false;
}




