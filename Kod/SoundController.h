#ifndef SOUNDCONTROLLER_H
#define SOUNDCONTROLLER_H

#include <map>
#include <wx/sound.h>

enum Sound{
    START_GAME,
    REGION_CONQUERED,
    ARMY_MARCH,
    END_GAME 
};

class SoundController{
private:
    SoundController();
    SoundController(const SoundController & sc);
    SoundController & operator=(const SoundController & sc);

    std::map<Sound,wxSound*> _sounds;
public:
    static void playSound(Sound name);
};  


#endif

