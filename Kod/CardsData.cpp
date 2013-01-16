#include "CardsData.h"

RiskCard CardsData::_cards[] = {
    RiskCard('i', Board::instance().region(0).name()),
    RiskCard('c', Board::instance().region(1).name()),
    RiskCard('a', Board::instance().region(2).name()),
    
    RiskCard('i', Board::instance().region(3).name()),
    RiskCard('c', Board::instance().region(4).name()),
    RiskCard('a', Board::instance().region(5).name()),

    RiskCard('i', Board::instance().region(6).name()),
    RiskCard('c', Board::instance().region(7).name()),
    RiskCard('a', Board::instance().region(8).name()),
   
    RiskCard('i', Board::instance().region(9).name()),
    RiskCard('c', Board::instance().region(10).name()),
    RiskCard('a', Board::instance().region(11).name()),

    RiskCard('i', Board::instance().region(12).name()),
    RiskCard('c', Board::instance().region(13).name()),
    RiskCard('a', Board::instance().region(14).name()),
    
    RiskCard('i', Board::instance().region(15).name()),
    RiskCard('c', Board::instance().region(16).name()),
    RiskCard('a', Board::instance().region(17).name()),

    RiskCard('i', Board::instance().region(18).name()),
    RiskCard('c', Board::instance().region(19).name()),
    RiskCard('a', Board::instance().region(20).name()),

    RiskCard('i', Board::instance().region(21).name()),
    RiskCard('c', Board::instance().region(22).name()),
    RiskCard('a', Board::instance().region(23).name()),

    RiskCard('i', Board::instance().region(24).name()),
    RiskCard('c', Board::instance().region(25).name()),
    RiskCard('a', Board::instance().region(26).name()),

    RiskCard('i', Board::instance().region(27).name()),
    RiskCard('c', Board::instance().region(28).name()),
    RiskCard('a', Board::instance().region(29).name()),

    RiskCard('i', Board::instance().region(30).name()),
    RiskCard('c', Board::instance().region(31).name()),
    RiskCard('a', Board::instance().region(32).name()),

    RiskCard('i', Board::instance().region(33).name()),
    RiskCard('c', Board::instance().region(34).name()),
    RiskCard('a', Board::instance().region(35).name()),
    
    RiskCard('i', Board::instance().region(36).name()),
    RiskCard('c', Board::instance().region(37).name()),
    RiskCard('a', Board::instance().region(38).name()),

    RiskCard('i', Board::instance().region(39).name()),
    RiskCard('c', Board::instance().region(40).name()),
    RiskCard('a', Board::instance().region(41).name())
};

CardsData::CardsData() : _deck(_cards, DECK_SIZE){}

CardsData & CardsData::instance(){
    static CardsData cd;
    return cd;
}

RiskDeck & CardsData::deck(){
    return _deck;
}

wxBitmap * CardsData::infantryBitmap(){
    if(!_infantry_image)
        _infantry_image = new wxBitmap(*new wxImage("Images/warriors.jpg"));
    return _infantry_image;   
}

wxBitmap * CardsData::cavalryBitmap(){
    if(!_cavalry_image)
        _cavalry_image = new wxBitmap(*new wxImage("Images/cavalrys.jpg"));
    return _cavalry_image;
}

wxBitmap * CardsData::artilleryBitmap(){
    if(!_artillery_image)
        _artillery_image = new wxBitmap(*new wxImage("Images/cannons.jpg"));
    return _artillery_image;
}
