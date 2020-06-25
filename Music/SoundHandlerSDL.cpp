//
// Created by koro-sensei on 25/06/2020.
//


#include <iostream>
#include "SoundHandlerSDL.h"


void SDL::SoundHandlerSDL::playMusic(int songNumber) {
    //play the music on repeat
    switch (songNumber) {
        case 1 :
            Mix_PlayMusic(story, -1);
            break;
        case 2 :
            Mix_PlayMusic(background, -1);
            break;
        case 3 :
            Mix_PlayMusic(winner, -1);
            break;
        case 4 :
            Mix_PlayMusic(loser, 0);
            break;
    }
}

void SDL::SoundHandlerSDL::playerShot() {
    //play the shot sound once
    Mix_PlayChannel(-1, shot, 0);
}

void SDL::SoundHandlerSDL::init() {

    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {
        std::cout<<"Mix_GetError"<<std::endl;
    }

    //set the volume to half
    Mix_VolumeMusic(100);
}

void SDL::SoundHandlerSDL::loadSounds(const char* backgroundPath, const char* playerShotPath, const char* storyPath,const char* victoryPath, const char* loserPath,const char* markBluh, const char* bonusPath) {
    //load the 2 sounds
    background = Mix_LoadMUS(backgroundPath);
    story = Mix_LoadMUS(storyPath);
    winner = Mix_LoadMUS(victoryPath);
    loser = Mix_LoadMUS(loserPath);
    shot = Mix_LoadWAV(playerShotPath);
    bluh = Mix_LoadWAV(markBluh);
    bonus = Mix_LoadWAV(bonusPath);
}

void SDL::SoundHandlerSDL::marcSound() {
    Mix_PlayChannel(-1, bluh, 0);
}

void SDL::SoundHandlerSDL::bonusSound() {
    Mix_PlayChannel(-1, bonus, 0);
}



