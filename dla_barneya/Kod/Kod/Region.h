#ifndef REGION_H
#define REGION_H

#include <string>
#include <wx/wx.h>
#include <vector>

#include "RiskExceptions.h"

#ifndef NO_OWNER
    #define NO_OWNER 50
#endif

///Klasa z informacjami o regionie
class Region{
private:
	unsigned int _id;
	std::string _name;
    unsigned int _owner;
	unsigned int _armies;
    wxPoint _coords;
    std::vector<unsigned int> _neighbors;
public:    	
    ///Konstruktor, przyjmuje nazwe regionu i wspolrzêdne punktu centralnego regionu dla mapy 1366x768
	Region(unsigned int id, std::string region_name, wxPoint coords);
    ///Zwraca ilosc armii w regionie
    unsigned int armyCount();
    ///Dodaje podana liczbe armii do regionu
    void addArmies(unsigned int num);
    ///Usuwa podana liczbe armii z regionu
    void removeArmies(unsigned int num);
    ///Dodaje region o podanym id do listy sasiadow, jesli jeszcze go tam nie ma
    void addNeighbor(unsigned int id);
    ///Zwraca wartosc logiczna czy region o podanym id jest sasiadem tego regionu
    bool isNeighbor(unsigned int id);
    ///Zwraca wspolrzedne punktu centralnego regionu dla mapy 1366x768
    wxPoint center();    
    ///Zwraca nazwe regionu
    std::string name();
    ///Zwraca id regionu
    unsigned int id();
    ///Zwraca id gracza kontrolujacego region
    unsigned int owner();
    ///Ustawia gracza o podanym id jako kontrolujacego ten region
    void setOwner(unsigned int id);
	
};

#endif
