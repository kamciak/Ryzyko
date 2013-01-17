#include "SoundController.h"

SoundController::SoundController(){
    _sounds.insert(std::make_pair(START_GAME,new wxSound("Sounds/Placeholder.wav")));
    _sounds.insert(std::make_pair(REGION_CONQUERED,new wxSound("Sounds/Placeholder.wav")));
    _sounds.insert(std::make_pair(ARMY_MARCH,new wxSound("Sounds/Placeholder.wav")));
}

void SoundController::playSound(Sound name){
    static SoundController sc;
    sc._sounds[name]->Play();
}   
