#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <wx/wx.h>

#include "Region.h"

///Klasa-singleton przechowuj¹ca dane o planszy
class Board{
private:
    ///Kontener z danymi o regionach
	std::vector<Region> _board;
    ///Konstruktor, dane o regionach wprowadzone w kodzie
	Board();
    ///Deklaracja konstruktora kopiujacego - uniemozliwia skopiowanie obiektu
	Board(const Board &b);
    ///Deklaracja operatora przypisania, j.w.
	Board & operator=(const Board & b);    
    ///Sprawia, ze dwa podane regiony staja sie swoimi sasiadami, jesli jescze nimi nie sa
    void addConnection(std::string reg1, std::string reg2);
    
public:
    ///Zwraca referencje do jedynego obiektu klasy Board
	static Board & instance();    
    ///Zwraca referencje do regionu o podanej nazwie
	Region & region(std::string);
    ///Zwraca referencje do regionu o podanym id
	Region & region(unsigned int id);
    ///Zwraca ilosc regionow na planszy
    unsigned int numberOfRegions();
};

#endif
