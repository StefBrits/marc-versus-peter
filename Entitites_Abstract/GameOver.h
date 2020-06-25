//
// Created by koro-sensei on 13/06/2020.
//

#ifndef STEFSPACE_GAMEOVER_H
#define STEFSPACE_GAMEOVER_H

#include "EntityAbstract.h"

namespace gameLogic {
    class GameOver : public EntityAbstract{

        int isWin;
    public:
        GameOver(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound,
                 int yBound, bool isExisting, int isWin);
        void update() override;
        int getIsWin();
    };

}
#endif //STEFSPACE_GAMEOVER_H
