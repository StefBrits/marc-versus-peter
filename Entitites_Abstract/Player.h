#ifndef STEFSPACE_PLAYER_H
#define STEFSPACE_PLAYER_H

#include "EntityAbstract.h"
#include "../Controllers/AbstractController.h"

namespace gameLogic {
    class Player : public EntityAbstract {
        AbstractController* controller;
        bool isShooting = false;
        bool isCool;
    public:
        Player(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound, int yBound,
               bool isExisting,
               gameLogic::AbstractController *pController, bool isCool);
        void update() override;

        bool getIsShooting();
        void setIsShooting(bool isShooting);
        bool getIsCool();
    };

}
#endif //STEFSPACE_PLAYER_H
