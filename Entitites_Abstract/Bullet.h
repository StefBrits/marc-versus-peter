//
// Created by koro-sensei on 11/05/2020.
//

#ifndef STEFSPACE_BULLET_H
#define STEFSPACE_BULLET_H

#include "EntityAbstract.h"

namespace gameLogic {
    class Bullet : public EntityAbstract {

        bool isFriendly;
    public:
        Bullet(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound, int yBound,
               bool isExisting,
               bool isFriendly);

        bool getIsFriendly();
        void setIsFriendly(bool isFriendly);
        void update() override;


    };

}
#endif //STEFSPACE_BULLET_H
