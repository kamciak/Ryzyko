#include "Player.h"
void Player::setName(const std::string name){
    _name = name;
}

void Player::setColor(const wxColour color){
    _color = color;
}

Player::Player(std::string name, wxColour color){
    _name = name;
    _color = color;
    _used=false;
}
