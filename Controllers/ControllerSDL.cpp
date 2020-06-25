#include "ControllerSDL.h"


//Getters and setters
void SDL::ControllerSDL::pressLeft(bool isPressed) {
    isLeft = isPressed;
}

void SDL::ControllerSDL::pressRight(bool isPressed) {
    isRight = isPressed;
}

void SDL::ControllerSDL::pressUp(bool isPressed) {
    isUp = isPressed;
}

void SDL::ControllerSDL::pressDown(bool isPressed) {
    isDown = isPressed;
}

void SDL::ControllerSDL::pressShoot(bool isPressed) {
    isShoot = isPressed;
}

bool SDL::ControllerSDL::getLeft() {
    return isLeft;
}

bool SDL::ControllerSDL::getRight() {
    return isRight;
}

bool SDL::ControllerSDL::getUp() {
    return isUp;
}

bool SDL::ControllerSDL::getDown() {
    return isDown;
}

bool SDL::ControllerSDL::getShoot() {
    return isShoot;
}
