#ifndef REGION_H
#define REGION_H
#include <vector>
#include <iostream>
class Player;

///Klasa przechowuj�ca wszystkie informacje o regionie na planszy gry
class Region{
friend class Board;               //Klasa planszy ma mie� dost�p do sk�adnik�w prywatnych - ona obs�u�y dodawanie s�siad�w itp.
private:
    //Identyfikator regionu
    unsigned int _id;
    //Nazwa w�asna regionu
    std::string _name;

    //Lista region�w s�siednich
    std::vector<Region*> _neighbors;

    //Gracz kontroluj�cy region
    Player *_controller; 

    //Ilo�� armii gracza w regionie
    unsigned int _armies;   

    //Dodaje podany region do listy s�siad�w
    void addNeighbor(Region &nbor);

public:

    ///Kontruktor, ustawia nazw� regionu i jego identyfikator
    Region(unsigned int id,std::string name);

    ///Przekazuje graczowi kontrol� nad regionem
    void setController(Player &player);

    ///Przeprowadza walk� mi�dzy tym regionem i wskazanym
    void attack(Region &target);

    ///Dodaje (lub usuwa) podan� liczb� armii z tego regionu
    void addArmies(int num);

    ///Zwraca ilo�� armii w regionie
    unsigned int armyCount(){return _armies;}

    ///Zwraca identyfikator regionu
    unsigned int id(){return _id;}
};





#endif
