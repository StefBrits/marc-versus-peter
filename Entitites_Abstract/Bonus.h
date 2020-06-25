
#ifndef STEFSPACE_BONUS_H
#define STEFSPACE_BONUS_H

#include "EntityAbstract.h"

namespace gameLogic {
    class Bonus : public EntityAbstract {
        int scoreWorth{};
    public:
        Bonus(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound, int yBound,
              bool isExisting, int scoreWorth);
        void update() override;

        int getScoreWorth();
        void setScoreWorth(int scoreWorth);
    };
}

#endif //STEFSPACE_BONUS_H
