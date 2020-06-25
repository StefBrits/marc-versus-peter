#ifndef STEFSPACE_ABSTRACTCONTROLLER_H
#define STEFSPACE_ABSTRACTCONTROLLER_H

namespace gameLogic {
    class AbstractController {

    public:
        virtual bool getLeft() = 0;
        virtual bool getRight() = 0;
        virtual bool getUp() = 0;
        virtual bool getDown() = 0;
        virtual bool getShoot() = 0;


        virtual void pressLeft(bool isPressed) = 0;
        virtual void pressRight(bool isPressed) = 0;
        virtual void pressUp(bool isPressed) = 0;
        virtual void pressDown(bool isPressed) = 0;
        virtual void pressShoot(bool isPressed) = 0;
        bool isLeft,isRight,isDown,isUp,isShoot;
    };
}
#endif //STEFSPACE_ABSTRACTCONTROLLER_H
