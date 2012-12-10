#ifndef REGION_H
#define REGION_H
#include <string>
#include "BattleResults.h"
#include "RiskExceptions.h"
class Player;
class Board;

class Region{
friend class Board;		//klasa Board zajmuje siê ca³ym zarz¹dzaniem regionami, klasa Region dla wygody
private:
	unsigned int _id;
	std::string _name;
	Player *_controller;
	unsigned int _armies;
	
	Region(unsigned int id, std::string name);
	
	BattleResults attack(Region &target);
	void addArmies(const unsigned int num);
	void removeArmies(const unsigned int num);
	
	void setController(Player &p);
	
	std::string name();
	Player & controller();
	unsigned int armyCount();
	
};


#endif
