#ifndef CARDSDATA_H
#define CARDSDATA_H

#include <wx/wx.h>

#include "RiskDeck.h"
#include "Board.h"

#define DECK_SIZE 42

///klasa-singleton/wrapper przechowuj¹ca dane o kartach i taliê kart ryzyka
class CardsData{
private:
    CardsData();
    CardsData(const CardsData & cd);
    CardsData & operator=(const CardsData & cd);
    RiskDeck _deck;
    static RiskCard _cards[DECK_SIZE];
    wxBitmap * _infantry_image;
    wxBitmap * _cavalry_image;
    wxBitmap * _artillery_image;  
public:
    static CardsData & instance();
    RiskDeck & deck(); 
    wxBitmap * infantryBitmap();
    wxBitmap * cavalryBitmap();
    wxBitmap * artilleryBitmap();    
};


#endif
