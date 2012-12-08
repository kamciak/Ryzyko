#include "Region.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define ROLL_D6 rand()%6+1

Region::Region(unsigned int id, std::string name): _name(name), _id(id){
}

void Region::setController(Player &player){
    _controller = &player;
}

void Region::addArmies(int num){
    _armies = (_armies + num < 0) ? 0 : _armies + num;
}


void Region::addNeighbor(Region &nbor){
    _neighbors.push_back(&nbor);
    nbor._neighbors.push_back(this);
}

void Region::attack(Region &target){
    srand(time(0));
   
    if(armyCount()<2)   //nie mo¿na atakowaæ mniej ni¿ dwoma armiami - dawa³oby to zero koœci ataku
        return;
    
    unsigned int atk_dice = (armyCount() > 4) ? 3 : armyCount() - 1;        //n-1 kosci ataku, limit 3
    unsigned int def_dice = (target.armyCount() > 2) ? 2 : target.armyCount();  //n kosci ataku, limit 2

    std::vector<unsigned int> atk_rolls;
    std::vector<unsigned int> def_rolls;

    for(unsigned int i = 0; i < atk_dice; ++i){
        atk_rolls.push_back(ROLL_D6);           //losowanie wynikow na kosci szesciosciennej
    }

    for(unsigned int i = 0; i< def_dice; ++i){
        def_rolls.push_back(ROLL_D6);
    }

    std::sort(atk_rolls.rbegin(),atk_rolls.rend());         //sortowanie od najwiekszego rzutu do najmniejszego
    std::sort(def_rolls.rbegin(),def_rolls.rend());         // rbegin i rend odwracaja domyslna kolejnosc

    unsigned int fights = (atk_dice > def_dice) ? def_dice : atk_dice;      //ilosc walk = min. ilosc kosci

    for(unsigned int i = 0; i < fights; ++i){
        if(atk_rolls[i] > def_rolls[i]) //wylonienie zwyciescow
            target.addArmies(-1);
        else                //obronca wygrywa  w wypadku remisu na kosci
            addArmies(-1);
    }

    if(target.armyCount() == 0)
        target.setController(*_controller);      //przejecie regionu po zabiciu wszystkich armii
}
