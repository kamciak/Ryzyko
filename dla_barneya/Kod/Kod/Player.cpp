#include "Player.h"


Player::Player(wxString player_name, PlayerColor player_color){
    _color = player_color;
    _name = player_name;
    _dead = false;
    wxImage::AddHandler( new wxPNGHandler );
    
    switch(player_color){
        case RED:
            _soldier_image = wxImage("Images/redguys.png");
            _soldier_image_big = wxImage("Images/redguyb.png");
            break;
        case BLUE:
            _soldier_image = wxImage("Images/blueguys.png");
            _soldier_image_big = wxImage("Images/blueguyb.png");
            break;
        case GREEN:
            _soldier_image = wxImage("Images/greenguys.png");
            _soldier_image_big = wxImage("Images/greenguyb.png");
            break;
        case YELLOW:
            _soldier_image = wxImage("Images/yellowguys.png");
            _soldier_image_big = wxImage("Images/yellowguyb.png");
            break;
        case PURPLE:
            _soldier_image = wxImage("Images/purpleguys.png");
            _soldier_image_big = wxImage("Images/purpleguyb.png");
            break;
        case GRAY:
            _soldier_image = wxImage("Images/greyguys.png");
            _soldier_image_big = wxImage("Images/greyguyb.png");
            break;
        case MAGENTA:
            _soldier_image = wxImage("Images/magentaguys.png");
            _soldier_image_big = wxImage("Images/magentaguyb.png");
            break;
        case CYAN:
            _soldier_image = wxImage("Images/cyanguys.png");
            _soldier_image_big = wxImage("Images/cyanguyb.png");
            break;
        case ORANGE:
            _soldier_image = wxImage("Images/orangeguys.png");
            _soldier_image_big = wxImage("Images/orangeguyb.png");
            break;
        case DARKBLUE:
            _soldier_image = wxImage("Images/darkblueguys.png");
            _soldier_image_big = wxImage("Images/darkblueguyb.png");
            break;    
    }
}

wxString Player::name(){
    return _name;
}

bool Player::isDead(){
    return _dead;
}

void Player::kill(){
    _dead = true;
}

PlayerColor Player::color(){
    return _color;
}

wxImage & Player::image(bool big){
    if(big)
        return _soldier_image_big;
    else
        return _soldier_image;
}
