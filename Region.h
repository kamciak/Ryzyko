#ifndef REGION_H
#define REGION_H
#include <vector>
#include <iostream>
class Player;

///Klasa przechowuj¹ca wszystkie informacje o regionie na planszy gry
class Region{
friend class Board;               //Klasa planszy ma mieæ dostêp do sk³adników prywatnych - ona obs³u¿y dodawanie s¹siadów itp.
private:
    //Identyfikator regionu
    unsigned int _id;
    //Nazwa w³asna regionu
    std::string _name;

    //Lista regionów s¹siednich
    std::vector<Region*> _neighbors;

    //Gracz kontroluj¹cy region
    Player *_controller; 

    //Iloœæ armii gracza w regionie
    unsigned int _armies;   

    //Dodaje podany region do listy s¹siadów
    void addNeighbor(Region &nbor);

public:

    ///Kontruktor, ustawia nazwê regionu i jego identyfikator
    Region(unsigned int id,std::string name);

    ///Przekazuje graczowi kontrolê nad regionem
    void setController(Player &player);

    ///Przeprowadza walkê miêdzy tym regionem i wskazanym
    void attack(Region &target);

    ///Dodaje (lub usuwa) podan¹ liczbê armii z tego regionu
    void addArmies(int num);

    ///Zwraca iloœæ armii w regionie
    unsigned int armyCount(){return _armies;}

    ///Zwraca identyfikator regionu
    unsigned int id(){return _id;}
};





#endif
