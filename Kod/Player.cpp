#include "Player.h"


Player::Player(wxString player_name, PlayerColor player_color){
    _name = player_name;
    wxImage::AddHandler( new wxPNGHandler );
    switch(player_color){
        case RED:
            _soldier_image = wxImage("Images/redguy.png");
            break;
        case BLUE:
            _soldier_image = wxImage("Images/blueguy.png");
            break;
        case GREEN:
            _soldier_image = wxImage("Images/greenguy.png");
            break;
        case YELLOW:
            _soldier_image = wxImage("Images/yellowguy.png");
            break;
        case PURPLE:
            _soldier_image = wxImage("Images/purpleguy.png");
            break;
        case GRAY:
            _soldier_image = wxImage("Images/greyguy.png");
            break;
        case MAGENTA:
            _soldier_image = wxImage("Images/magentaguy.png");
            break;
        case CYAN:
            _soldier_image = wxImage("Images/cyanguy.png");
            break;
        case ORANGE:
            _soldier_image = wxImage("Images/orangeguy.png");
            break;
        case DARKBLUE:
            _soldier_image = wxImage("Images/darkblueguy.png");
            break;    
    }
}

wxString Player::name(){
    return _name;
}


wxImage & Player::image(){
    return _soldier_image;
}
