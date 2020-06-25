#ifndef STEFSPACE_CONTROLLERSDL_H
#define STEFSPACE_CONTROLLERSDL_H

#include "AbstractController.h"

namespace SDL {
    class ControllerSDL : public gameLogic::AbstractController{

        bool isRight,isUp,isLeft,isDown,isShoot;
    public:
        void pressLeft(bool isPressed) override;
        void pressRight(bool isPressed) override;
        void pressUp(bool isPressed) override;
        void pressDown(bool isPressed) override;
        void pressShoot(bool isPressed) override;

        bool getLeft() override;
        bool getRight() override;
        bool getUp() override;
        bool getDown() override;
        bool getShoot() override;
    };

}
#endif //STEFSPACE_CONTROLLERSDL_H
