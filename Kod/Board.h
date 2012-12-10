#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>
#include "Region.h"

///Klasa-singleton przechowuj¹ca dane o planszy
class Board{
private:
	std::vector<Region> _board;
    Region *_selected;
	Board();
	Board(const Board &b);
	Board & operator=(const Board & b);
	Region & region(std::string);
	Region & region(unsigned int id);
public:
	static Board & instance();
	void combat(unsigned int attacker, unsigned int defender);
};

#endif
