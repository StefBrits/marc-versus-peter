//
// Created by koro-sensei on 25/06/2020.
//

#ifndef STEFSPACE_SOUNDHANDLERSDL_H
#define STEFSPACE_SOUNDHANDLERSDL_H

#include <vector>
#include "AbstractSoundHandler.h"
#include "SDL2/SDL_mixer.h"

namespace SDL {
    class SoundHandlerSDL : public gameLogic::AbstractSoundHandler {
    private:
        Mix_Music* background = nullptr;
        Mix_Music* story = nullptr;
        Mix_Music* loser = nullptr;
        Mix_Music* winner = nullptr;
        Mix_Chunk* shot = nullptr;
        Mix_Chunk* bluh = nullptr;
        Mix_Chunk* bonus = nullptr;

    public:
        void init() override;

        void playMusic(int songNumber) override;

        void playerShot() override;

        void loadSounds(const char* backgroundPath, const char* playerShotPath, const char* storyPath,const char* victoryPath, const char* loserPath,const char* markBluh, const char* bonusPath) override;

        void marcSound() override ;

        void bonusSound() override ;
    };
}



#endif //STEFSPACE_SOUNDHANDLERSDL_H
