#ifndef STEFSPACE_ENEMY_H
#define STEFSPACE_ENEMY_H

#include "EntityAbstract.h"

namespace gameLogic{
    class Enemy : public EntityAbstract {
        int scoreWorth;
        int rateOfFire;
        bool currentDirection = true; //1 is right, 0 is left
        bool isShooting = false;
        int shootCounter = 0;
        int health = 3;

    public:

        Enemy(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound, int yBound,
              bool isExisting, int scoreWorth, int rateOfFire);
        void update() override;

        int getHealth();
        void setHealth(int health);
        bool getIsShooting();
        void setIsShooting(bool isShooting);
        int getScoreWorth();
        int getRateOfFire();
        void setScoreWorth(int scoreWorth);
        void setRateOfFire(int rateOfFire);
        bool getDirection();
        void setDirection(bool direction);
    };

}
#endif //STEFSPACE_ENEMY_H
