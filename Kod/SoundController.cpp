#include "SoundController.h"

SoundController::SoundController(){
    _sounds.insert(std::make_pair(START_GAME,new wxSound("Sounds/Placeholder.wav")));
    _sounds.insert(std::make_pair(REGION_CONQUERED,new wxSound("Sounds/new_region.wav")));
    _sounds.insert(std::make_pair(ARMY_MARCH,new wxSound("Sounds/march.wav")));
    _sounds.insert(std::make_pair(END_GAME,new wxSound("Sounds/end.wav")));
}

void SoundController::playSound(Sound name){
    static SoundController sc;
    sc._sounds[name]->Play();
}   
