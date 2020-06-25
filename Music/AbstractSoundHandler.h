//
// Created by koro-sensei on 25/06/2020.
//

#ifndef STEFSPACE_ABSTRACTSOUNDHANDLER_H
#define STEFSPACE_ABSTRACTSOUNDHANDLER_H

namespace gameLogic {
    class AbstractSoundHandler {

    public:
        virtual void init() = 0;

        virtual void playMusic(int songNumber) = 0;

        virtual void playerShot() = 0;

        virtual void loadSounds(const char* backgroundPath, const char* playerShotPath, const char* storyPath,const char* victoryPath, const char* loserPath, const char* markBluh, const char* bonusPath) = 0;

        virtual void marcSound() = 0;

        virtual void bonusSound() = 0;
    };
}


#endif //STEFSPACE_ABSTRACTSOUNDHANDLER_H
