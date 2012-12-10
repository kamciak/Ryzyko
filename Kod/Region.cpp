#include "Region.h"
#include <vector>
#include <algorithm>
#include <ctime>

#define ROLL_D6 (rand() % 6 + 1)

Region::Region(unsigned int id, std::string name) : _id(id), _name(name){}
	
BattleResults Region::attack(Region &target){
	srand(time(0));

	unsigned int atk_dice = armyCount() > 4 ? 3 : armyCount() - 1;
	unsigned int def_dice = target.armyCount() > 1 ? 2 : 1;
	
	std::vector<unsigned int> atk_rolls;
	std::vector<unsigned int> def_rolls;
	
	for(int i = 0; i < atk_dice; ++i){
		atk_rolls.push_back(ROLL_D6);
	}
	
	for(int i = 0; i < def_dice; ++i){
		def_rolls.push_back(ROLL_D6);
	}
	
	std::sort(atk_rolls.rbegin(),atk_rolls.rend());
	std::sort(def_rolls.rbegin(),def_rolls.rend());
	
	unsigned int comparisons = atk_dice > def_dice ? def_dice : atk_dice;
	
	int atk_losses=0;
	int def_losses=0;
	
	for(int i = 0; i < comparisons; ++i){
		if(atk_rolls[i] > def_rolls[i])
			++def_losses;
		else
			++atk_losses;
	}
	
	return BattleResults(*this, target, atk_rolls, def_rolls, atk_losses, def_losses);
	
}

void Region::addArmies(const unsigned int num){
	_armies += num;
}
void Region::removeArmies(const unsigned int num){
	_armies -= num;
}
	
std::string Region::name(){
	return _name;
}

Player & Region::controller(){
	return *_controller;
}	

unsigned int Region::armyCount(){
	return _armies;
}
		
void Region::setController(Player &p){
	_controller = &p;
}


	