#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <wx/colour.h>

class Player{
friend class Controller;
private:
    std::string _name;
    wxColour _color;
    bool _used;

    void setName(const std::string name);
    std::string name(){return _name;}

    void setColor(const wxColour color);
    wxColor color(){return _color;}

    void toggleUsed(){_used = !_used;}
    bool used(){return _used;}

    Player(std::string name, wxColour color);
};


#endif
